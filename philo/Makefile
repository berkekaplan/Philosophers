# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 15:36:58 by mkaplan           #+#    #+#              #
#    Updated: 2023/10/30 19:06:28 by mkaplan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c other_utils.c check.c inits.c \
		dinner.c write_term.c view.c free.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread

all:
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	
datarace:
	@$(CC) $(DFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
