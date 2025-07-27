/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:09:23 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/06/11 22:25:46 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

static void	char_to_bin(const int pid, char c)
{
	int				mybit;

	mybit = 7;
	while (mybit >= 0)
	{
		if (((c >> mybit) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		mybit--;
		usleep(100);
	}
}

static void	treat_pid(int pid)
{
	if (pid <= 0)
	{
		ft_printf(YELLOW MSG_PID_2 "\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	if (argc <= 2)
	{
		ft_printf(YELLOW MSG_ARG_1 "\n");
		return (1);
	}
	if (argc >= 4)
	{
		ft_printf(YELLOW MSG_ARG_2 "\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	treat_pid(pid);
	if (argc == 3)
	{
		i = 0;
		while (argv[2][i])
			char_to_bin (pid, argv[2][i++]);
		char_to_bin (pid, '\n');
	}
	return (0);
}
