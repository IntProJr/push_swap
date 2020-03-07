# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 18:42:42 by lrosalee          #+#    #+#              #
#    Updated: 2020/03/07 11:42:04 by lrosalee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

PRINTF_C =  print_cs.c print_ptr.c float_to_string.c print_di.c \
        print_f.c print_number.c print_o.c print_u.c \
        print_x.c flag.c flag_manager_f.c length.c precision.c \
        print_flag.c print_padding.c round_ld.c width.c \
        ft_printf.c parse.c

GNL_C = get_next_line.c  \

HEAD = ./headers

LIBFT_C = ft_abs.c \
          ft_atoi.c \
          ft_atoi_base.c \
          ft_bzero.c \
          ft_chr_and_fill.c \
          ft_clear_mass.c \
          ft_fact.c \
          ft_hex_len.c \
          ft_isalnum.c \
          ft_isalpha.c \
          ft_isascii.c \
          ft_isdigit.c \
          ft_isprint.c \
          ft_isspace.c \
          ft_itoa.c \
          ft_len_base.c \
          ft_longlong_len.c \
          ft_lstadd.c \
          ft_lstdel.c \
          ft_lstdelone.c \
          ft_lstiter.c \
          ft_lstmap.c \
          ft_lstnew.c \
          ft_memalloc.c \
          ft_memccpy.c \
          ft_memchr.c \
          ft_memcmp.c \
          ft_memcpy.c \
          ft_memdel.c \
          ft_memmove.c \
          ft_memset.c \
          ft_min.c \
          ft_pow.c \
          ft_print_u_hex.c \
          ft_ptr_len_base.c \
          ft_put_longlong_base.c \
          ft_put_u_longlong_base.c \
          ft_putchar.c \
          ft_putchar_fd.c \
          ft_putendl.c \
          ft_putendl_fd.c \
          ft_putnbr.c \
          ft_putnbr_fd.c \
          ft_putnchar.c \
          ft_putnstr.c \
          ft_putstr.c \
          ft_putstr_fd.c \
          ft_realloc.c \
          ft_sqrt.c \
          ft_str_multi_chr.c \
          ft_strcat.c \
          ft_strchr.c \
          ft_strclr.c \
          ft_strcmp.c \
          ft_strcpy.c \
          ft_strdel.c \
          ft_strdup.c \
          ft_strequ.c \
          ft_striter.c \
          ft_striteri.c \
          ft_strjoin.c \
          ft_strlcat.c \
          ft_strlen.c \
          ft_strmap.c \
          ft_strmapi.c \
          ft_strncat.c \
          ft_strncmp.c \
          ft_strncpy.c \
          ft_strndup.c \
          ft_strnequ.c \
          ft_strnew.c \
          ft_strnstr.c \
          ft_strrchr.c \
          ft_strsplit.c \
          ft_strstr.c \
          ft_strsub.c \
          ft_strtrim.c \
          ft_tolower.c \
          ft_toupper.c \
          ft_u_len_base.c \
          ft_u_longlong_len.c \
          ft_wordcount.c \
          ft_digstr_cpy.c \
          ft_swap.c \


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

$(DIR_O)/%.o: ./src/ft_printf/%.c
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
