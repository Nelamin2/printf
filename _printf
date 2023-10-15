#include "main.h"

void print_buffer(char buffer[], int *index);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, index = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[index++] = format[i];
			if (index== BUFF_SIZE)
				print_buffer(buffer, &index);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &index;
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &index);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the string from buffer
 * @buffer: Array of chars
 * @index: Index of the buffer.
 */
void print_buffer(char buffer[], int *index)
{
	if (*index> 0)
		write(1, &buffer[0], *index);

	*index = 0;
}

