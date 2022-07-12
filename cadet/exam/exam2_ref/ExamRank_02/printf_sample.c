//Assignment name  : ft_printf
//Expected files   : ft_printf.c
//Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
//--------------------------------------------------------------------------------

//Write a function named `ft_printf` that will mimic the real printf but 
//it will manage only the following conversions: s,d and x.

//Your function must be declared as follows:

//int ft_printf(const char *, ... );

//Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
//To test your program compare your results with the true printf.

//Exemples of the function output:

//call: ft_printf("%s\n", "toto");
//out: toto$

//call: ft_printf("Magic %s is %d", "number", 42);
//out: Magic number is 42%

//call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
//out: Hexadecimal for 42 is 2a$


#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c) {
    return write(1, &c, 1);
}

int ft_putstr(char *s) {
    int ret = 0;
    if (s == NULL)
        s = "(null)";
    while (*s)
        ret += ft_putchar(*s++);
    return ret;
}

#define HEX "0123456789abcdef"
int ft_putnbr(long long n, int base) {
    int ret = 0;
    if (n < 0) {
        ret += write(1, "-", 1);
        n *= -1;
    }
    if (n >= base)
        ret += ft_putnbr(n/base, base);
    ret += ft_putchar(HEX[n%base]);
    return ret;
}

int print(char *f, va_list ap) {
    int ret = 0;
    char c;

    while (*f){
        c = *f++;
        if (c != '%')
            ret += ft_putchar(c);
        else {
            c = *f++;
            if (c == 'c')
                ret += ft_putchar((char)va_arg(ap, int));
            else if (c == 's')
                ret += ft_putstr(va_arg(ap, char*));
            else if (c == 'd')
                ret += ft_putnbr((long long)va_arg(ap, int), 10);
            else if (c == 'x')
                ret += ft_putnbr((long long)va_arg(ap, unsigned long), 16);
        }
    }
    return ret;
}

int ft_printf(char *f, ...) {
    va_list ap;
    int ret = 0;
    
    va_start(ap, f);
    ret += print(f, ap);
    va_end(ap);
    return ret;
}

#include <limits.h>
#include <stdio.h>
int main()
{
    int f, s;
    f = ft_printf("%s %c %d %d %x %s\n", "hello", 'X', INT_MAX, INT_MIN, UINT_MAX, NULL);
    s =    printf("%s %c %d %d %x %s\n", "hello", 'X', INT_MAX, INT_MIN, UINT_MAX, NULL);
    printf("%d | %d\n", f, s);
}
