#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct s_popen
{
	int   fd;
	pid_t pid;
} t_popen;

/* type: 'r' parent lit stdout cmd, 'w' parent écrit stdin cmd */
t_popen ft_popen(char *file, char *const argv[], char type)
{
	t_popen p;
	int fds[2];

	p.fd = -1;
	p.pid = -1;
	if (!file || !argv || (type != 'r' && type != 'w'))
		return p;
	if (pipe(fds) == -1)
		return p;
	p.pid = fork();
	if (p.pid == -1)
	{
		close(fds[0]); close(fds[1]);
		p.pid = -1;
		return p;
	}
	if (p.pid == 0)
	{
		if (type == 'r')
		{
			if (dup2(fds[1], STDOUT_FILENO) == -1) _exit(127);
		}
		else
		{
			if (dup2(fds[0], STDIN_FILENO) == -1) _exit(127);
		}
		close(fds[0]);
		close(fds[1]);
		execvp(file, argv);
		_exit(127);
	}
	if (type == 'r')
	{
		close(fds[1]);
		p.fd = fds[0];
	}
	else
	{
		close(fds[0]);
		p.fd = fds[1];
	}
	return p;
}

int ft_pclose(t_popen p)
{
	int status = -1;

	if (p.fd != -1)
		close(p.fd);
	if (p.pid > 0 && waitpid(p.pid, &status, 0) == -1)
		return -1;
	return status;
}
