RED     =   \033[38;5;161m
GREEN   =   \033[38;5;154m
YELLOW  =   \033[38;5;227m
BLUE    =   \033[38;5;81m
PURPLE  =   \033[38;5;93m
PINK    =   \033[38;5;219m
NC      =   \033[0m

C = clang
NAME = fdf
LIB = libft/libft.a
MLX = minilibx/libmlx.a
FLAGS = -Wall -Wextra -Werror -O3
LIBFT = libft
DIR_O = temp
DIR_MLX = minilibx
HEADERS = includes

SOURCES = fdf.c shapes.c utils.c colors.c movements.c hooks.c

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: temp make_lib make_mlx $(NAME)

$(NAME): $(OBJS) $(LIB) $(MLX)
	$(C) -L $(LIBFT) -lft -o $@ $^ -framework OpenGL -framework AppKit -lm -L $(DIR_MLX) -lmlx 
	@#-fsanitize="address,undefined" -g
	@echo "$(PURPLE)=====FDF COMPILED=====$(NC)"

make_lib:
	@$(MAKE) -C $(LIBFT) --no-print-directory

make_mlx:
	@$(MAKE) -C $(DIR_MLX) --no-print-directory

temp:
	@mkdir -p temp

$(DIR_O)/%.o: %.c $(NAME).h $(LIB) $(MLX)
	$(C) -I $(HEADERS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT) --no-print-directory
	@make clean -C $(DIR_MLX) --no-print-directory
	@rm -rf $(DIR_O)
	@echo "$(RED)FDF OBJ DELETED$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT) --no-print-directory
	@make fclean -C $(DIR_MLX) --no-print-directory
	@echo "$(RED)FDF ALL DELETED$(NC)"

re: fclean all