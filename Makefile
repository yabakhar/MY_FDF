# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 19:55:13 by yabakhar          #+#    #+#              #
#    Updated: 2019/08/01 17:52:27 by yabakhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -lmlx -framework OpenGl -framework AppKit -Wall -Werror -Wextra

SRCS = ft_read.c\
		draw.c\
		ft_move.c\
		fdf.c\
		ft_iso.c\
		ft_print.c\
		ft_change_color.c

HEADER = fdf.h
LIBFT = libft/libft.a

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) $(HEADER)
	@make -C libft
	@gcc -I $(HEADER) -c $(SRCS)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[32m$(NAME) created\n\033[0m"
clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"
re: fclean all
