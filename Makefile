# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 13:57:19 by jaehlee           #+#    #+#              #
#    Updated: 2025/07/23 13:57:19 by jaehlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	src/main.c \
		src/simple_sort.c \
		src/big_sort.c \
		operations/swap.c \
		operations/push.c \
		operations/rotate.c \
		operations/reverse.c \
		utils/utils.c \
		utils/stack.c \
		utils/check_arg.c \
		utils/check_arg2.c \
		utils/ft_atoill.c \
		utils/make_chunk.c \
		utils/make_chunk2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
