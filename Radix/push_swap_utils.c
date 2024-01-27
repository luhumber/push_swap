/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:15 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/13 11:13:09 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new(int val)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->val = val;
	ptr->nxt = NULL;
	return (ptr);
}

void	ft_to_free(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	ft_sort3(t_stack **stack_a, t_stack *temp, int min, int next_min)
{
	if (temp->index == min && temp->nxt->index != next_min)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a, 1);
	}
	else if (temp->index == next_min)
	{
		if (temp->nxt->index == min)
			ft_sa(stack_a);
		else
			ft_rra(stack_a, 1);
	}
	else
	{
		if (temp->nxt->index == min)
			ft_ra(stack_a);
		else
		{
			ft_sa(stack_a);
			ft_rra(stack_a, 1);
		}
	}
}
