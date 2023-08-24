#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* _printf.c */
int _printf(const char *format, ...);
void print_binary(unsigned int n, int *count);
void print_unsigned(unsigned int n, int *count, int base);
void print_pointer(void *ptr, int *count);

/*_putchar.c*/
int _putchar(char);

#endif /* MAIN_H */

