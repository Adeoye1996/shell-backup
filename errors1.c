#include "shell.h"


/**
 * _erratoi - An integer is to be converted to a string
 * @s: strings to be converted
 * Return: Success 0 if there is no numbers in string,
 * the converted number otherwise
 * -1 on error
 */

int _erratoi(char *s)

{
	int k = 0;

	unsigned long int result = 0;

	if (*s == '+')

		s++;  /* TODO: why does this value make main return 255? */

	for (k = 0;  s[k] != '\0'; k++)

	{
		if (s[k] >= '0' && s[k] <= '9')

		{
			result *= 10;
			result += (s[k] - '0');

			if (result > INT_MAX)

				return (-1);
		}

		else
			return (-1);
	}

	return (result);

}

/**
 * print_error - an error message to be printed
 * @info: parameter & return info struct
 * @estr: the string containing specified error type
 * Return: success 0 if no numbers in string, converted number otherwise
 * -1 on error
 */
void print_error(info_t *info, char *estr)

{
	_eputs(info->fname);

	_eputs(": ");

	print_d(info->line_count, STDERR_FILENO);

	_eputs(": ");

	_eputs(info->argv[0]);

	_eputs(": ");

	_eputs(estr);

}

/**
 * print_d - the functions to  print a decimal (integer) number (base 10)
 * @input: the input
 * @fd: filedescriptor to write to
 * Return: success number of characters printed
 */

int print_d(int input, int fd)

{
	int (*__putchar)(char) = _putchar;

	int i, count = 0;

	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)

		__putchar = _eputchar;

	if (input < 0)

	{
		_abs_ = -input;

		__putchar('-');

		count++;
	}

	else
		_abs_ = input;

	current = _abs_;

	for (i = 1000000000; i > 1; i /= 10)

	{
		if (_abs_ / i)

		{
			__putchar('0' + current / i);

			count++;
		}
		current %= i;
	}
__putchar('0' + current);
count++;
return (count);
}
/**
 * convert_number - the converter functions, to a clone of itoa
 * @num: the number
 * @base: to base
 * @flags: the argument flags
 * Return: success string
 */

char *convert_number(long int num, int base, int flags)

{
	static char *array;

	static char buffer[50];

	char sign = 0;

	char *ptr;

	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)

	{
		n = -num;

		sign = '-';
	}

array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";

	ptr = &buffer[49];

	*ptr = '\0';

	do        {

		*--ptr = array[n % base];

		n /= base;

	} while (n != 0);

	if (sign)

		*--ptr = sign;

	return (ptr);

}

/**
 * remove_comments - the function replaces first instance of '#' with '\0'
 * @buf: the address of the string to modify
 * Return: success Always 0;
 */

void remove_comments(char *buf)

{
	int k;

	for (k = 0; buf[k] != '\0'; k++)

		if (buf[k] == '#' && (!k || buf[k - 1] == ' '))

		{
			buf[k] = '\0';

			break;
		}
}
