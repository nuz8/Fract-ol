# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 14:30:19 by pamatya           #+#    #+#              #
#    Updated: 2024/07/29 02:02:24 by pamatya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

BIN_PATH=	.
NAME	=	fractol
BIN		=	$(BIN_PATH)/$(NAME)

FT_DIR	=	./lib
LIBFT	=	libft.a
FT		= 	$(FT_DIR)/$(LIBFT)

MLX_DIR	=	./lib
LIB_MLX	=	libmlx42.a
MLX		=	$(MLX_DIR)/$(LIB_MLX)

HEADERS	=	-I ./inc -I ./lib/includes

SRCS	=	./src/main.c ./src/initiations.c ./src/renditions.c \
			./src/boundaries.c ./src/manage_events.c \
			./src/complex_arithmetic.c ./src/iterations.c ./src/utils.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(FT) -Llib -lmlx42 -lglfw -framework OpenGL -framework AppKit $(HEADERS) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -sC $(FT_DIR) all

clean:
	$(RM) $(OBJS)
	$(MAKE) -sC $(FT_DIR) clean

fclean: clean
	$(RM) $(BIN)
	$(RM) $(FT)
	$(MAKE) -sC $(FT_DIR) fclean

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
