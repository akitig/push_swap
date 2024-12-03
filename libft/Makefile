# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akunimot <akitig24@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 08:44:44 by akunimot          #+#    #+#              #
#    Updated: 2024/12/03 12:21:05 by akunimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =    ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isalnum.c \
            ft_isprint.c \
            ft_strlen.c \
            ft_memset.c \
            ft_bzero.c \
            ft_memcpy.c \
            ft_memmove.c \
            ft_strlcpy.c \
            ft_strlcat.c \
            ft_toupper.c \
            ft_tolower.c \
            ft_strchr.c \
            ft_strrchr.c \
            ft_strncmp.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_strnstr.c \
            ft_atoi.c \
            ft_calloc.c \
            ft_strdup.c \
            ft_substr.c \
            ft_strjoin.c \
            ft_putchar_fd.c \
            ft_putstr_fd.c \
            ft_putendl_fd.c \
            ft_strmapi.c \
            ft_putnbr_fd.c \
            ft_split.c \
            ft_strtrim.c \
            ft_itoa.c \
            ft_striteri.c \


BONUS_SRC =    ft_lstadd_back.c \
            ft_lstadd_front.c \
            ft_lstclear.c \
            ft_lstdelone.c \
            ft_lstiter.c \
            ft_lstlast.c \
            ft_lstmap.c \
            ft_lstnew.c \
            ft_lstsize.c \
            ft_lstdelone.c \

PRINTF_SRC =    ft_printf.c \
                ft_printf_csp.c \
                ft_printf_diu.c \
                ft_printf_x.c \
            
SRCS                += $(BONUS_SRC) $(PRINTF_SRC)
CC                  = cc
RM                  = rm -f
CFLAGS              = -Wall -Wextra -Werror

NAME            	= libft.a

OBJS            = $(SRCS:.c=.o)
BONUS_OBJS      = $(BONUS_SRC:.c=.o) $(PRINTF_SRC:.c=.o)
OBJS            += $(BONUS_OBJS)

$(NAME):        $(OBJS)
				ar rcs $@ $^

all:            $(NAME)

%.o:            %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			all

.PHONY:			all clean fclean re bonus