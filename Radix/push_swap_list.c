/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:04:40 by luhumber          #+#    #+#             */
/*   Updated: 2023/02/20 11:41:56 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (lst && *lst)
	{
		ptr = *lst;
		while (ptr->nxt)
			ptr = ptr->nxt;
		ptr->nxt = new;
	}
	else if (lst)
		*lst = new;
}

void	ft_delone(t_stack *stack_a)
{
	if (!stack_a)
		return ;
	free(stack_a);
}

void	ft_clear(t_stack **stack_a)
{
	t_stack	*temp;

	if (!stack_a || !(*stack_a))
		return ;
	while (stack_a && *stack_a)
	{
		temp = (*stack_a)->nxt;
		ft_delone(*stack_a);
		*stack_a = temp;
	}
}

void	ft_add_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->nxt = *stack;
	*stack = new;
}
