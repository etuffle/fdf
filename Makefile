# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/02 18:07:51 by etuffleb          #+#    #+#              #
#    Updated: 2019/02/26 13:26:34 by etuffleb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# src/obj

SRC = main.c \
	get_next_line.c \
	fdf.c \
	read_valid.c \
	ft_atoi_base.c \
	line.c

OBJ = $(addprefix ./obj/,$(SRC:.c=.o))

# compiler

CFLAGS = -Wall -Wextra -Werror -g

# mlx library

MLX_LIB	= $(addprefix ./minilibx/,mlx.a)
MLX_INC	= -I ./miniLibX 
MLX_LNK	= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

# ft library

FT_LIB	= $(addprefix ./libft/,libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# directories

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C ./libft

$(MLX_LIB):
	make -C ./minilibx

$(NAME): $(OBJ)
	gcc $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean
	make -C ./minilibx clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all
