# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 14:30:19 by pamatya           #+#    #+#              #
#    Updated: 2024/07/26 06:35:28 by pamatya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
# CC		=	cc -g -fsanitize=address

CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

# BIN_PATH=	.
BIN_PATH=	./bin
NAME	=	fractol
BIN		=	$(BIN_PATH)/$(NAME)

FT_DIR	=	./lib
LIBFT	=	libft.a
FT		= 	$(FT_DIR)/$(LIBFT)

MLX_DIR	=	./lib
LIB_MLX	=	libmlx42.a
MLX		=	$(MLX_DIR)/$(LIB_MLX)

HEADERS	=	-I ./inc -I ./lib/includes


SRCS	=	./src/main.c ./src/initiations.c ./src/errors.c ./src/complex_arithmetic.c ./src/iter_funcns.c ./src/utils.c
OBJS	=	$(SRCS:.c=.o)

TEST	=	./src/main.c
# DEBUG	=	$(TEST)
DEBUG	=	$(SRCS)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(FT) -Llib -lmlx42 -lglfw -framework OpenGL -framework AppKit $(HEADERS) -o $(BIN)
# $(CC) $(CFLAGS) $(OBJS) $(FT)  -Llib -lmlx42 -lglfw -framework OpenGL -framework AppKit $(HEADERS) -o $(BIN)
# $(CC) $(CFLAGS) $(OBJS) $(FT) $(MLX) $(HEADERS) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -sC $(FT_DIR) all

# $(LIB_MLX):
# 	$(MAKE) -sC $(MLX_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(BIN)
	$(RM) $(FT)

cleanx: clean
	$(MAKE) -sC $(FT_DIR) fclean

fcleanx: fclean
	$(MAKE) -sC $(FT_DIR) fclean

re: fclean
	$(MAKE) fclean
	$(MAKE) all
# $(MAKE) -sC $(MLX_DIR) re

.PHONY: all clean fclean re
