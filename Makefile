NAME = fdf

SRC_PATH = ./sources/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
LIB_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
INC_LIB = $(addprefix -I, $(INC_PATH))

SRC_NAME =	ft_draw.c			\
			ft_exit.c			\
			ft_free.c			\
			ft_hooks.c			\
			ft_init.c			\
			ft_main.c			\
			ft_safe_malloc.c	\
			ft_validation.c		\

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make lib_refresh
	@gcc -g -Wall -Wextra -Werror -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) -lft -l mlx -framework OpenGL -framework AppKit
	 
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(INC) -o $@ -c $^


lib_refresh:
	@make -C $(LIB_PATH)

norm:
	@echo "$(YELLOW)"
	@norminette -R CheckForbiddenSourceHeader

clean:
	@clear
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re: fclean all