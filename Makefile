# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 17:35:46 by josesanc          #+#    #+#              #
#    Updated: 2022/10/18 17:20:24 by josesanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  ft_main.c ft_stack.c ft_stack_extra.c ft_arg_checker.c ft_stack_utils1.c ft_stack_utils2.c ft_stack_utils3.c ft_stack_utils4.c ft_stack_utils5.c ft_stack_utils6.c ft_stack_utils7.c ft_split.c ft_split_utils.c ft_atoi.c
SRC_B = ft_checker_bonus.c ft_checker_utils_bonus.c ft_stack.c  ft_stack_utils1.c ft_stack_utils2.c ft_split.c ft_split_utils.c ft_atoi.c ft_arg_checker.c ft_strcmp_bonus.c get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c
OBJ = ${SRC:.c=.o}
OBJ_B = ${SRC_B:.c=.o}
NAME = push_swap
NAME_B = checker

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME}
	@echo "✅ Push Swap compiled successfully ✅"

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus: ${NAME_B}

${NAME_B}: ${OBJ_B}
	@${CC} ${CFLAGS} ${OBJ_B} -o ${NAME_B}
	@echo "✅ Checker compiled successfully ✅"

clean: 
	@${RM} ${OBJ} ${OBJ_B}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${NAME_B}


re: fclean all

.PHONY: fclean clean all bonus