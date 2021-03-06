/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:07:24 by jbyeon            #+#    #+#             */
/*   Updated: 2021/08/27 14:18:09 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void ft_send_char(int pid, char ch)
{
    int     i;

    i = 128;
    while (i > 0)
    {
        if (ch & i)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
        i /= 2;
    }
}

int main(int argc, char **argv)
{
    pid_t       pid;
    int         i;

    if (argc == 3)
    {
        i = 0;
        pid = ft_atoi(argv[1]);
        if (!pid)
        {
            ft_putstr_fd("Error : invalid PID\n", 1);
            return (0);
        }
        while (argv[2][i])
        {
            ft_send_char(pid, argv[2][i]);
            i++;
        }
        ft_send_char(pid, '\n');        
    }
    else
        ft_putstr_fd("wrong argument\n",2);
    return (0);
}
