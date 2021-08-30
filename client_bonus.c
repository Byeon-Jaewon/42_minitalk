/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:07:24 by jbyeon            #+#    #+#             */
/*   Updated: 2021/08/28 16:22:43 by jbyeon           ###   ########.fr       */
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

void ft_send_str(int pid, char *str, int pid_flag)
{
    int     i;

    i = 0;
    while (str[i])
    {
        ft_send_char(pid, str[i]);
        i++;
    }
    if (pid_flag == 1)
    {
        ft_send_char(pid, 0);
        ft_send_char(pid, ':');
    }
    else
        ft_send_char(pid, '\n');        
}

void ft_ack(int sig)
{
    (void)sig;
    ft_putstr_fd("success\n", 1);
}

int main(int argc, char **argv)
{
    pid_t       pid;
    char        *client_pid;

    signal(SIGUSR1, ft_ack);
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        if (!pid)
        {
            ft_putstr_fd("Error : invalid PID\n", 1);
            return (0);
        }
        client_pid = ft_itoa(getpid());
        ft_send_str(pid, client_pid, 1);
        ft_send_str(pid, argv[2], 0);
        ft_send_char(pid, 0);
    }
    else
        ft_putstr_fd("wrong argument\n",2);
    free(client_pid);
    return (0);
}
