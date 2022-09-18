# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 04:35:45 by vahemere          #+#    #+#              #
#    Updated: 2022/09/18 17:10:46 by vahemere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_DIR = objs
SRCS_DIR = $(shell find srcs -type d)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir))
SRCS = main.c \
check_fd.c get_map.c parsing.c check_map.c check_data_map.c check_data_map_utils.c check_body_map.c \
get_next_line_utils.c get_next_line.c \
get_position_player.c \
free_double_arr.c \
ft_split.c remove_wspace.c ft_atoi.c ft_strncmp.c \

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

DEPS = $(OBJS:%.o=%.d)

NAME = cub3d
LIB_DIR = minilibx_linux
LIB_NAME = $(LIB_DIR)/libmlx_Linux.a

########################### COMPILATION AND FLAGS ###########################

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
LIB_FLAGS = -lXext -lX11 -lm

##################################### COLOR ##################################

COLOUR_PURPLE = \033[0;35m
COLOUR_END = \033[0m

##################################### MANDATORY ##############################

all: $(NAME)

$(NAME): $(OBJS)
	cd $(LIB_DIR) && ./configure
	$(CC) $(CFLAGS) $(OBJS) $(LIB_NAME) $(LIB_FLAGS) -I $(LIB_DIR) -o $(NAME)
	@echo "\n\t$(COLOUR_PURPLE)***EXECUTABLE CREATED SUCCESSFULL***\n\n$(COLOUR_END)"

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -MMD -o $@ -c $<

$(OBJS_DIR):
	mkdir -p $@
	@echo "\n\t$(COLOUR_PURPLE)OBJECT DIRECTORY CREATED\n\n$(COLOUR_END)"

clean:
	rm -rf $(OBJS) $(OBJS_DIR) $(DEPS)
	@echo "\n\t$(COLOUR_PURPLE)OBJECT DIRECTORY CREATED\n\n$(COLOUR_END)"

fclean: clean
	rm -rf $(NAME)
	cd $(LIB_DIR) && make clean
	@echo "\n\t$(COLOUR_PURPLE)DELETE EXECUTABLE SUCCESSFULL\n\n$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)