# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 16:20:28 by cdarrell          #+#    #+#              #
#    Updated: 2021/11/01 20:03:54 by cdarrell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	push_swap
NAME_C		=	checker

HEADER		=	include/ps_push_swap.h
HEADER_C	=	include/psc_checker.h
LIBFT_DIR	=	libft
LIBFT_LIB	=	libft.a

CC			=	gcc -g
FLAGS		=	-Wall -Wextra -Werror

DIR_SRC		=	ps_push_swap
SRC			=	ps_push_swap.c \
				ps_commands.c \
				ps_operations.c \
				ps_parsing_stack.c \
				ps_parsing_array.c \
				ps_sort_six.c \
				ps_sort_all_first.c \
				ps_sort_all_a.c \
				ps_sort_all_b.c \
				ps_optimization.c \
				ps_units.c

DIR_SRC_C	=	psc_checker
SRC_C		=	psc_checker.c \
				psc_parsing.c \
				psc_commands.c \
				psc_operations.c


OBJ_DIR		=	obj_push_swap
OBJ_DIR_C	=	obj_checker

OBJ 		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJ_C 		=	$(addprefix $(OBJ_DIR_C)/,$(SRC_C:.c=.o))

RM_DIR		=	rm -rf
RM_FILE		=	rm -f

INCLUDES	= 	-I .

all:	$(NAME)

bonus:	$(NAME_C)

${NAME}:	${OBJ}
			@make -C ${LIBFT_DIR}/ all
			@$(CC) -o $(NAME) $(OBJ) $(FLAGS) ${LIBFT_DIR}/${LIBFT_LIB}
			@echo "\tCompiling...\t" [ $(NAME) ] $(SUCCESS)

$(OBJ)		:	| $(OBJ_DIR)

$(OBJ_DIR)	:
			@mkdir -p $(OBJ_DIR)
			
$(OBJ_DIR)/%.o :	${DIR_SRC}/%.c $(HEADER) Makefile
					@${CC} $(FLAGS) $(INCLUDES) -o $@ -c $<

${NAME_C}:	${OBJ_C}
			@make -C ${LIBFT_DIR}/ all
			@$(CC) -o $(NAME_C) $(OBJ_C) $(FLAGS) ${LIBFT_DIR}/${LIBFT_LIB}
			@echo "\tCompiling...\t" [ $(NAME_C) ] $(SUCCESS)

$(OBJ_C)	:	| $(OBJ_DIR_C)

$(OBJ_DIR_C):
			@mkdir -p $(OBJ_DIR_C)
			
$(OBJ_DIR_C)/%.o :	${DIR_SRC_C}/%.c $(HEADER_C) Makefile
					@${CC} $(FLAGS) $(INCLUDES) -o $@ -c $<

#COLORS
C_NO		=	"\033[00m"
C_OK		=	"\033[32m"
C_GOOD		=	"\033[32m"

#DEBUG
SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)
			
clean:
		@make -C ${LIBFT_DIR}/ clean
		@${RM_DIR} ${OBJ_DIR} ${OBJ_DIR_C}
		@echo "\tCleaning...\t" [ $(NAME) ] $(OK)
		@echo "\tCleaning...\t" [ $(NAME_C) ] $(OK)
				
fclean:	clean
		@${RM_FILE} ${LIBFT_DIR}/$(LIBFT_LIB) > /dev/null
		@echo "\tDeleting...\t" [ $(LIBFT_LIB) ] $(OK)
		@${RM_FILE} $(NAME) $(NAME_C)
		@echo "\tDeleting...\t" [ $(NAME) ] $(OK)
		@echo "\tDeleting...\t" [ $(NAME_C) ] $(OK)
				
re:		fclean all

.PHONY: all bonus clean fclean re
