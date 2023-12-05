#include "shell.h"

/**
 * exec_cmd - execution command
 * @command: arg
 *
 * Return: void
 */
void exe_cmd(char *command)
{
	pid_t pid;
	int status;

	command[_strlen(command) - 1] = '\0';

	pid = fork();
	if (pid == 0)
	{
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("_printf");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("printf");
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}
}
