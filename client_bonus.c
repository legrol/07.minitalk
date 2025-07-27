/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client _bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-13 09:43:20 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-06-13 09:43:20 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

int	bits_received;

static int	arg_control(const int argc)
{
	if (argc <= 2)
	{
		ft_printf(YELLOW MSG_ARG_1 "\n");
		exit (EXIT_FAILURE);
	}
	if (argc >= 4)
	{
		ft_printf(YELLOW MSG_ARG_2 "\n");
		exit (EXIT_FAILURE);
	}
	return (0);
}

static void	handler_pid(int pid)
{
	if (pid <= 0)
	{
		ft_printf(YELLOW MSG_PID_2 "\n");
		exit(EXIT_FAILURE);
	}
	if (pid == SIGUSR1)
	{
		usleep(150);
		bits_received++;
	}
}

static int	char_to_bin(const int pid, char c, int mybit)
{
	int				send;

	send = 0;
	ft_printf(BLUE" %c " ARROWRG "  " WHITE, c);
	while (mybit >= 0)
	{
		if (((c >> mybit) & 1) == 1)
		{
			ft_printf(CYAN"1");
			kill(pid, SIGUSR1);
			send++;
		}
		else
		{
			ft_printf(CYAN"0");
			kill(pid, SIGUSR2);
			send++;
		}
		mybit--;
		usleep(150);
	}
	ft_printf("\n");
	return (send);
}

static void	print_resp(int send)
{
	ft_printf(YELLOW "=========================================\n");
	ft_printf(GREEN "%d bits sent successfully.\n", send);
	if (bits_received > 0)
		ft_printf(WHITE "%d bits received successfully.\n", bits_received);
	else
		ft_printf(WHITE "message received successfully.\n");
	ft_printf(YELLOW "=========================================\n");
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;
	int	send;

	send = 0;
	bits_received = 0;
	arg_control (argc);
	pid = ft_atoi(argv[1]);
	handler_pid(pid);
	signal(SIGUSR1, handler_pid);
	if (argc == 3)
	{
		i = 0;
		while (argv[2][i])
			send += char_to_bin (pid, argv[2][i++], 7);
		char_to_bin (pid, '\n', 7);
	}
	print_resp(send);
	return (0);
}
