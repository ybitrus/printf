#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - custom implementation of printf
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0, precision = -1;

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '.')
			{
				i++;
				precision = 0;
				while (format[i] >= '0' && format[i] <= '9')
				{
					precision = precision * 10 + (format[i] - '0');
					i++;
				}
				i--;
			}
			switch (format[i])
			{
				case 'd':
				case 'i':
					count += printf("%.*d", precision, va_arg(args, int));
					break;
				case 'u':
					count += printf("%.*u", precision, va_arg(args, unsigned int));
					break;
				case 'o':
					count += printf("%.*o", precision, va_arg(args, unsigned int));
					break;
				case 'x':
					count += printf("%.*x", precision, va_arg(args, unsigned int));
					break;
				case 'X':
					count += printf("%.*X", precision, va_arg(args, unsigned int));
					break;
				case 'c':
					count += printf("%c", va_arg(args, int));
					break;
				case 's':
					count += printf("%.*s", precision, va_arg(args, char *));
					break;
				case '%':
					count += putchar('%');
					break;
				default:
					count += putchar('%');
					count += putchar(format[i]);
					break;
			}
			precision = -1;
		}
		else
		{
			count += putchar(format[i]);
		}
	}
	va_end(args);
	return (count);
}
