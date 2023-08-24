#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (format && *format)
	{
		if (*format != '%') /* Normal character, just print it */
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++; /* Move past the '%' */

			if (*format == 'c') /* Character */
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 's') /* String */
			{
				char *str = va_arg(args, char *);

				if (str)
				{
					int len = 0;

					while (str[len])
					len++;
					write(1, str, len);
					count += len;
				}
				else /* Handle NULL pointer */
				{
					write(1, "(null)", 6);
					count += 6;
				}
			}
			else if (*format == 'd' || *format == 'i') /* Decimal/Integer */
			{
				int num = va_arg(args, int);
				int num_digits = 0;
				int temp = num;

				if (num == 0) /* Handle zero separately */
				{
					_putchar('0');
					count++;
				}
				else
				{
					if (num < 0)
					{
						_putchar('-');
						count++;
						num = -num;
						temp = -temp;
					}

					while (temp > 0)
					{
						temp /= 10;
						num_digits++;
					}

					while (num_digits > 0)
					{
						temp = num;
						int divisor = 1;
						int i = num_digits - 1;

						while (i > 0)
						{
							divisor *= 10;
							i--;
						}
						int digit = temp / divisor;

						_putchar('0' + digit);
						count++;
						num -= digit * divisor;
						num_digits--;
					}
				}
			}
			else if (*format == '%') /* Percentage sign */
			{
				write(1, "%", 1);
				count++;
			}
			else /* Unknown specifier, print the '%' */
			{
				write(1, "%", 1);
				count++;
				if (*format != '\0')
				{
					write(1, format, 1);
					count++;
				}
			}
		}

	format++;
	}

	va_end(args);
	return (count);
}
