#include "main.h"
#include<stdarg.h>
#include<string.h>
#include<unistd.h>

/**
 * _printf - Custom printf function implementation.
 * @format: The format string.
 * @...: Additional arguments depending on format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int char_print = 0;
	va_list args_list;
	char c;
	char *str;
	int str_len = 0;
	int num, num_len;
	char num_str[13];

	if (format == NULL)
		return (-1);
	va_start(args_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				char_print++;
			}
			else if (*format == 'c')
			{
				c = va_arg(args_list, int);
					write(1, &c, 1);
				char_print++;
			}
			else if (*format == 's')
			{
				str = va_arg(args_list, char *);
				if (str == NULL)
					str = "(NULL)";
				str_len = strlen(str);
				write(1, str, str_len);
				char_print += str_len;
			}
			else if (*format == 'd' || *format == 'i')
			{
				num = va_arg(args_list, int);
				num_len = snprintf(num_str, sizeof(num_str), "%d", num);
				write(1, num_str, num_len);
				char_print += num_len;
			}
			else
			{
				write(1, "ERROR: Unsupported format specifier", strlen("ERROR: Unsupported format specifier"));
				char_print += strlen("ERROR: Unsupported format specifier");
			}
		}
		format++;
	}
	va_end(args_list);
	return (char_print);
}
