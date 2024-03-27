# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 02:50:47 by erpiana           #+#    #+#              #
#    Updated: 2024/03/27 16:23:02 by erpiana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                   PATH                                       #
#******************************************************************************#

MLX42_P          := MLX42/
MLX42_BUILD_P    := MLX42/build/
SRC_P            := srcs/
SRC_BONUS_P      := srcs_bonus/
LIB_P            := libft/
MAPS_P           := maps/
INCS             := include/ $(LIB_P)include/ $(MLX42_P)include/
CPPFLAGS         := $(addprefix -I, $(INCS)) -MP

#******************************************************************************#
#                                  FILES                                       #
#******************************************************************************#

SRCS       += $(addprefix $(SRC_P), 0_main.c 1_ft_parse_arguments.c 2_ft_validate.c 3_ft_utils_validate.c 4_ft_checks.c 5_ft_validate_path.c 6_ft_init_game.c \
						7_ft_create_map.c 8_ft_movements.c 9_finish_game.c)
SRCS_BONUS  += $(addprefix $(SRC_BONUS_P), 0_main_bonus.c 1_ft_parse_arguments_bonus.c 2_ft_validate_bonus.c 3_ft_utils_validate_bonus.c \
						4_ft_checks_bonus.c 5_ft_validate_path_bonus.c 6_ft_init_game_bonus.c 7_ft_create_map_bonus.c 8_ft_movements_bonus.c \
						9_finish_game_bonus.c 10_steps_bonus.c 11_animation_player_bonus.c)
OBJS     += $(addprefix obj/, $(notdir $(SRCS:.c=.o)))
OBJS_B   += $(addprefix obj_bonus/, $(notdir $(SRCS_BONUS:.c=.o)))
NAME     := so_long
NAME_B   := so_long_bonus
LIBFT    := $(addprefix $(LIB_P), libft.a)
MLX      := $(addprefix $(MLX42_BUILD_P), libmlx42.a)
LIBS     := $(LIBFT) $(MLX)

#******************************************************************************#
#                               BASH COMMANDS                                  #
#******************************************************************************#

RM          := rm -rf
BUILD       := obj/
BUILD_BONUS := obj_bonus/

#******************************************************************************#
#                                COMPILATION                                   #
#******************************************************************************#

CC       := cc
CFLAGS   :=  -g3 -Ofast -Wall -Wextra -Werror
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

$(NAME_B): obj_bonus $(OBJS_B)
	$(CC) $(OBJS_B) $(LDLIBS) $(LIBS) -o $@
	echo "Executável $@ criado com sucesso!"

obj:
	mkdir -p $(BUILD)

obj_bonus:
	mkdir -p $(BUILD_BONUS)

obj/%.o: $(SRC_P)%.c $(INCS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	
obj_bonus/%.o: $(SRC_BONUS_P)%.c $(INCS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

bonus: $(MLX) $(LIBFT) $(NAME_B)	

clean:
	make fclean -C libft/
	$(RM) $(MLX42_BUILD_P)
	$(RM) $(BUILD)
	$(RM) $(BUILD_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re: fclean all

.PHONY: all clean fclean bonus

.DEFAULT_GOAL := all

.SILENT: