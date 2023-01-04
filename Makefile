# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 13:20:07 by aestraic          #+#    #+#              #
#    Updated: 2023/01/04 14:53:31 by aestraic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(OBJ)

SRC =  client.c server.c

OBJ = $(SRC:.c=) 

HEADER_PATH = header
LIB_PATH = lib
SRC_PATH = src
C_FLAGS = -Wall -Wextra -Werror
LIB = $(LIB_PATH)/libft.a

all:  $(LIB) $(NAME)
	
%: %.c
	gcc $(C_FLAGS) -I$(HEADER_PATH) -L$(LIB_PATH) -lft $^ -o $@
	
$(LIB):
	@mkdir -p $(LIB_PATH)
	@make all -C	$(SRC_PATH)/libft
	@make all -C	$(SRC_PATH)/ft_printf
	@make all -C	$(SRC_PATH)/gnl

clean:
	@rm -f client server
	@echo Objectfiles removed

fclean: clean
	@make fclean -C $(SRC_PATH)/libft
	@make fclean -C $(SRC_PATH)/ft_printf
	@echo Libraries and exeutables removed
	
re: fclean all
	@echo REDONE

.PHONY: clean fclean re obj exec library