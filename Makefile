# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chourri <chourri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 15:45:53 by chourri           #+#    #+#              #
#    Updated: 2024/05/20 16:59:50 by chourri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx
RM = rm -rf
VPATH = src
SRCS = main.c \
 tools.c \
 check_errors.c \
 colors.c \
 fractals.c \
 hooks.c \
 image.c \
 initialization.c \

HEADERS = -I ./inc
HDRS = ./inc/fractol.h
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGl -framework AppKit -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c $(HDRS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
