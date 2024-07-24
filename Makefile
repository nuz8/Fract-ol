# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 14:30:19 by pamatya           #+#    #+#              #
#    Updated: 2024/07/23 23:05:29 by pamatya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
# CC		=	cc -g -fsanitize=address

CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

NAME	=	fractol

FT_DIR	=	./lib
LIBFT	=	libft.a
FT_PATH	= 	$(FT_DIR)/$(LIBFT)

MLX_DIR	=	./lib/MLX42
MLX_LIB	=	libmlx42.a
MLX		=	$(MLX_DIR)/$(MLX_LIB)

PATHS	=	./lib

# EXE_PATH=	.
EXE_PATH=	./bin

TEST	=	./src/main.c

SRCS	=	./src/main.c ./src/complex_arithmetic.c ./src/iter_funcns.c ./src/utils.c

OBJS	=	$(SRCS:.c=.o)

# DEBUG	=	$(TEST)
DEBUG	=	$(SRCS)

all: $(NAME)

# $(NAME): $(OBJS) $(LIBFT)
# 	cp ./$(FT_PATH) $(EXE_PATH)/$(FRCT_LIB)
# 	ar rcs $(EXE_PATH)/$(FRCT_LIB) $(OBJS)
# 	$(CC) $(CFLAGS) $(EXE_PATH)/$(FRCT_LIB) -o $(EXE_PATH)/$(NAME)

$(NAME): $(OBJS) $(FT_PATH) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PATH) $(MLX) $(PATHS) -o $(EXE_PATH)/$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FT_PATH):
	$(MAKE) -sC $(FT_DIR) all

$(MLX):
	$(MAKE) -sC $(MLX_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(EXE_PATH)/$(NAME)

# $(RM) $(EXE_PATH)/$(NAME)2
# $(RM) ./bin/test
# $(RM) -r ./bin/test.dSYM
# $(RM) ./bin/bug
# $(RM) -r ./bin/bug.dSYM

re: fcleanx
	$(MAKE) fclean
	$(MAKE) all

cleanx:
	$(RM) $(OBJS)
	$(MAKE) -sC $(FT_DIR) clean

fcleanx: cleanx
	$(RM) $(FRCT_LIBFT)
	$(RM) $(EXE_PATH)/$(NAME)
	$(MAKE) -sC $(FT_DIR) fclean

bug:
	$(CC) -g $(CFLAGS) ./$(FT_PATH) $(DEBUG) -o ./bin/bug

test:
	$(CC) $(CFLAGS) ./$(FT_PATH) $(TEST) -o ./bin/test
	./bin/test

exe: all
	./bin/$(NAME)

.PHONY: all clean fclean re cleanx fcleanx bug test
