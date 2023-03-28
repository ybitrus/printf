#include <stdarg.h>
#include <stdio.h>

/**
 * _print_int - print an integer with given precision
 * @args: va_list containing the integer to print
 * @precision: precision to use when printing
 *
 * Return: number of characters printed
 */
int _print_int(va_list args, int precision)
{
	return (printf("%.*d", precision, va_arg(args, int)));
}

/**
 * _print_unsigned_int - print an unsigned integer with given precision
 * @args: va_list containing the unsigned integer to print
 * @precision: precision to use when printing
 *
 * Return: number of characters printed
 */
int _print_unsigned_int(va_list args, int precision)
{
	return (printf("%.*u", precision, va_arg(args, unsigned int)));
}

/**
 * _print_octal - print an unsigned integer as an octal with given precision
 * @args: va_list containing the unsigned integer to print
 * @precision: precision to use when printing
 *
 * Return: number of characters printed
 */
int _print_octal(va_list args, int precision)
{
	return (printf("%.*o", precision, va_arg(args, unsigned int)));
}

/**
 * _print_hex - print an unsigned integer as a hexadecimal with given precision
 * @args: va_list containing the unsigned integer to print
 * @precision: precision to use when printing
 * @uppercase: whether to print uppercase letters
 *
 * Return: number of characters printed
 */
int _print_hex(va_list args, int precision, int uppercase)
{
	if (uppercase)
		return (printf("%.*X", precision, va_arg(args, unsigned int)));
	else
		return (printf("%.*x", precision, va_arg(args, unsigned int)));
}

/**
 * _print_char - print a character
 * @args: va_list containing the character to print
 *
 * Return: number of characters printed
 */
int _print_char(va_list args)
{
	return (putchar(va_arg(args, int)));
}

/**
 * _print_string - print a string with given precision
 * @args: va_list containing the string to print
 * @precision: precision to use when printing
 *
 * Return: number of characters printed
 */
int _print_string(va_list args, int precision)
{
	return (printf("%.*s", precision, va_arg(args, char *)));
}

/**
 * _print_percent - print a percent sign
 *
 * Return: number of characters printed
 */
int _print_percent(void)
{
	return (putchar('%'));
}

/**
 * _print_unknown - print an unknown format specifier
 *
 * Return: number of characters printed
 */
int _print_unknown(char c)
{
	putchar('%');
	return (putchar(c));
}
