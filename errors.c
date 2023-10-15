#include "shell.h"

/**
 * _eputs - let prints an input string
 * @str: the string that will be printed
 *
 * Return: Success Nothing
 */

void _eputs(char *str)

{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_eputchar(str[k]);
		k++;
	}
}

/**
 * _eputchar -it now  writes the character c to stderr
 * @c: it character to print
 *
 * Return: on success 1.
 * On error, -1 is being returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - let write the character c to given fd
 * @c: character to print
 * @fd: filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is being returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - it prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: success the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
