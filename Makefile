# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:31:05 by aperez-m          #+#    #+#              #
#    Updated: 2023/01/21 20:13:28 by aperez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

NAME = push_swap.a
BIN_PATH = bin

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

AR = ar
ARFLAGS = rcs

SRC_PATH = src
SRC =	\
		moves_push.c\
#		moves_reverse_rotate.c\
#		moves_rotate.c\
#		moves_swap.c

INCLUDE = $(SRC_PATH)/push_swap.h

OBJ_PATH = obj
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

# produces obj/moves_push.o obj/moves_reverse_rotate.o ...

LIB_PATH = lib
LIB_H = $(LIB_PATH)/libft.h
LIB_A = $(LIB_PATH)/libft.a

# RULES

# target: prerequisites
#	command
#	command

# if there's a file with the same name of the target
# commands won't run. This is why .PHONY exists

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@
# $@ = target
# $^ = prerequisite


all: $(NAME)

re: fclean all

clean:
	rm -rf $(OBJ_PATH)

fclean:	clean
	rm -rf $(BIN_PATH)
	rm -rf *.dSYM

$(NAME): $(OBJ) | $(BIN_PATH)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	mkdir -p $@
# -p no error if existing, make parent dirs as needed

$(BIN_PATH):
	mkdir -p $@

no_flag: | $(BIN_PATH)
	$(CC) $(addprefix $(SRC_PATH)/, $(SRC)) $(INCLUDE) $(LIB_H) $(LIB_A)
	mv a.out $(BIN_PATH)

debug: | $(BIN_PATH)
	$(CC) -g3 $(addprefix $(SRC_PATH)/, $(SRC)) $(INCLUDE) $(LIB_H) $(LIB_A)
#mv -v a.out* $(BIN_PATH)

fsanitize:
	$(CC) -fsanitize=address -g3 $(addprefix $(SRC_PATH)/, $(SRC)) $(INCLUDE) $(LIB_H) $(LIB_A)

leaks: | $(BIN_PATH)
	$(CC) -D LEAKS=1 -g3 $(addprefix $(SRC_PATH)/, $(SRC)) $(INCLUDE) $(LIB_H) $(LIB_A)
	mv -v *.out $(BIN_PATH)

.PHONY: clean fclean leaks re