/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:35:16 by lucas             #+#    #+#             */
/*   Updated: 2023/02/08 15:23:26 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max_bits(t_stack **stack_a)
{
	t_stack	*temp;
	int		max;
	int		max_bits;

	temp = *stack_a;
	max = temp->index;
	max_bits = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->nxt;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_long_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	temp_a = *stack_a;
	size = ft_check_size(temp_a);
	max_bits = ft_get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			temp_a = *stack_a;
			if (((temp_a->index >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		while (ft_check_size(*stack_b) != 0)
			ft_pa(stack_a, stack_b);
		i++;
	}
}

int	ft_check_size(t_stack *stack_a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack_a;
	while (tmp)
	{
		tmp = tmp->nxt;
		i++;
	}
	return (i);
}

int	ft_get_distance(t_stack **stack_a, int index)
{
	t_stack	*temp;
	int		distance;

	distance = 0;
	temp = (*stack_a);
	while (temp)
	{
		if (temp->index == index)
			break ;
		distance++;
		temp = temp->nxt;
	}
	return (distance);
}
