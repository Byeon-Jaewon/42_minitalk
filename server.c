/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:44:05 by jbyeon            #+#    #+#             */
/*   Updated: 2021/08/26 15:18:48 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void ft_sighandler(int sig)
{
    static char     word;
    static int      cnt;

    word <<= 1;
    if (sig == 10)
        word += 1;
    cnt++;
    if (cnt == 8)
    {
        ft_putchar_fd(word, 1);
        word = 0;
        cnt = 0;
    }
    usleep(1);
}

int main(void)
{
    ft_putstr_fd("server's pid :", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n', 1);
    signal(SIGUSR1, (void *)ft_sighandler);
    signal(SIGUSR2, (void *)ft_sighandler);
    while (1)
    {
        pause();
    }
    return (0);
}
