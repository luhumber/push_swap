/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:22:28 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/01 16:14:16 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack {
	int					val;
	int					index;
	struct s_stack		*nxt;
}	t_stack;

typedef struct s_tab {
	int	*tab;
	int	prev_nb;
	int	min_nb;
}	t_tab;

t_stack		*ft_new(int val);
void		ft_add_back(t_stack **lst, t_stack *new);
void		ft_parsing(t_stack **stack_a, int argc, char **argv);
void		ft_error(void);
void		ft_delone(t_stack *stack_a);
void		ft_clear(t_stack **stack_a);
void		ft_sa(t_stack **stack_a);
void		ft_pa(t_stack **stack_a, t_stack **stack_b);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
void		ft_ra(t_stack **stack_a);
void		ft_rra(t_stack **stack_a, int i);
void		ft_add_front(t_stack **stack, t_stack *new);
int			ft_a_is_sort(t_stack **stack_a);
int			ft_check_size(t_stack *stack_a);
void		ft_sort_small_stack(t_stack *stack_a);
void		ft_sort_big_stack(t_stack *stack_a);
int			ft_get_distance(t_stack **stack_a, int index);
void		ft_short_swap(t_stack **stack_a, t_stack **stack_b);
void		ft_long_swap(t_stack **stack_a, t_stack **stack_b);
int			ft_get_max_bits(t_stack **stack_a);
void		ft_free_exit(t_stack **stack_a, t_stack **stack_b);
long long	ft_new_atoi(const char *str);
void		ft_loop_check_args(char **args);
void		ft_to_free(char **args);
int			ft_free_double_tab(char **strs);
void		ft_sort3(t_stack **stack_a, t_stack *temp, int min, int next_min);
void		ft_tab_cpy(char **argc, char **args);

#endif