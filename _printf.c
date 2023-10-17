#include "main.h"
#include <stdarg.h>


void print_buffer(char buffer[], int *index);

/**
 *  _printf - Printf function.
 * @format: format.
 * Return: Printed chars.
*/

int handle_print(const char *fmt, int *i, va_list list,
char buffer[], int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[index++] = format[i];
			if (index == BUFF_SIZE)
				print_buffer(buffer, &index);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars+ = printed;
		}
	}

	print_buffer(buffer, &index);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the string from buffer
 * @buffer: Array of chars
 * @index: Index of the buffer
*/
void print_buffer(char buffer[], int *index)
{
	if (*index > 0)
		write(1, &buffer[0], *index);

	*index = 0;
}
