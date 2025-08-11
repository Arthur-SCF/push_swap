NAME		= libftprintf.a
PROG		= test_printf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
DEBUG_FLAGS	= -g3 -fsanitize=address
RM			= rm -f

# Directories
SRCS_DIR	= srcs/
LIBFT_DIR	= libft/
INC_DIR		= includes/
OBJS_DIR	= objs/

# Source files
SRCS		= $(SRCS_DIR)ft_printf.c \
			$(SRCS_DIR)format.c \
			$(SRCS_DIR)convertions/convert_char.c \
			$(SRCS_DIR)convertions/convert_str.c \
			$(SRCS_DIR)convertions/convert_ptr.c \
			$(SRCS_DIR)convertions/convert_int.c \
			$(SRCS_DIR)convertions/convert_uint.c \
			$(SRCS_DIR)convertions/convert_hex.c \
			$(SRCS_DIR)utils/int_utils.c \
			$(SRCS_DIR)utils/ptr_utils.c \
			$(SRCS_DIR)utils/hex_utils.c

# Object files
OBJS		= $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

# Libft
LIBFT		= $(LIBFT_DIR)libft.a

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) -rf $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean:		clean
	$(RM) $(NAME) $(PROG)
	make fclean -C $(LIBFT_DIR)

re:			fclean all

bonus:		all

norminette:
	norminette ./

# Add main rule
main:		$(NAME)
	$(CC) $(CFLAGS) -I$(INC_DIR) main.c $(NAME) -o $(PROG)
	./$(PROG)

debug:		fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)"
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -I$(INC_DIR) main.c $(NAME) -o $(PROG)

.PHONY:		all clean fclean re main debug