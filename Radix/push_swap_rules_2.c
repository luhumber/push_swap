/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:44:10 by luhumber          #+#    #+#             */
/*   Updated: 2023/02/06 15:31:45 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **stack_a)
{
	t_stack	*first_a;
	t_stack	*tmp;

	if (!stack_a)
		return ;
	first_a = *stack_a;
	*stack_a = first_a->nxt;
	tmp = *stack_a;
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;
	first_a->nxt = NULL;
	tmp->nxt = first_a;
	ft_printf("ra\n");
}

void	ft_rb(t_stack **stack_b)
{
	t_stack	*first_b;
	t_stack	*tmp;

	if (!stack_b)
		return ;
	first_b = *stack_b;
	tmp = *stack_b;
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;
	tmp->nxt = first_b;
	ft_printf("rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*tmp_a;
	t_stack	*first_b;
	t_stack	*tmp_b;

	if (!stack_a)
		return ;
	if (!stack_b)
		return ;
	first_a = *stack_a;
	*stack_a = first_a->nxt;
	tmp_a = *stack_a;
	while (tmp_a->nxt != NULL)
		tmp_a = tmp_a->nxt;
	tmp_a->nxt = first_a;
	first_b = *stack_b;
	tmp_b = *stack_b;
	while (tmp_b->nxt != NULL)
		tmp_b = tmp_b->nxt;
	tmp_b->nxt = first_b;
	ft_printf("rr\n");
}
