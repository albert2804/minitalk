# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 13:20:07 by aestraic          #+#    #+#              #
#    Updated: 2022/11/08 14:06:54 by aestraic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(COMPILED)

SRC =  client.c server.c

COMPILED = $(SRC:.c=) 

HEADER_PATH = header
LIB_PATH = lib
LIB_PATH2 = lib/libft.a
SRC_PATH = src
OBJ_PATH = obj
C_FLAGS = -Wall -Wextra -Werror

all:  library $(COMPILED)
	
%: %.c
	gcc $(C_FLAGS) -I$(HEADER_PATH) -L$(LIB_PATH) -lft $^ -o $@

library:
#	@echo MAKE LIBFT
	@make all -C	$(SRC_PATH)/libft
	
#	@echo MAKE PRINTF
	@make all -C	$(SRC_PATH)/ft_printf

#	@echo MAKE GNL	
	@make all -C	$(SRC_PATH)/gnl
	
val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(INPUT)

move:
	@make move -C	$(SRC_PATH)/libft
	@make move -C	$(SRC_PATH)/ft_printf
	@mv $(OBJ)$^ $(OBJ_PATH)
	@echo Moved Objectfiles into /$(OBJ_PATH)

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