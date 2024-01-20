/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:59:35 by luhumber          #+#    #+#             */
/*   Updated: 2023/02/06 22:36:42 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	int	temp;

	temp = (*stack_a)->val;
	(*stack_a)->val = (*stack_a)->nxt->val;
	(*stack_a)->nxt->val = temp;
	ft_printf("sa\n");
}

void	ft_sb(t_stack **stack_b)
{
	int	temp;

	temp = (*stack_b)->val;
	(*stack_b)->val = (*stack_b)->nxt->val;
	(*stack_b)->nxt->val = temp;
	ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	int	temp;

	temp = (*stack_a)->val;
	(*stack_a)->val = (*stack_a)->nxt->val;
	(*stack_a)->nxt->val = temp;
	temp = (*stack_b)->val;
	(*stack_b)->val = (*stack_b)->nxt->val;
	(*stack_b)->nxt->val = temp;
	ft_printf("ss\n");
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_b;

	if (!stack_b)
		return ;
	first_b = (*stack_b)->nxt;
	(*stack_b)->nxt = *stack_a;
	*stack_a = *stack_b;
	*stack_b = first_b;
	ft_printf("pa\n");
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;

	if (!stack_a)
		return ;
	first_a = (*stack_a)->nxt;
	(*stack_a)->nxt = *stack_b;
	*stack_b = *stack_a;
	*stack_a = first_a;
	ft_printf("pb\n");
}
