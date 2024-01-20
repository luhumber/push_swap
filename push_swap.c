/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:22:16 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/01 16:12:13 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_exit(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_b)
		ft_clear(stack_b);
	ft_clear(stack_a);
	exit(0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_indexing(t_stack *stack)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		i;

	i = 0;
	tmp_a = stack;
	tmp_b = tmp_a->nxt;
	while (tmp_a)
	{
		if (tmp_a->val > tmp_b->val)
			i++;
		tmp_b = tmp_b->nxt;
		if (!tmp_b)
		{
			tmp_a->index = i;
			tmp_a = tmp_a->nxt;
			tmp_b = stack;
			i = 0;
		}
	}
}

int	ft_a_is_sort(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = (*stack_a);
	while (tmp->nxt != NULL)
	{
		if (tmp->val < tmp->nxt->val)
			tmp = tmp->nxt;
		else
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(0);
	ft_parsing(&stack_a, argc, argv);
	if (ft_a_is_sort(&stack_a) == 0)
		ft_free_exit(&stack_a, &stack_b);
	ft_indexing(stack_a);
	if (ft_check_size(stack_a) > 5)
		ft_long_swap(&stack_a, &stack_b);
	else
		ft_short_swap(&stack_a, &stack_b);
	ft_free_exit(&stack_a, &stack_b);
	return (0);
}
