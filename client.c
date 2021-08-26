/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:07:24 by jbyeon            #+#    #+#             */
/*   Updated: 2021/08/26 18:14:13 by jbyeon           ###   ########.fr       */
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
        while (argv[2][i])
        {
            ft_send_char(pid, argv[2][i]);
            i++;
        }
        ft_send_char(pid, '\n');
        
    }
    return (0);
}
