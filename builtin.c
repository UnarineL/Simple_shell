#include "shell.h"

/**
 * _printf - printf custom function
 * @format: string containing zero or more specifiers
 *
 *
 * Return: The number od chars printed or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *ptr;
	int count;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ++ptr)
	{
		if (*ptr != '%')
		{
			write(STDOUT_FILENO, ptr, 1);
			++count;
		}
		else
		{
			++ptr;
			if (*ptr == 's')
			{
				const char *str = va_arg(args, const char *);
				while (*str != '\0')
				{
					write (STDOUT_FILENO, str, 1);
					++count;
					++str;
				}
			}
			else if (*ptr == 'd')
			{
				int num = va_arg(args, int);
				char buffer[20];
				int length = 0;
				do {
					buffer[length++] = '0' + num % 10;
					num /= 10;
				} while (num != 0);

				while (--length >= 0)
				{
					write (STDOUT_FILENO, &buffer[length], 1);
					++count;
				}
			}
			else
			{
				write (STDOUT_FILENO, "%", 1);
				++count;
			}
		}
	}

	va_end(args);
	return count;
}

/**
 * _strlen - length of string
 * @s: the string to check
 *
 * Return: int of string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
	{
		return (0);
	}

	while (*s++)
	{
		i++;
	}
	return (i);
}
