# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 13:20:07 by aestraic          #+#    #+#              #
#    Updated: 2022/06/08 17:30:14 by aestraic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(COMPILED)

SRC =  client.c server.c

COMPILED = $(SRC:.c=.out) 

all: $(NAME)

%.out : %.c
	cc -Wall -Wextra -Werror -I header -L bib -l ft $^ -o $@

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)
	
re: fclean $(NAME)

.PHONY: clean fclean re bonus