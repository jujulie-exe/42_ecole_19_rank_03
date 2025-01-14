# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 17:55:26 by jfranco           #+#    #+#              #
#    Updated: 2025/01/14 16:25:32 by jfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# Compiler and flags
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror 
#-fsanitize=thread

# Source files and objects
SRCS = $(wildcard src/*.c)
OBJ_DIR = obj
OBJ = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)



# Default target
all: $(NAME)
	@echo "\033[38;5;213m(っ◔◡◔)っ ♥ Ecole 19 | philo | Julie ♥\033[0m"

# Create the object directory before compiling
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile the program
$(NAME): $(OBJ_DIR) $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Rule to compile .c into .o
$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean objects and MiniLibX
clean:
	rm -rf $(OBJ_DIR)
	@echo "File oggetto rimossi."

# Clean everything (objects and executable)
fclean: clean
	rm -f $(NAME)
	@echo "Eseguibile rimosso."

# Recompile everything
re: fclean all

# Run the program
run: re
	./$(NAME)

.PHONY: all clean fclean re run
