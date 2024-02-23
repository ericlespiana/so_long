# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 02:50:47 by erpiana           #+#    #+#              #
#    Updated: 2024/02/23 08:05:49 by erpiana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                   PATH                                       #
#******************************************************************************#

SRC_P    := srcs/
LIB_P    := libft/
TEXT_P   := textures/
MAPS_P   := maps/
INCS     := include/ $(LIB_P)include
CPPFLAGS := $(addprefix -I, $(INCS)) -MP

#******************************************************************************#
#                                  FILES                                       #
#******************************************************************************#

SRCS     += $(addprefix $(SRC_P), main.c ft_parse.c ft_validate.c ft_utils_error.c)
OBJS     += $(addprefix obj/, $(notdir $(SRCS:.c=.o)))
NAME     := so_long
LIBFT    := $(addprefix $(LIB_P), libft.a) 

#******************************************************************************#
#                               BASH COMMANDS                                  #
#******************************************************************************#

RM       := rm -rf
BUILD    := obj/

#******************************************************************************#
#                                COMPILATION                                   #
#******************************************************************************#

CC       := cc
CFLAGS   := -Wall -Wextra -Werror

#******************************************************************************#
#                                  TARGETS                                     #
#******************************************************************************#

all: $(LIBFT) $(NAME)

$(LIBFT):
	make bonus -C libft/

$(NAME): obj $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $@
	echo "Executável $@ criado com sucesso!"

obj:
	mkdir -p $(BUILD)

obj/%.o: $(SRC_P)%.c $(INCS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	make fclean -C libft/
	$(RM) $(BUILD)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean

.DEFAULT_GOAL := all

.SILENT: