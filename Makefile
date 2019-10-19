# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pierre <Pierre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 13:59:37 by pierre            #+#    #+#              #
#    Updated: 2019/10/18 21:37:04 by pleroux          ###   ########.fr        #
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

SRC_DIR_NM = nm/
SRC_DIR_COM = common/
SRC_DIR_OTOOL = otool/

SRC_FILE_COM = open.c \
			   singleton.c \
			   swap.c	\
			   singleton_arg.c \

SRC_FILE_NM = main.c \
		 macho.c \
		 magic.c \
		 print.c \
		 sort.c \
		 fat.c \
		 arg.c \

SRC_FILE_OTOOL = main.c \
				 magic.c \
				 macho.c \
				 print_memory.c \

SRC_NM = $(addprefix $(SRC_DIR), $(addprefix $(SRC_DIR_NM), $(SRC_FILE_NM)))
SRC_OTOOL = $(addprefix $(SRC_DIR), $(addprefix $(SRC_DIR_OTOOL), $(SRC_FILE_OTOOL)))
SRC_COM = $(addprefix $(SRC_DIR), $(addprefix $(SRC_DIR_COM), $(SRC_FILE_COM)))

OBJ_COM = $(SRC_COM:.c=.o)
OBJ_NM = $(SRC_NM:.c=.o)
OBJ_OTOOL = $(SRC_OTOOL:.c=.o)

INC = $(addprefix $(INC_DIR), $(INC_FILE))

all		: $(LIB) $(LIB_PRINTF) $(NAME_NM) $(NAME_OTOOL)

$(LIB)	:
	make -C $(LIB_PATH)

$(LIB_PRINTF)	:
	make -C $(LIB_PRINTF_PATH)

#$(OBJ_NM): $(SRC_NM) $(INC)
#	     $(CC) $(CFLAGS) -o $@ -c $<
#
#$(OBJ_OTOOL): $(SRC_OTOOL) $(INC)
#	     $(CC) $(CFLAGS) -o $@ -c $<

%.o: %.c $(INC)
	     $(CC) $(CFLAGS) -o $@ -c $<

$(NAME_NM)	: $(OBJ_COM) $(OBJ_NM)
	$(CC) -o $(NAME_NM) $(CFLAGS) $(OBJ) $(OBJ_COM) $(OBJ_NM) $(LIB_FLAGS)

$(NAME_OTOOL)	: $(OBJ_COM) $(OBJ_OTOOL)
	$(CC) -o $(NAME_OTOOL) $(CFLAGS) $(OBJ) $(OBJ_COM) $(OBJ_OTOOL) $(LIB_FLAGS)

clean	:
	rm -f $(OBJ) $(OBJ_NM) $(OBJ_OTOOL)
	make -C $(LIB_PATH) fclean
	make -C $(LIB_PRINTF_PATH) fclean

fclean	: clean
	rm -f $(NAME)

re		: clean all

.PHONY	: all clean re fclean $(LIB) $(LIB_PRINTF)
