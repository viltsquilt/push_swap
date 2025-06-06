# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 10:57:31 by vahdekiv          #+#    #+#              #
#    Updated: 2025/06/06 13:30:32 by vahdekiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I libft/
SRCS = push_swap.c ps_command_call.c  push_swap_utils.c ps_operations.c \
		ps_main.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
		@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
		@rm -f *.o
		@make clean -C $(LIBFT_DIR)

fclean: clean
		@rm -f $(NAME) $(LIBFT)

re: fclean all

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -g

.PHONY: all clean fclean re

