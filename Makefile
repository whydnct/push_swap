# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:31:05 by aperez-m          #+#    #+#              #
#    Updated: 2023/01/22 12:39:55 by aperez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

NAME = push_swap.a
BIN_PATH = bin

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

AR = ar
ARFLAGS = rcs

SRC_PATH = src/
SRC =	\
		moves_push.c\
#		moves_reverse_rotate.c\
#		moves_rotate.c\
#		moves_swap.c

INCLUDE = $(SRC_PATH)push_swap.h

OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

# produces obj/moves_push.o obj/moves_reverse_rotate.o ...

LIB_PATH = lib/
LIB_H = $(LIB_PATH)libft.h
LIB_A = $(LIB_PATH)libft.a

# RULES

# target: prerequisites
#	command
#	command

# if there's a file with the same name of the target
# commands won't run. This is why .PHONY exists

# $@ = target
# $^ = prerequisite


all: $(NAME)

re: fclean all

clean:
	rm -rf $(OBJ_PATH)

fclean:	clean
	rm -rf $(BIN_PATH)
	rm -rf *.dSYM

$(OBJ_PATH):
	mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJ) $(LIB_A)
	$(AR) $(ARFLAGS) $@ $^
	@echo $(NAME)

# -p no error if existing, make parent dirs as needed

$(BIN_PATH):
	mkdir -p $@

main: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) $(INCLUDE) -o test

.PHONY: clean fclean leaks re main $(NAME)
