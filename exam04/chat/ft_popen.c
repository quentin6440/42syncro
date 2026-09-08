#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

typedef struct s_popen
{
    int   fd;   // fd à utiliser par le parent
    pid_t pid;  // pid de l'enfant à wait
} t_popen;

t_popen ft_popen(char *file, char *const argv[], char type)
{
    t_popen p;
    int     pipefd[2];

    p.fd = -1;
    p.pid = -1;

    if (!file || !argv || (type != 'r' && type != 'w'))
        return p;
    if (pipe(pipefd) == -1)
        return p;

    p.pid = fork();
    if (p.pid == -1)
    {
        close(pipefd[0]);
        close(pipefd[1]);
        p.pid = -1;
        return p;
    }

    if (p.pid == 0) // enfant
    {
        if (type == 'r')
        {
            // enfant écrit -> parent lit
            if (dup2(pipefd[1], STDOUT_FILENO) == -1)
                _exit(127);
        }
        else
        {
            // parent écrit -> enfant lit
            if (dup2(pipefd[0], STDIN_FILENO) == -1)
                _exit(127);
        }
        close(pipefd[0]);
        close(pipefd[1]);
        execvp(file, argv);
        _exit(127); // exec a échoué
    }

    // parent
    if (type == 'r')
    {
        close(pipefd[1]);
        p.fd = pipefd[0];
    }
    else
    {
        close(pipefd[0]);
        p.fd = pipefd[1];
    }
    return p;
}

int ft_pclose(t_popen p)
{
    int status = -1;

    if (p.fd != -1)
        close(p.fd);
    if (p.pid > 0)
    {
        if (waitpid(p.pid, &status, 0) == -1)
            return -1;
    }
    return status; // comme pclose: status brut waitpid
}

/* demo
int main(void)
{
    char *const cmd[] = {"cat", NULL};
    t_popen p = ft_popen("cat", cmd, 'w');
    if (p.fd == -1)
        return 1;

    write(p.fd, "HI\n", 3);
    int st = ft_pclose(p);
    printf("status=%d\n", st);
    return 0;
}
*/
