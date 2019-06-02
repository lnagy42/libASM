
CC := gcc

NAME := main
LIBASM := ../libft.a

SRC_DIR := src
OBJ_DIR := .obj
INC_DIR := include

ITE_SRC :=	main \
		error \
		get \
		compare \
		run_tests \
		ut_is \
		ut_strlen \
		ut_bzero \
		ut_strdup \
		ut_strcat \
		ut_memset \
		ut_memcpy \
		ut_puts \
		ut_putchar \
		ut_putchar_fd \
		ut_putstr \
		ut_putstr_fd \
		ut_cat \
		ut_memalloc

ITE_INC :=	include

SRCS := $(patsubst %, $(SRC_DIR)/%.c, $(ITE_SRC))
OBJS := $(patsubst %, $(OBJ_DIR)/%.o, $(ITE_SRC))
INCS := $(patsubst %, $(INC_DIR)/%.h, $(ITE_INC))

all: $(NAME)

#####################################_MAIN_#####################################

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBASM) -I $(INC_DIR) -o $@

#####################################_OTHER_#####################################

clean:
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	/bin/rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
