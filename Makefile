# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/04 22:28:38 by fchancel     #+#   ##    ##    #+#        #
#    Updated: 2019/03/06 19:14:37 by fchancel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		= 	minishell
SRC_PATH 	= 	src
SRC_NAME 	=	read.c				\
				main.c				\
				prompt.c			\
				path.c				\
				ft_env.c			\
				exec_cmd.c			\
				display_error.c		\
				annex_function.c	\
				ft_linked_list.c	\
				loop.c				\
				builtins.c			\
				builtin_cd.c		\
				builtin_env.c		\
				expansion.c
OBJ_PATH	= 	objs
CPPFLAGS	=	-I include
LDFLAG		= 	-L libft
LDLIBS		=	-lft
CC 			=	clang
CFLAGS 		=	-Werror -Wall -Wextra

OBJ_NAME 	= 	$(SRC_NAME:.c=.o)

SRC 		=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ 		=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft
		@$(CC) $(LDFLAG) $(LDLIBS) $^ -o $@
		@echo "Compilation minishell .... OK"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
		@make -C libft clean
		@rm -fv $(OBJ)
		@rmdir $(OBJ_PATH) 2> /dev/null || true
		@echo "Clean minishell .......... OK"

fclean: clean
		@rm -f libft/libft.a
		@rm -fv $(NAME)
		@echo "Fclean minishell .......... OK"
re: fclean all

