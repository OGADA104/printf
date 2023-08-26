#include "main.h"
#include <stdio.h>
#include <stdarg.h> /* for va_list and va_start */

/**
 * print_binary - Print an unsigned integer in binary format.
 * @n: The unsigned integer to print.
 * @count: A pointer to the count variable to update.
 */
void print_binary(unsigned int n, int *count)
{
    if (n > 1)
        print_binary(n / 2, count);

    putchar('0' + n % 2);
    (*count)++;
}
void print_unsigned(unsigned int n, int *count, int base)
{
    if (n >= (unsigned int)base)
        print_unsigned(n / base, count, base);

    putchar("0123456789ABCDEF"[n % base]);
    (*count)++;
}

/**
 * print_pointer - Print the hexadecimal representation of a pointer.
 * @ptr: The pointer to print.
 * @count: A pointer to the count variable to update.
 */
void print_pointer(void *ptr, int *count)
{
    putchar('0');
    putchar('x');
    print_unsigned((unsigned long)ptr, count, 16);
}


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
		case 'b':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    print_binary(num, &count);
                    break;
                }
		 case 'X':
		{
			unsigned int num = va_arg(args, unsigned int);
			print_unsigned(num, &count, 16);
			break;
		}
		 case 'u':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    print_unsigned(num, &count, 10);
                    break;
                }
                case 'o':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%o", num);
		    print_unsigned(num, &count, 8);
                    break;
                }
                case 'x':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    print_unsigned(num, &count, 16);
                    break;
                }
		case 'p':
                {
                    void *ptr = va_arg(args, void *);
                    print_pointer(ptr, &count);
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

