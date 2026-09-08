#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int ft_open(char *file, char *argv[], char type)
{

    if (!file || !argv)
        return -1;
    
    if (type != 'r' && type != 'w')
        return -1;

    int fd[2];

    if (pipe(fd) < 0)
        return -1;

    int pid = fork();

    if (pid < 0)
    {
        close(fd[1]);
        close(fd[0]);
        return -1;
    }

    if (pid == 0)
    {
        if (type == 'r')
            dup2(fd[1], STDOUT_FILENO);
        else
            dup2(fd[0], STDIN_FILENO);

        close(fd[0]);
        close(fd[1]);
        execvp(file, argv);
        exit(-1);
    }

    if (type == 'r')
    {
        close(fd[1]);
        return (fd[0]);
    }
    else
    {
        close(fd[0]);
        return fd[1];
    }


}

int main()
{
    char *cmd[] = {"cat", NULL};
    int fd = ft_open("cat", cmd, 'w');

    if (fd == -1)
        return -1;

    write(fd, "HI\n", 3);
    close(fd);
    wait(NULL);
    return 0;

}
