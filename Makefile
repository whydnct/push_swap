# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:31:05 by aperez-m          #+#    #+#              #
#    Updated: 2023/04/11 19:05:43 by aperez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g3

AR = ar
ARFLAGS = rcs

SRC_PATH = src
SRC = \
	read_params.c \
	normalize_params.c \
	errors.c \
	radix.c \
	simpler_sort.c \
	moves_push_swap.c \
	moves_rotate.c \
	free.c 

#INCLUDE = $(SRC_PATH)/push_swap.h

OBJ_PATH = obj
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

# produces obj/moves_push.o obj/moves_reverse_rotate.o ...

LIB_PATH = lib
LIB_H = $(LIB_PATH)/libft.h
LIB_A = $(LIB_PATH)/libft.a
NEW_LIB_A = $(LIB_PATH)/lib$(NAME).a

# RULES

# target: prerequisites
#	commandgg
#	command

# if there's a file with the same name of the target
# commands won't run. This is why .PHONY exists

# $@ = target
# $^ = prerequisite

all: $(NAME)

re: fclean all

clean:
	@rm -rf $(OBJ_PATH)

fclean:	clean
	@rm -rf $(NAME)

$(OBJ_PATH):
	@mkdir -p $@

$(LIB_PATH):
	@mkdir -p $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH) $(LIB_PATH)
	@$(CC) $(CFLAGS) -c $^ -o $@

$(NEW_LIB_A): $(OBJ)
	@make -C ./libft
	@mv libft/libft.a $@
	@$(AR) $(ARFLAGS) $@ $^

$(NAME): $(NEW_LIB_A) $(OBJ)
	@$(CC) $(CFLAGS) $(SRC_PATH)/main.c -L$(LIB_PATH) -l$(NAME) -o $(NAME)

.PHONY: clean fclean re

#valgrind --leak-check=yes --log-file=valgrind.rpt ./a.out