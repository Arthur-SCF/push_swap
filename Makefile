# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: your_login <your_login@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 00:00:00 by your_login       #+#    #+#              #
#    Updated: 2025/07/13 00:00:00 by your_login      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./include -I./ft_printf/includes -I./ft_printf/libft

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
FT_PRINTF_DIR = ft_printf

# Source files
SRC_FILES = main.c \
            parsing.c \
			greedy_sort.c \
			greedy_utils.c \
			doubled_operations.c \
            stack_operations.c \
            push_operations.c \
            swap_operations.c \
            rotate_operations.c \
            chunk_sort.c \
            utils.c \
            small_sort.c \
			small_sort_2.c

# Object files
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Header files
HEADERS = $(INC_DIR)/push_swap.h

# ft_printf library
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

# Rules  	
all: $(NAME)

$(NAME): $(FT_PRINTF) $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

$(FT_PRINTF):
	@echo "$(BLUE)Building ft_printf...$(RESET)"
	@make -C $(FT_PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make clean -C $(FT_PRINTF_DIR)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make fclean -C $(FT_PRINTF_DIR)

re: fclean all

# Debug rule
debug: CFLAGS += -DDEBUG
debug: re

# Valgrind rule for memory leak checking
valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Test with sample inputs
test: $(NAME)
	@echo "$(BLUE)Testing with sample inputs...$(RESET)"
	@echo "Test 1: ./$(NAME) 2 1 3 6 5 8"
	@./$(NAME) 2 1 3 6 5 8
	@echo "\nTest 2: ./$(NAME) 4 67 3 87 23"
	@./$(NAME) 4 67 3 87 23

# Norm check (if you have norminette installed)
norm:
	@echo "$(BLUE)Checking norm...$(RESET)"
	@norminette $(SRC_DIR) $(INC_DIR)

.PHONY: all clean fclean re debug valgrind test norm