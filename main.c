#include "shell.h"

/**
 * main - main func
 *
 * Return: 0
 */
int main(void)
{
	char *command;

	while (1)
	{
		prompt();
		command = read_line();

		if (command == NULL)
		{
			break;
		}

		if (command[0] == '\n')
		{
			free(command);
			continue;
		}
		exe_cmd (command);
		free (command);
	}
	return (EXIT_SUCCESS);
}
