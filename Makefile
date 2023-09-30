# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 14:32:06 by adhaka            #+#    #+#              #
#    Updated: 2023/07/02 20:56:20 by adhaka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

CC				= cc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

SRCS			= operations.c \
					push_swap.c \
					sort.c \
					utils.c \

OBJS			= $(SRCS:.c=.o)

LIBFT_DIR =		./libft
LIBFT =			$(LIBFT_DIR)/libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) -C $(LIBFT_DIR)
				$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS):		push_swap.h

$(LIBFT):
				make -C $(LIBFT_DIR)

clean:
				make clean -C $(LIBFT_DIR)
				$(RM) $(OBJS)

fclean:			clean
				make fclean -C $(LIBFT_DIR)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft

