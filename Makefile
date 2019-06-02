
CC := gcc
NA := nasm
FLAGS := -f macho64 -g

NAME_LIB := libft.a
NAME_BIN := main

DIR_SRC_LIB := src
DIR_OBJ_LIB := .obj

DIR_SRC_BIN := bintest
DIR_OBJ_BIN := .obj

ITE_LIB :=	ft_bzero \
			ft_strcat \
			ft_strlen \
			ft_isalpha \
			char_table \
			char_type \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isprint \
			ft_tolower \
			ft_puts \
			ft_toupper \
			ft_memset \
			ft_memcpy \
			ft_strdup \
			ft_cat \
			ft_isspace \
			ft_isblank \
			ft_putstr \
			ft_putchar \
			ft_putchar_fd \
			# ft_putstr_fd \
			# ft_memalloc \

ITE_BIN :=	bintest

SRC_LIB := $(patsubst %, $(DIR_SRC_LIB)/%.s, $(ITE_LIB))
OBJ_LIB := $(patsubst %, $(DIR_OBJ_LIB)/%.o, $(ITE_LIB))

SRC_BIN := $(patsubst %, $(DIR_SRC_BIN)/%.c, $(ITE_BIN))
OBJ_BIN := $(patsubst %, $(DIR_OBJ_BIN)/%.o, $(ITE_BIN))

all: $(NAME_LIB) $(NAME_BIN)

#####################################_LIB_######################################

$(DIR_OBJ_LIB)/%.o: $(DIR_SRC_LIB)/%.s
	mkdir -p $(DIR_OBJ_LIB)
	$(NA) $(FLAGS) -o $@ $<

$(NAME_LIB): $(OBJ_LIB)
	ar rcs $(NAME_LIB) $(OBJ_LIB)
	ranlib $(NAME_LIB)

#####################################_MAIN_#####################################

$(DIR_OBJ_BIN)/%.o: $(DIR_SRC_BIN)/%.c
	mkdir -p $(DIR_OBJ_BIN)
	$(CC) -o $@ -c $<

$(NAME_BIN): $(OBJ_BIN)
	$(CC) $(OBJ_BIN) $(NAME_LIB) -o $@ -g

#####################################_OTHER_#####################################

clean:
	/bin/rm -rf $(DIR_OBJ_LIB) $(DIR_OBJ_BIN)

fclean: clean
	/bin/rm $(NAME_LIB) $(NAME_BIN)

re: fclean all

.PHONY: all clean fclean re


# CC := gcc
# NA := nasm
# FLAGS := -f macho64

# NAME := libfts.a

# DIR_SRC_LIB := src
# DIR_OBJ_LIB := .obj

# ITE_LIB :=	char_table \
# 			char_type \
# 			ft_bzero \
# 			ft_isalnum \
# 			ft_isalpha \
# 			ft_isascii \
# 			ft_isprint \
# 			ft_isdigit \
# 			ft_isspace \
# 			ft_isblank \
# 			ft_tolower \
# 			ft_toupper \
# 			ft_puts \
# 			ft_strlen \
# 			ft_strcat \
# 			ft_memset \
# 			ft_memcpy \
# 			ft_strdup \
# 			ft_cat \
# 			ft_putchar \
# 			ft_putchar_fd

# SRC_LIB := $(patsubst %, $(DIR_SRC_LIB)/%.s, $(ITE_LIB))
# OBJ_LIB := $(patsubst %, $(DIR_OBJ_LIB)/%.o, $(ITE_LIB))

# .PHONY: all clean fclean re

# all: $(NAME)

# #####################################_LIB_######################################

# $(DIR_OBJ_LIB)/%.o: $(DIR_SRC_LIB)/%.s
# 	mkdir -p $(DIR_OBJ_LIB)
# 	$(NA) $(FLAGS) -o $@ $<

# $(NAME): $(OBJ_LIB)
# 	ar rcs $(NAME) $(OBJ_LIB)
# 	ranlib $(NAME)

# #####################################_OTHER_#####################################

# clean:
# 	/bin/rm -rf $(DIR_OBJ_LIB)

# fclean: clean
# 	/bin/rm -f $(NAME)

# re: fclean all
