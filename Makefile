NAME 	= minishell
CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
AR 		= ar
ARFLAGS = rcs
RM 		= rm -fr

LIBFT_DIR 	= libft
LIBFT 		= $(LIBFT_DIR)/libft.a
INC_DIR		= includes
SRC_DIR		= src


SRC	 =

OBJS = $(SRC:.c=.o)

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

RE: fclean all

.PHONY: all clean fclean re