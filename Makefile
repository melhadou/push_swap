NAME = push_swap
CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
LIBFT = libs/libft
GNL = libs/getnextline

# ************************* Header Files and Libs PART **************************

INC = -Iincludes
LIBS = $(addprefix $(LIBFT), /libft.a)

# ************************* FIlES PART **************************

SRC_DIR = src/
SRC_FILES = main.c

SORTING_DIR= $(SRC_DIR)sorting/
SORTING_FILES = sort_five.c sort_four.c sort_others.c sort_three.c sort_utils.c
SORTING_FILES += push_instructions.c rotate_instructions.c reverse_rotate_instructions.c swap_instructions.c 

UTILS_DIR = $(SRC_DIR)utils/
UTILS_FILES = helper_funcs.c init_stack.c errors.c ft_free.c ft_tweaks.c lst_utils.c

CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))
CFILES += $(addprefix $(UTILS_DIR), $(UTILS_FILES))
CFILES += $(addprefix $(SORTING_DIR), $(SORTING_FILES))


# ************************* BONUS FILES PART **************************

BONUS = checker
BNS_FILES = bonus/checker.c src/sorting/push_instructions.c src/sorting/rotate_instructions.c \
						src/sorting/reverse_rotate_instructions.c src/sorting/swap_instructions.c \
						src/sorting/sort_utils.c
BNS_FILES += $(addprefix $(UTILS_DIR), $(UTILS_FILES))

# *************************  PATTERN SUBSTITUTION PART **************************

OBJ = $(CFILES:%.c=%.o)
OBJ_BONUS = $(BNS_FILES:%.c=%.o)

# *************************  RULES PART **************************

all: libft $(NAME)

libft:
	@echo "Making Libft"
	@cd $(LIBFT) && make

gnl:
	@echo "Making GetNextLine"
	@cd $(GNL) && make

bonus: gnl $(BONUS)

# *************************  LINKING PART **************************

$(BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(INC) $(OBJ_BONUS) $(LIBS) libs/getnextline/gnl.a -o $(BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBS) -o $(NAME)

# *************************  COMPILING PART **************************

%.o : %.c 
	$(CC) $(CFLAGS) -c $(INC) $< -o $@

# *************************  CLEANING PART **************************

clean:
	@cd $(LIBFT) && make clean
	@cd $(GNL) && make clean
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean: clean
	@cd $(GNL) && make fclean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re: fclean all

.PHONY: all bonus gnl libft clean fclean
