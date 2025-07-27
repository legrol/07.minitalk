/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:24:50 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/06/09 03:59:12 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// =======================================================
// Libraries
// =======================================================

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

// =======================================================
// To fix the visibility of the sigaction structure
// =======================================================
# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 200809L
# endif

// =======================================================
// Access to my libraries
// =======================================================
# include "libft.h"
# include "ft_printf.h"
# include "colors.h"

// =======================================================
// Define messages
// =======================================================
# define MSG_ARG_1 "Arguments missing"
# define MSG_ARG_2 "Too many Arguments"
# define MSG_PID_1 "Could not generate the PID"
# define MSG_PID_2 "Invalid PID"
# define MSG_WAR_1 "Delivery failed"
# define MSG_WAR_2 "Delivery success"
# define MSG_INF_1 "Info message 1"
# define MSG_SUC_1 "Success message 1"

// =======================================================
// Functions
// =======================================================

#endif