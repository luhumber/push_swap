/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:19:39 by luhumber          #+#    #+#             */
/*   Updated: 2023/02/08 15:50:54 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min(t_stack **stack_a, int val)
{
	t_stack	*temp;
	int		min;

	temp = *stack_a;
	min = temp->index;
	while (temp->nxt)
	{
		temp = temp->nxt;
		if ((temp->index < min) && temp->index != val)
			min = temp->index;
	}
	return (min);
}

void	ft_three_numbers(t_stack **stack_a)
{
	t_stack	*temp;
	int		min;
	int		next_min;

	temp = *stack_a;
	min = ft_get_min(stack_a, -1);
	next_min = ft_get_min(stack_a, min);
	ft_sort3(stack_a, temp, min, next_min);
}

void	ft_four_numbers(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = ft_get_distance(stack_a, ft_get_min(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
		ft_rra(stack_a, 1);
	if (ft_a_is_sort(stack_a) == 0)
		return ;
	ft_pb(stack_a, stack_b);
	ft_three_numbers(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = ft_get_distance(stack_a, ft_get_min(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
	{
		ft_rra(stack_a, 1);
		ft_rra(stack_a, 1);
	}
	else if (distance == 4)
		ft_rra(stack_a, 1);
	if (ft_a_is_sort(stack_a) == 0)
		return ;
	ft_pb(stack_a, stack_b);
	ft_four_numbers(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_short_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_check_size(*stack_a);
	if (ft_a_is_sort(stack_a) == 0 || size == 0 || size == 1)
		return ;
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		ft_three_numbers(stack_a);
	else if (size == 4)
		ft_four_numbers(stack_a, stack_b);
	else if (size == 5)
		ft_five_numbers(stack_a, stack_b);
}
