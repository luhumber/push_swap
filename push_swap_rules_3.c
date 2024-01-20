/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:31:18 by luhumber          #+#    #+#             */
/*   Updated: 2023/02/06 23:51:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **stack_a, int i)
{
	t_stack	*tmp;
	t_stack	*previous;
	t_stack	*stack;

	stack = *stack_a;
	if (!stack)
		return ;
	tmp = stack;
	while (tmp->nxt)
	{
		previous = tmp;
		tmp = tmp->nxt;
	}
	tmp->nxt = stack;
	previous->nxt = NULL;
	*stack_a = tmp;
	if (i == 1)
		ft_printf("rra\n");
}

void	ft_rrb(t_stack **stack_b, int i)
{
	t_stack	*tmp;
	t_stack	*previous;
	t_stack	*stack;

	stack = *stack_b;
	if (!stack)
		return ;
	tmp = stack;
	while (tmp->nxt)
	{
		previous = tmp;
		tmp = tmp->nxt;
	}
	tmp->nxt = stack;
	previous->nxt = NULL;
	*stack_b = tmp;
	if (i == 1)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	ft_printf("rrr\n");
}
