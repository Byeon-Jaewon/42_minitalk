/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:44:05 by jbyeon            #+#    #+#             */
/*   Updated: 2021/08/27 16:01:15 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void ft_sighandler(int sig)
{
    static char     word;
    static int      cnt;
    static int      client_pid = 0;
    static int      pid_flag = 0;

    word <<= 1;
    if (sig == 10)
        word += 1;
    cnt++;
    if (cnt == 8)
    {
        ft_putchar_fd(word, 1);
        if (word == 0 && pid_flag == 0)
        {
            kill(client_pid, SIGUSR1);
            pid_flag += 1;
//            printf("\npid flag : %d\npid_client:%d\n", pid_flag, client_pid);
        }
        if (word == 0 && pid_flag == 1)
        {
            pid_flag -= 1;
            client_pid = client_pid * 0;
  //          printf("\n message end :%d\nclient_pid : %d\n", pid_flag, client_pid);
        }
        if (pid_flag == 0 && word != 0)
            client_pid = (client_pid * 10) + (word - 48);
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
