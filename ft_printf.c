/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:36:16 by esafar            #+#    #+#             */
/*   Updated: 2022/01/21 14:07:49 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

void    ft_putnbr(int nb)
{
    long long int n;

    n = nb;
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    else if (n >= 0 && n < 10)
        ft_putchar(n + '0');
    else
    {
        ft_putnbr(n/10);
        ft_putnbr(n%10);
    }
}

int ft_intlen(int nb)
{
    int count = 0;

    if (nb == 0)
        return (1);
    if (nb < 0)
    {
        count++;
        nb = -nb;
    }
    while (nb > 0)
    {
        nb /= 10;
        count++;
    }
    return (count);
}

int print_int(va_list ap)
{
    int nb = va_arg(ap, int);
    int size = ft_intlen(nb);

    ft_putnbr(nb);
    return (size);
}

int count_hexa(unsigned long int nb)
{
    int count = 0;

    if (nb == 0)
        return 1;
    if (nb < 0)
        return (8);
    while (nb > 0)
    {
        nb /= 16;
        count++;
    }
    return (count);
}

int print_hexa(unsigned int nb, char *base)
{
    if (nb > 15)
        print_hexa(nb/16, base);
    ft_putchar(base[nb%16]);
    return (count_hexa(nb));
}

int ft_putstr(char *str)
{
    int i = 0;

    while (str[i])
        ft_putchar(str[i++]);
    return (i);
}

int print_str(va_list ap)
{
    int count = 0;
    char *str = va_arg(ap, char *);

    count = ft_putstr(str);
    return (count);
}

int sort_spec(char c, va_list ap)
{
    int count = 0;

    if (c == 'd')
        count += print_int(ap);
    if (c == 's')
        count += print_str(ap);
    if (c == 'x')
        count += print_hexa(va_arg(ap, unsigned int), "0123456789abcdef");
}

int ft_printf(char *str, ...)
{
    va_list ap;
    int count = 0;
    int i = 0;

    va_start(ap, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            count += sort_spec(str[i], ap);
        }
        else
            count += ft_putchar(str[i]);
        i++;
    }
    va_end(ap);
    return (0);
}
