# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 14:30:19 by pamatya           #+#    #+#              #
#    Updated: 2024/07/25 04:10:50 by pamatya          ###   ########.fr        #
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

MLX_DIR	=	./lib/MLX42
LIB_MLX	=	libmlx42.a
MLX		=	$(MLX_DIR)/$(LIB_MLX)

INCLUDE	=	-I ./inc -I ./lib/includes -I ./lib/MLX42/include

SRCS	=	./src/test_main.c ./src/complex_arithmetic.c ./src/iter_funcns.c ./src/utils.c
OBJS	=	$(SRCS:.c=.o)

TEST	=	./src/main.c
# DEBUG	=	$(TEST)
DEBUG	=	$(SRCS)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIB_MLX)
	$(CC) $(CFLAGS) $(OBJS) $(FT) $(MLX) $(INCLUDE) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -sC $(FT_DIR) all

$(LIB_MLX):
	$(MAKE) -sC $(MLX_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(BIN)
	$(RM) $(FT)
	$(RM) $(MLX)

cleanx: clean
	$(MAKE) -sC $(FT_DIR) fclean

fcleanx: fclean
	$(MAKE) -sC $(FT_DIR) fclean

re: fclean
	$(MAKE) fclean
	$(MAKE) -sC $(MLX_DIR) re
	$(MAKE) all

.PHONY: all clean fclean re
