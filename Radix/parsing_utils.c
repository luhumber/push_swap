/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:19:19 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/13 11:12:50 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_double_tab(char **strs)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (strs[i])
		free(strs[i++]);
	free(strs);
	exit(1);
}

char	**ft_big_tab(char **argv, int argc)
{
	char	**args;
	int		i;
	int		k;

	i = 1;
	k = 0;
	(void)argc;
	args = malloc(sizeof(char *) * (argc));
	if (!args)
		return (NULL);
	while (argv[i])
	{
		args[k] = malloc(sizeof(char *) * (ft_strlen(argv[i]) + 2));
		if (!args[k])
			ft_free_double_tab(args);
		i++;
		k++;
	}
	args[k] = NULL;
	ft_tab_cpy(argv, args);
	return (args);
}

char	**ft_little_tab(char **args, char **argv)
{
	int	i;

	i = 0;
	args = ft_split(argv[1], ' ');
	if (args == NULL)
		return (NULL);
	if (args[0] == NULL)
	{
		free(args);
		ft_error();
		exit(0);
	}
	if (ft_new_atoi(args[i]) == 2147483648)
		ft_free_double_tab(args);
	return (args);
}

char	**ft_check_args(int argc, char **argv)
{
	char	**args;

	args = NULL;
	if (argc == 2)
		args = ft_little_tab(args, argv);
	else
		args = ft_big_tab(argv, argc);
	if (args == NULL)
		return (NULL);
	ft_loop_check_args(args);
	return (args);
}

void	ft_parsing(t_stack **stack_a, int argc, char **argv)
{
	t_stack	*new;
	char	**args;
	int		i;

	i = 0;
	args = ft_check_args(argc, argv);
	if (args == NULL)
		exit (1);
	while (args[i])
	{
		new = ft_new(ft_new_atoi(args[i]));
		if (!new)
		{
			ft_to_free(args);
			write(2, "Error\n", 6);
			ft_clear(stack_a);
			exit (0);
		}
		ft_add_back(stack_a, new);
		i++;
	}
	ft_to_free(args);
}
