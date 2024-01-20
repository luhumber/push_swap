# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:26:15 by luhumber          #+#    #+#              #
#    Updated: 2023/03/02 11:23:29 by luhumber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

SRCS = 	push_swap.c \
		push_swap_list.c \
		push_swap_rules_1.c \
		push_swap_rules_2.c \
		push_swap_rules_3.c \
		short_sort.c \
		long_sort.c \
		parsing.c \
		parsing_utils.c \
		push_swap_utils.c 

OBJS = $(SRCS:.c=.o)
HEADERS = 	push_swap.h

all: 
	$(MAKE) -C ./libft/
	${MAKE} $(NAME)

$(NAME): $(OBJS) $(HEADERS) ./libft/
	cc $(OBJS) ./libft/libft.a -o $(NAME)

%.o: %.c  $(HEADERS) Makefile 
		cc $(CFLAGS) -c $< -o $@ -I.

clean:
	$(MAKE) clean -C ./libft/
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C libft/
	rm -f $(NAME)

re: fclean
	${MAKE} all

.PHONY: clean fclean re libft
