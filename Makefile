# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 15:48:56 by lrosalee          #+#    #+#              #
#    Updated: 2020/03/11 16:13:05 by lrosalee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap

NAME2	= checker

CFLAGS 	= -Wall -Wextra -Werror

PUSH_SWAP_MAIN = main_pw.c

CHECKER_MAIN = main_checker.c

SRC1 	= 		change_a_stack.c \
          		change_b_stack.c \
          		change_both_stacks.c \
          		change_stack_fun.c \
          		copy_argv_to_stack.c \
          		count_moves.c \
          		unit_moves.c \
          		create_stack.c \
          		delete_stack.c \
          		do_moves.c \
          		error.c \
          		find_min_max.c \
          		push_swap.c \
          		quick_sort.c \
          		set_to_zero_stack.c \
          		small_sort.c \
          		validation.c \
          		kick_values.c \
          		sorting_check.c \
          		search_values.c \
          		help_for_parser.c \

SRC2 	=       commands_list_functions.c \
                validate_comands.c \
                change_stacks_no_output.c \

OBJSFD 	= temporary

OBJS1 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))

OBJS2 	= $(addprefix $(OBJSFD)/,$(SRC2:.c=.o))

HDR 		= -I./includes

LIBFT_HDR 	= -I./includes/libft/includes

LIB_BINARY	= -L./includes/libft -lft

LIBFT		= ./includes/libft/libft.a

all: $(LIBFT) $(NAME1) $(NAME2)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c ./includes/push_swap.h | $(OBJSFD)
	gcc $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(LIBFT):
	make -C ./includes/libft

$(NAME1): $(OBJS1) $(LIBFT)
	gcc $(PUSH_SWAP_MAIN) $(OBJS1) $(LIB_BINARY) -o $@

$(NAME2): $(OBJS2) $(LIBFT)
	gcc $(CHECKER_MAIN) $(OBJS1) $(OBJS2) $(LIB_BINARY) -o $@

clean:
	/bin/rm -f $(OBJS)
	rm -rf $(OBJSFD)
	make -C ./includes/libft clean

fclean: clean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)
	make -C ./includes/libft fclean

re: fclean all

.PHONY: all clean fclean re
