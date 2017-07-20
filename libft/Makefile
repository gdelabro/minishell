# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 12:46:39 by gdelabro          #+#    #+#              #
#    Updated: 2017/03/22 13:05:35 by gdelabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FC = ft_atoi.c ft_memccpy.c ft_putendl.c ft_strcmp.c ft_strlen.c ft_strrchr.c\
ft_bzero.c ft_memchr.c ft_putendl_fd.c ft_strcpy.c ft_strmap.c ft_strsplit.c\
ft_isalnum.c ft_memcmp.c ft_putnbr.c ft_strdel.c ft_strmapi.c ft_strstr.c ft_putlong.c\
ft_isalpha.c ft_memcpy.c ft_putnbr_fd.c  ft_strdup.c ft_strncat.c ft_strsub.c add_str.c\
ft_isascii.c ft_memdel.c ft_putstr.c ft_strequ.c ft_strncmp.c ft_strtrim.c ft_strcpyend.c\
ft_isdigit.c ft_memmove.c ft_putstr_fd.c  ft_striter.c ft_strncpy.c ft_tolower.c ft_strccpy.c\
ft_isprint.c ft_memset.c ft_strcat.c ft_striteri.c ft_strnequ.c ft_toupper.c ft_putlong.c\
ft_itoa.c ft_putchar.c ft_strchr.c ft_strjoin.c ft_strnew.c ft_swap.c ft_strsplit_nbr.c ft_split_space.c\
ft_memalloc.c ft_putchar_fd.c ft_strclr.c ft_strlcat.c ft_strnstr.c ft_strlen_fd.c ft_fdcpy.c\
ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstdel.c ft_lstdelone.c get_next_line.c\

OBJ = $(FC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "libft: [\033[32;1mOK\033[0;1m]\n"

%.o: %.c
	@printf "\033[35;1m| \033[0;1m"
	@gcc -Wall -Wextra -Werror -c $<

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf libft.a

re : fclean all
