/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:09:14 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/06/09 22:12:59 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

static void	sig_handler(int sign)
{
	static unsigned char	mychr;
	static int				mybit;

	mychr <<= 1;
	if (sign == SIGUSR1)
		mychr |= 1;
	mybit++;
	if (mybit == 8)
	{
		if ((int)mychr <= 126)
			ft_printf(GREEN "%c", mychr);
		else if ((int)mychr >= 127)
			ft_printf("%c", mychr);
		mybit = 0;
		mychr = '\0';
	}
}

static void	ft_getpid(void)
{
	pid_t	pid;

	pid = getpid();
	if (!pid)
		ft_printf(BDRED MSG_PID_1 "\n");
	ft_printf(RED"  __  __ _       _ _        _  _    \n");
	ft_printf(RED" |  \\/  (_)     (_) |      | || |   \n");
	ft_printf(YELLOW" | \\  / |_ _ __  _| |_ __ _| || | __\n");
	ft_printf(YELLOW" | |\\/| | | '_ \\| | __/ _` | || |/ /\n");
	ft_printf(YELLOW" | |  | | | | | | | | |(_| | || | < \n");
	ft_printf(RED" |_|  |_|_|_| |_|_|\\__\\__,_|_||_|\\_\\\n\n");
	ft_printf(RED"Welcome to "BDYELLOW"Minitalk "RED"project by rdel-olm\n");
	ft_printf(GREEN EQLIN EQLIN" Server is up and running. "EQLIN EQLIN"\n\n");
	ft_printf(CYAN"The PID is : " BDWHITE "%d\n\n", pid);
	ft_printf(GREEN"Server waiting to receive signals." BDWHITE "\n\n\n", pid);

}

static void	ft_trigger(void)
{
	struct sigaction	mysigact;

	sigemptyset(&mysigact.sa_mask);
	mysigact.sa_handler = sig_handler;
	mysigact.sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigaction(SIGUSR1, &mysigact, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &mysigact, NULL) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	ft_getpid();
	ft_trigger();
	while (1)
		sleep (300);
	return (0);
}
