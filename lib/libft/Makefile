# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 11:18:06 by lmangall          #+#    #+#              #
#    Updated: 2023/04/21 20:35:40 by lmangall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS_PATH = ../../include/
SRCS_PATH = ./src/
OBJS_PATH = ./obj/
LIBS_PATH = ../

CC = gcc
FLAGS = -Wall -Wextra -Werror

RM = rm -f
MKDIR = mkdir -p

LIBNAME = libft.a
SRC_FILES =	ft_bzero.c		\
			ft_memcpy.c		\
			ft_memmove.c 	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memset.c		\
			ft_strlen.c		\
			ft_isalpha.c 	\
			ft_calloc.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_strdup.c			\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strtrim.c		\
			ft_split.c			\
			ft_strjoin.c		\
			ft_substr.c			\
			ft_strncmp.c		\
			ft_strlcpy.c		\
			ft_strlcat.c		\
			ft_strnstr.c		\
			ft_strmapi.c		\
			ft_striteri.c		\
			ft_atoi.c			\
			ft_itoa.c			\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_lstnew.c			\
			ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c

SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

all: libft $(LIBNAME)

libft:
	@echo "$(LIBNAME): Compiling...(from libft Makefile)"
	@$(MKDIR) $(SRCS_PATH) $(OBJS_PATH)
	@echo "$(LIBNAME): Compiling complete!(from libft Makefile)"

$(LIBNAME): $(OBJECTS)
	@ar -rcs $(LIBS_PATH)$(LIBNAME) $(OBJECTS)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	@$(CC) $(FLAGS) -c -I $(HEADERS_PATH) $< -o $@

clean:
	@$(RM) $(OBJECTS)
	@echo "$ Cleaning..."
	@echo "$(LIBNAME): object (*.o) files were deleted"

fclean:
	@$(RM) $(OBJECTS)
	@$(RM) $(LIBS_PATH)$(LIBNAME)
	@echo "$(LIBNAME): Cleaned!"

re: fclean all

.PHONY:	all clean fclean re
