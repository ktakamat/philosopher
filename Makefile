# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 21:24:58 by machi             #+#    #+#              #
#    Updated: 2024/05/30 19:28:30 by ktakamat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP -pthread 
# DEBUG := -g -fsanitize=address -fno-omit-frame-pointer
 DEBUG = -g3 -fsanitize=thread

SRCS_DIR := srcs
SRCS := $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/assign.c \
		$(SRCS_DIR)/data.c \
		$(SRCS_DIR)/died.c \
		$(SRCS_DIR)/table.c \
		$(SRCS_DIR)/eating.c \
		$(SRCS_DIR)/fork.c \
		$(SRCS_DIR)/ft_atoi.c \
		$(SRCS_DIR)/philo.c \
		$(SRCS_DIR)/simulation.c \
		$(SRCS_DIR)/sleeping.c \
		$(SRCS_DIR)/thinking.c \
		$(SRCS_DIR)/time.c \
		$(SRCS_DIR)/info.c \

OBJS_DIR := objs
OBJS := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

INCLUDES_DIR := includes
INCLUDES := -I$(INCLUDES_DIR)

DEPS =	$(OBJS:.o=.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

debug: CFLAGS += $(DEBUG)
debug: re

re: fclean all

-include $(DEPS)
