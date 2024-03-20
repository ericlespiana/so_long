# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 02:50:47 by erpiana           #+#    #+#              #
#    Updated: 2024/03/19 21:52:37 by erpiana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                   PATH                                       #
#******************************************************************************#

MLX42_P          := MLX42/
MLX42_BUILD_P    := MLX42/build/
SRC_P            := srcs/
LIB_P            := libft/
MAPS_P           := maps/
INCS             := include/ $(LIB_P)include/ $(MLX42_P)include/
CPPFLAGS         := $(addprefix -I, $(INCS)) -MP

#******************************************************************************#
#                                  FILES                                       #
#******************************************************************************#

SRCS     += $(addprefix $(SRC_P), 0_main.c 1_ft_parse_arguments.c 2_ft_validate.c 3_ft_utils_validate.c 4_ft_checks.c 5_ft_validate_path.c 6_ft_init_game.c \
									7_ft_create_map.c)
OBJS     += $(addprefix obj/, $(notdir $(SRCS:.c=.o)))
NAME     := so_long
LIBFT    := $(addprefix $(LIB_P), libft.a)
MLX      := $(addprefix $(MLX42_BUILD_P), libmlx42.a)
LIBS     := $(LIBFT) $(MLX)

#******************************************************************************#
#                               BASH COMMANDS                                  #
#******************************************************************************#

RM       := rm -rf
BUILD    := obj/

#******************************************************************************#
#                                COMPILATION                                   #
#******************************************************************************#

CC       := cc
CFLAGS   :=  -g3 -Wall -Wextra -Werror
LDFLAGS  := $(addprefix -L,$(dir $(LIBS)))
LDLIBS   := -ldl -lglfw -lm -lpthread

#******************************************************************************#
#                                  TARGETS                                     #
#******************************************************************************#

all: $(MLX) $(LIBFT) $(NAME)

$(MLX):
	cd $(MLX42_P) && cmake -B build -DDEBUG=1
	cd $(MLX42_P) && cmake --build build -j4

$(LIBFT):
	make bonus -C libft/

$(NAME): obj $(OBJS)
	$(CC) $(OBJS) $(LDLIBS) $(LIBS) -o $@
	echo "Executável $@ criado com sucesso!"

obj:
	mkdir -p $(BUILD)

obj/%.o: $(SRC_P)%.c $(INCS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	make fclean -C libft/
	$(RM) $(MLX42_BUILD_P)
	$(RM) $(BUILD)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean

.DEFAULT_GOAL := all

.SILENT: