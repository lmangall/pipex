# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 20:19:22 by lmangall          #+#    #+#              #
#    Updated: 2023/04/21 20:40:26 by lmangall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBNAME = libft

HEADERS_PATH 	= ./include/
SRCS_PATH 		= ./src/
OBJS_PATH 		= ./obj/
LIBS_PATH 		= ./lib/
ROOT	 		= ./

CC 		= cc -g
FLAGS 	= -Wall -Wextra -Werror

RM 			 = rm -f
MKDIR 		 = mkdir -p
MAKE_NOPRINT = $(MAKE) --no-print-directory

SRC_FILES = pipex.c errors.c execute_cmd.c \

SOURCES 	= $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES 	= $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS 	= $(addprefix $(OBJS_PATH), $(OBJ_FILES))
EXECUTABLE 	= pipex

all: $(NAME) main

libft:
	@echo "$(LIBNAME): Libft compiling..."
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT)
	@echo "$(LIBNAME): Libft complete!"

$(NAME): $(OBJECTS) libft
	@cp $(LIBS_PATH)/libft.a $(LIBS_PATH)$(NAME)
	@ar -rcs $(LIBS_PATH)$(NAME) $(OBJECTS)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	@echo "$(NAME): Compiling..."
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(FLAGS) -c $< -I $(HEADERS_PATH) -o $@

main: $(OBJECTS)
	@echo "$(NAME): Pipex compiling..."
	@$(CC) $(FLAGS) $(OBJECTS) $(LIBS_PATH)$(NAME) -I $(HEADERS_PATH) -o $(ROOT)$(EXECUTABLE)
	@echo "$(NAME): Pipex complete!"
clean:
	@$(RM) $(OBJECTS)
	@echo "$ Cleaning..."
	@echo "$(NAME): object (*.o) files were deleted"
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@

fclean: clean
	@$(RM) $(ROOT)$(EXECUTABLE)
	@$(RM) $(LIBS_PATH)$(NAME)
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@
	@echo "$(NAME): Cleaned!"

re: fclean all

.PHONY: all run clean fclean re
