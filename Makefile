NAME 	= minishell
CC 		= cc
DEBUG_VERBOSE ?= 0
DEBUG_FLAGS = -g3 -DDEBUG_VERBOSE=$(DEBUG_VERBOSE)
CFLAGS 	= -Wall -Wextra -Werror

AR 		= ar
ARFLAGS = rcs
RM 		= rm -fr

LIBFT_DIR 	= libft
LIBFT 		= $(LIBFT_DIR)/libft.a
INC_DIR		= includes
SRC_DIR		= src

SRC	 = cmd_utils.c expander.c ft_shell.c lexer.c main.c parser.c debug_helper_functions.c ft_execute.c get_cmd_list.c lexer_utils.c new_token.c syntax.c ft_strndup.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR)
LIBS		= -lreadline

all: $(LIBFT) $(NAME)
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)

src/%.o: src/%.c $(INC_DIR)/minishell.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: test
test: DEBUG_VERBOSE = 1
test: CFLAGS := $(CFLAGS) $(DEBUG_FLAGS)
#test: DEBUG_FLAGS = -g3 -DDEBUG_VERBOSE=1
test: re

.PHONY: all clean fclean re test