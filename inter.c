/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:04:25 by esafar            #+#    #+#             */
/*   Updated: 2022/01/21 14:08:10 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    int used[255];
    int i, j;

    if (ac == 3)
    {
        i = 0;
        while (i < 255)
            used[i++] = 0;
        i = 2;
        while (i > 0)
        {
            j = 0;
            while (av[i][j])
            {
                if (i == 2 && !used[(unsigned char)av[i][j]])
                    used[(unsigned char)av[i][j]] = 1;
                else if (i == 1 && used[(unsigned char)av[i][j]] == 1)
                {
                    write(1, &av[i][j], 1);
                    used[(unsigned char)av[i][j]] = 2;
                }
                j++;
            }
            i--;
        }
    }
    write(1, "\n", 1);
    return 0;
}
