# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pierre <Pierre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 13:59:37 by pierre            #+#    #+#              #
#    Updated: 2019/10/01 17:36:36 by Pierre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DBG=-ggdb -fsanitize=address -fno-omit-frame-pointer -g3
DBG2=-ggdb  -fsanitize=address -fsanitize-memory-track-origins

NAME_NM = ft_nm
NAME_OTOOL = ft_otool
CC = gcc
LIB_PRINTF = ft_printf/libftprintf.a
LIB_PRINTF_PATH = ft_printf/
LIB_PRINTF_HEADER = ft_printf/inc
LIB_PRINTF_LINK = ftprintf
LIB = libft/libft.a
LIB_PATH = libft/
LIB_HEADER = libft/includes
LIB_LINK = ft
SRC_DIR = src/
INC_DIR = inc/
CFLAGS = -Wall -Werror -Wextra -I $(LIB_HEADER) -I $(LIB_PRINTF_HEADER) -I $(INC_DIR)
LIB_FLAGS = -L$(LIB_PRINTF_PATH) -l$(LIB_PRINTF_LINK) -L$(LIB_PATH) -l$(LIB_LINK)
			
INC_FILE = common.h \

SRC_FILE =  \

SRC_NM = $(SRC_DIR)nm/main.c
SRC_OTOOL = $(SRC_DIR)otool/main.c
OBJ_NM = $(SRC_NM:.c=.o)
OBJ_OTOOL = $(SRC_OTOOL:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
INC = $(addprefix $(INC_DIR), $(INC_FILE))
OBJ = $(SRC:.c=.o)

all		: $(LIB) $(LIB_PRINTF) $(NAME_NM) $(NAME_OTOOL)

$(LIB)	:
	make -C $(LIB_PATH)

$(LIB_PRINTF)	:
	make -C $(LIB_PRINTF_PATH)

$(OBJ_NM): $(SRC_NM) $(INC)
	     $(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_OTOOL): $(SRC_OTOOL) $(INC)
	     $(CC) $(CFLAGS) -o $@ -c $<

%.o: %.c $(INC)
	     $(CC) $(CFLAGS) -o $@ -c $<

$(NAME_NM)	: $(OBJ) $(OBJ_NM)
	$(CC) -o $(NAME_NM) $(CFLAGS) $(OBJ) $(OBJ_NM) $(LIB_FLAGS)

$(NAME_OTOOL)	: $(OBJ) $(OBJ_OTOOL)
	$(CC) -o $(NAME_OTOOL) $(CFLAGS) $(OBJ) $(OBJ_OTOOL) $(LIB_FLAGS)

clean	:
	rm -f $(OBJ) $(OBJ_NM) $(OBJ_OTOOL)
	make -C $(LIB_PATH) fclean
	make -C $(LIB_PRINTF_PATH) fclean

fclean	: clean
	rm -f $(NAME)

re		: clean all

.PHONY	: all clean re fclean $(LIB) $(LIB_PRINTF)
