# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 15:37:25 by gdelabro          #+#    #+#              #
#    Updated: 2017/03/22 13:05:24 by gdelabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC_PATH = src
SRC_NAME = main.c prompt.c cmd.c traitement.c env.c pars.c lunch.c cd.c pars_cd.c echo.c setenv.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes -I libft/includes

LDFLAGS = -L libft
LDLIBS = -lft
LIB = libft/libft.a

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\n"
	@make -C libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "\033[33;1m$(NAME)\033[0;1m: objects deleted"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "\033[33;1m$(NAME)\033[0;1m: $(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re
