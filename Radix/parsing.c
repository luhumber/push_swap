/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:36:26 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/01 16:09:23 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_new_atoi(const char *str)
{
	long long	res;
	long long	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{	
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((res * 10 + (*str - '0')) * sign >= 2147483648)
			return (2147483648);
		if ((res * 10 + (*str - '0')) * sign < -2147483648)
			return (2147483648);
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

int	ft_double(int num, char **argv, int i)
{
	i++;
	while (argv && argv[i])
	{
		if (ft_new_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	if (num[i] == '\0')
		return (1);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_tab_cpy(char **argv, char **args)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	while (argv[j])
	{
		k = 0;
		while (argv[j][k])
		{
			args[i][k] = argv[j][k];
			k++;
		}
		args[i][k] = '\0';
		j++;
		i++;
	}
}

void	ft_loop_check_args(char **args)
{
	int		i;
	long	tmp;

	i = 0;
	while (args && args[i])
	{
		tmp = ft_new_atoi(args[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			ft_free_double_tab(args);
		if (ft_new_atoi(args[i]) == 2147483648)
			ft_free_double_tab(args);
		if (ft_isnum(args[i]) == 1)
			ft_free_double_tab(args);
		if (ft_double(tmp, args, i) == 1)
			ft_free_double_tab(args);
		i++;
	}
}
