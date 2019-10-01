# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/02 12:44:40 by pleroux           #+#    #+#              #
#    Updated: 2018/06/29 17:39:28 by pierre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_PATH= libft/
LIB= $(LIB_PATH)/libft.a
LIB_HEAD= $(LIB_PATH)/includes
LIB_PRINTF= libftprintf-tmp.a
NAME= libftprintf.a

CFLAGS = -Wall -Wextra -Werror -I $(LIB_HEAD)
CC = gcc
INC_DIR =./inc

SRC_DIR = src/
SRC_FILE = format_c.c \
		   format_d.c \
		   format_s.c\
		   format_tools.c \
		   format_uox.c \
		   format_uox_attr.c \
		   ft_printf.c \
		   ft_sprintf.c \
		   ft_vasprintf.c \
		   mae_parse.c \
		   param.c \
		   resolve_format.c \
		   search_next_format.c \
		   misc.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	ar rcs $(LIB_PRINTF) $(OBJ)
	#libtool -static -o $(NAME) $(LIB_PRINTF) $(LIB)
	ar -x $(LIB)
	ar -x $(LIB_PRINTF)
	ar -qc $(NAME)  *.o
	rm -f *.o
	rm -f $(LIB_PRINTF)

$(LIB)	:
	make -C $(LIB_PATH)

clean	:
	rm -f $(OBJ)
	make -C $(LIB_PATH) clean

fclean	: clean
	rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re		: fclean all

.PHONY : all clean re fclean compile $(LIB)
