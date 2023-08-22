#include <stdio.h>
#include <stdarg.h> /* for va_list and va_start */
/**
 * _printf - Custom printf function implementation.
 * @format: The format string.
 * @...: Additional arguments depending on format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    int count = 0; /* Counter to keep track of characters printed */
    va_list args;  /* Variable argument list */

    va_start(args, format); /* Initialize variable argument list */

    while (*format)
    {
        if (*format != '%')
        {
            putchar(*format); /* Print non-format characters */
            count++;
        }
        else
        {
            format++; /* Move past the '%' character */
            switch (*format)
            {
                case 'c':
                {
                    int c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    if (str)
                    {
                        while (*str)
                        {
                            putchar(*str);
                            str++;
                            count++;
                        }
                    }
                    break;
		}
		case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    count += snprintf(NULL, 0, "%d", num);
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
            }
        }
        format++;
    }

    va_end(args); /* Clean up variable argument list */
    return count;
}

