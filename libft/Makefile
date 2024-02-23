# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 07:56:03 by erpiana           #+#    #+#              #
#    Updated: 2024/02/23 02:22:40 by erpiana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                   PATH                                       #
#******************************************************************************#

SRCS_PATH 	:= 	srcs/
INCS 		:= 	include/
CPPFLAGS	:= 	$(addprefix -I,$(INCS)) -MP

#******************************************************************************#
#                                   FILES                                      #
#******************************************************************************#

SRCS 		:= 	$(addprefix $(SRCS_PATH), ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
				ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
				ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
				ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_itoa.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
				ft_striteri.c ft_printf.c ft_print_format.c ft_puthexa.c ft_printf_utils.c get_next_line.c get_next_line_utils.c)
OBJS		+=	$(addprefix obj/, $(notdir $(SRCS:.c=.o)))
BONUS 		:=	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c ft_lstlast_bonus.c \
				ft_lstmap_bonus.c ft_lstnew_bonus.c \
				ft_lstsize_bonus.c
BONUS_OBJS	+= 	$(addprefix obj/, $(notdir $(BONUS:.c=.o)))
NAME 		:= 	libft.a

#******************************************************************************#
#                                  BASH COMMANDS                               #
#******************************************************************************#

RM			:= 	rm -rf

#******************************************************************************#
#                                  COMPILATION                                 #
#******************************************************************************#

CC			:= 	cc
CFLAGS 		:= 	-Wall -Wextra -Werror

#******************************************************************************#
#                                   TARGETS                                    #
#******************************************************************************#

all: $(NAME)

obj:
		mkdir -p obj

$(NAME): obj $(OBJS)
		echo "Comprimindo mandatórios no arquivo $@"
		
obj/%.o:	$(SRCS_PATH)%.c
		$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
		echo "Compilando o arquivo $(notdir $<)"
		ar -rcs $(NAME) $@
		
clean:
		$(RM) obj
		
fclean:	clean
		$(RM) $(NAME)
		
re:	fclean all

bonus: $(NAME) $(BONUS_OBJS)
		echo "Comprimindo bonus no arquivo $<"

.PHONY:	all clean fclean re bonus

.DEFAULT_GOAL := all

.SILENT:
