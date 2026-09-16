#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int	i = 0, fd[2], prev = -1;
	pid_t	pid;

	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd) == -1)
			return 1;
		pid = fork();
		if (pid == -1)
			return 1;
		if (pid == 0)
		{
			if (prev != -1)
			{
				dup2(prev, 0);
				close(prev);
			}
			if (cmds[i+1])
			{
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			_exit(1);
		}
		if (prev != -1)
			close(prev);
		if (cmds[i + 1])
		{
			close(fd[1]);
			prev = fd[0];
		}
		i++;
	}
	while (wait(NULL) > 0)
		;
	return 0;
}
