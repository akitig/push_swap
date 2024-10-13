# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 19:08:23 by akunimot          #+#    #+#              #
#    Updated: 2024/09/27 20:03:58 by akunimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

### srcs ###
PS_SRCS =	main.c \

LIBFT_A = libft/libft.a

### commands ###
CC		 	= gcc
WWW		 	= -Wall -Wextra -Werror
RM			= rm -f
PS_OBJS 	= $(PS_SRCS:.c=.o)

### decoration ###
RED = \033[1;31m
GRN = \033[1;32m
YEL = \033[1;33m
PRP = \033[1;34m
PNC = \033[1;35m
CYN = \033[1;36m
WHT = \033[1;37m
EOC = \033[1;0m

TOP_MRK = "$(PNC)****$(EOC)"
UND_MRK = "$(PNC)----$(EOC)"
CMD_MRK = @echo "$(PNC) | >$(EOC)"
INDENT  = sed 's/^/  /'

F_PS 	= "$(PNC)[$(NAME)]$(EOC)"
STR_MES = "$(WHT)START $@$(EOC)"
FIN_MES = "$(GRN)$@ done.$(EOC)"

### subject ###
all: $(NAME)

$(NAME): $(PS_OBJS)
	make -C libft all
	make $(PS_OBJS)
	$(CC) $(WWW) -o $(NAME) $(PS_OBJS) $(LIBFT_A)

%.o:%.c
	$(CC) $(WWW) -c $< -o $@

clean:
	make -C libft clean
	$(RM) $(PS_OBJS)

fclean:
	make -C libft fclean
	$(RM) $(PS_OBJS)
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re