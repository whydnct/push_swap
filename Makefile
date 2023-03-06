# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:31:05 by aperez-m          #+#    #+#              #
#    Updated: 2023/03/06 12:28:00 by aperez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

NAME = push_swap
BIN_PATH = bin

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g1 -fsanitize=address

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
	free.c \
	debuggers.c

INCLUDE = $(SRC_PATH)/push_swap.h

OBJ_PATH = obj
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

# produces obj/moves_push.o obj/moves_reverse_rotate.o ...

LIB_PATH = lib
LIB_H = $(LIB_PATH)/libft.h
LIB_A = $(LIB_PATH)/libft.a
NEW_LIB_A = $(LIB_PATH)/libpush_swap.a

# RULES

# target: prerequisites
#	command
#	command

# if there's a file with the same name of the target
# commands won't run. This is why .PHONY exists

# $@ = target
# $^ = prerequisite
# TODO: está bien meter la .PHONY $(NEW_LIB_A) para que
# recompile siempre la librería? como no tiene .o para comparar
# con src creo que va a recompilarla siempre, y no sé si eso es correcto
# esto viene de intentar incorporar cambios en libft.


all: $(NAME)

re: fclean all

clean:
	@rm -rf $(OBJ_PATH)

fclean:	clean
	@rm -rf $(BIN_PATH)
	@rm -rf *.dSYM

$(OBJ_PATH):
	@mkdir -p $@

$(BIN_PATH):
	@mkdir -p $@

$(LIB_PATH):
	@mkdir -p $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH) $(LIB_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

$(NEW_LIB_A): $(OBJ)
	@make -C ./libft
	@cp libft/libft.a $(LIB_A)
	@cp $(LIB_A) $@
	@$(AR) $(ARFLAGS) $@ $^

$(NAME): $(NEW_LIB_A) $(OBJ) | $(BIN_PATH)
	@$(CC) $(CFLAGS) $(SRC_PATH)/main.c -L$(LIB_PATH) -l$(NAME) -o $(BIN_PATH)/$(NAME)
	@$(CC) $(CFLAGS) $(SRC_PATH)/main.c -L$(LIB_PATH) -l$(NAME) -o $(NAME)


.PHONY: clean fclean re $(NEW_LIB_A)
