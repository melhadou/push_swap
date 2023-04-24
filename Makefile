SRC = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror # -g -fsanitize=address
INC = -Iincludes
SRC_DIR = src/
SRC_FILES = main.c lst_utils.c ft_funcs.c utils.c sorting_algo.c
CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(CFILES:%.c=%.o)

all: $(SRC)

# Linker
$(SRC): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(SRC)

# compiling
%.o : %.c 
	$(CC) $(CFLAGS) -c $(INC) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	rm -rf $(SRC)

re: fclean all
