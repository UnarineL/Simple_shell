#include "shell.h"

/**
 * prompt - shelll prompt
 *
 * Return: void
 */
void prompt(void)
{
	_printf("#cisfun$ ");
}

char *read_line(void)
{
	char *line;
	size_t bufsize;
	ssize_t read_chars;

	line = NULL;
	bufsize = 0;

	read_chars = getline(&line, &bufsize, stdin);
	if (read_chars == -1)
	{
		free(line);
		return (NULL);
	}

	if (read_chars > 0 && line[read_chars - 1] == '\n')
	{
		line[read_chars - 1] = '\0';
	}
	return (line);
}
