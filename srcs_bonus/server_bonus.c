/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:17:41 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/06 18:17:49 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_counter = 128;

static pid_t	check_pid(pid_t si_pid, pid_t pid, char *out_char)
{
	if (si_pid != pid)
	{	
		out_char = 0;
		g_counter = 128;
		return (si_pid);
	}
	return (pid);
}

static void	ft_sighandler(int signo, siginfo_t *info, void *context)
{
	static char		out_char;
	static pid_t	pid = 0;

	(void)context;
	pid = check_pid(info->si_pid, pid, &out_char);
	if (g_counter == 128)
		out_char = 0;
	if (signo == SIGUSR1)
		out_char += g_counter;
	g_counter >>= 1;
	if (!(g_counter))
	{
		g_counter = 128;
		if (out_char == 0)
		{
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		write(1, &(out_char), 1);
	}
	usleep(50);
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{	
	pid_t				spid;
	struct sigaction	sig;

	spid = getpid();
	ft_printf("%d\n", (int)spid);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_sighandler;
	if (sigaction(SIGUSR1, &sig, NULL) || sigaction(SIGUSR2, &sig, NULL))
	{
		ft_printf("ERROR SIGNAL\n");
		exit(2);
	}
	while (1)
		;
	return (0);
}
