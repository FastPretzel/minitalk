/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:17:29 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/06 18:17:33 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sighandler(int signo)
{
	if (signo == SIGUSR1)
		write(1, "SUCCESS\n", 8);
	if (signo == SIGUSR2)
		return ;
}

static void	ft_sig_char(char ch, pid_t spid)
{
	static int	counter;

	counter = 128;
	while (counter)
	{
		if (ch & counter)
		{
			if (kill(spid, SIGUSR1))
				exit(1);
		}
		else
			if (kill(spid, SIGUSR2))
				exit(1);
		counter >>= 1;
		pause();
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int					i;
	pid_t				spid;
	struct sigaction	act;

	if (argc != 3)
		exit(0);
	i = 0;
	spid = (pid_t)ft_atoi(argv[1]);
	act.sa_handler = ft_sighandler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (argv[2][i])
	{
		ft_sig_char(argv[2][i], spid);
		i++;
	}
	i = 8;
	while (i--)
	{
		if (kill(spid, SIGUSR2))
			exit(1);
		pause();
		usleep(50);
	}
	return (0);
}
