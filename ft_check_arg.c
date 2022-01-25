/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:27:07 by tdelauna          #+#    #+#             */
/*   Updated: 2022/01/25 10:18:14 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arg_nb(int argc)
{
	if (argc <= 2)
		return (1);
	return (0);
}

int	ft_arg_digit(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == '-' && argv[i][j + 1])
				j++;
			if (!ft_isdigit(argv[i][j]))
			{
				write(1, "Error", 5);
				return (1);
			}
		}
	}
	return (0);
}

int	ft_arg_doublon(char **argv)
{
	int	i;
	int	j;
	int	nb_arg;
	int	doublon;

	i = 0;
	while (argv[++i])
	{
		doublon = 0;
		j = 0;
		nb_arg = ft_atoi(argv[i]);
		while (argv[++j])
		{
			if (nb_arg == ft_atoi(argv[j]))
			{
				doublon++;
				if (doublon > 1)
				{
					write(1, "Error", 5);
					return (1);
				}
			}
		}
	}
	return (0);
}

int	ft_arg_limit(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_strlen(argv[i]) > 2
			&& (ft_atoi(argv[i]) == -1 || ft_atoi(argv[i]) == 0))
		{
			write(1, "Error", 5);
			return (1);
		}
	}
	return (0);
}

int	ft_arg_error(int argc, char **argv)
{
	if (ft_arg_nb(argc) || ft_arg_digit(argv)
		|| ft_arg_doublon(argv) || ft_arg_limit(argv))
		return (0);
	return (1);
}
