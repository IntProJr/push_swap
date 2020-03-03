# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 18:42:42 by lrosalee          #+#    #+#              #
#    Updated: 2020/03/03 16:23:34 by lrosalee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

PRINTF_C = flag.c flag_manager_f.c float_to_string.c length.c precision.c print_cs.c print_di.c ft_printf.c print_flag.c \
print_number.c print_o.c print_padding.c print_ptr.c print_u.c print_x.c round_ld.c width.c

GNL_C = get_next_line.c  \

HEAD = ./headers

LIBFT_C = ft_abs.s ft_atoi.c ft_atoi_base.c ft_bzero.c ft_clear_mass.c ft_fact.c

DIR_O = temporary

CFILES = $(LIBFT_C) $(PRINTF_C) $(GNL_C)

PATH_C = $(addprefix ./src/libft/,$(LIBFT_C)) $(addprefix ./src/ft_printf/,$(PRINTF_C)) $(addprefix ./src/get_next_line/,$(GNL_C))

OFILES = $(CFILES:.c=.o)

PATH_O = $(addprefix $(DIR_O)/,$(OFILES))

all: $(NAME)

$(NAME): $(PATH_O)
	@ar rc $(NAME) $(PATH_O)
	@ranlib $(NAME)

$(DIR_O)/%.o: ./src/libft/%.c
	@mkdir -p $(DIR_O)
	@echo "COMPILING $< = $@"
	$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@;

$(DIR_O)/%.o: ./src/printf_f/%.c
	@mkdir -p $(DIR_O)
	@echo "COMPILING $< = $@"
	$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@;

$(DIR_O)/%.o: ./src/get_next_line/%.c
	@mkdir -p $(DIR_O)
	@echo "COMPILING $< = $@"
	@$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@;

clean:
	@rm -f temporary/*.o
	@rm -rf temporary

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
