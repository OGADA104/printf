#include "main.h"
#include<stdarg.h>
#include<string.h>
#include<unistd.h>
/**
 *
 *
 *
 *
 *
 */
int _printf(const char *format, ...)
{
	int char_print = 0;
	va_list args_list;
	char c;
	char *str;
	int str_len = 0;

	if (format == NULL)
		return (-1);
	va_start(args_list, format);
	while(*format)
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
				str_len = strlen(str);
				write(1, str, str_len);
				char_print += str_len;
			}
		}
		format++;
	}
	va_end(args_list);
	return (char_print);
}
