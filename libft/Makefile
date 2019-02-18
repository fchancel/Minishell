# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/04 22:29:06 by fchancel     #+#   ##    ##    #+#        #
#    Updated: 2019/02/18 14:46:21 by fchancel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		=	libft.a
SRC_PATH 	= 	src
SRC_NAME 	= 	ft_atoi.c			\
				ft_bzero.c			\
				ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_isprint.c		\
				ft_itoa.c			\
				ft_memalloc.c		\
				ft_memccpy.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_memcpy.c			\
				ft_memdel.c			\
				ft_memmove.c		\
				ft_memset.c			\
				ft_putchar.c		\
				ft_putchar_fd.c		\
				ft_putendl.c		\
				ft_putendl_fd.c		\
				ft_putnbr.c			\
				ft_putnbr_fd.c		\
				ft_putstr.c			\
				ft_putstr_fd.c		\
				ft_strcat.c			\
				ft_strchr.c			\
				ft_strclr.c			\
				ft_strcmp.c			\
				ft_strcpy.c			\
				ft_strdel.c			\
				ft_strdup.c			\
				ft_strequ.c			\
				ft_striter.c		\
				ft_striteri.c		\
				ft_strjoin.c		\
				ft_strlcat.c		\
				ft_strlen.c			\
				ft_strmap.c			\
				ft_strmapi.c		\
				ft_strncat.c		\
				ft_strncmp.c		\
				ft_strncpy.c		\
				ft_strnequ.c		\
				ft_strnew.c			\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_strsplit.c		\
				ft_strstr.c			\
				ft_strsub.c			\
				ft_strtrim.c		\
				ft_tolower.c		\
				ft_toupper.c		\
				ft_sort_tab.c		\
				ft_isspace.c		\
				ft_display_s2tab.c	\
				ft_free_2tab.c		\
				ft_strnjoin.c		\
				ft_realloc.c		\
				ft_free_tab.c		\
				ft_error.c			\
				get_next_line.c		\
				ft_putcolor.c		\
				ft_intlen.c			\
				ft_count_char.c		\

OBJ_PATH		= 	objs
CPPFLAGS	=	-I include
CC 			=	clang
CFLAGS 		=	-Werror -Wall -Wextra

OBJ_NAME 	= 	$(SRC_NAME:.c=.o)

SRC 		=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ 		=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar ruc $@ $?
	@ranlib $@
	@echo "Compilation libft .... OK"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Clean libft .......... OK"

fclean: clean
	@rm -fv $(NAME)
	@echo "Fclean libft .......... OK"

re: fclean all

