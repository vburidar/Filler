NAME = vburidar.filler

SRC = main.c\
	  ft_get_data.c\
	  ft_resize_piece.c\
	  ft_add_position.c\
	  ft_free_tab.c\
	  ft_middle_tab.c\
	  ft_print_result.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C LIBFT
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -L. LIBFT/libft.a

$(FT_PRINTF):
	make all -C LIBFT

%.o : %.c
	gcc -o $@ -c $< -g -Wall -Wextra -Werror

clean :
	rm -rf *.o
	make clean -C LIBFT

fclean : clean 
	rm -rf $(NAME)
	make fclean -C LIBFT

re :	
	make fclean
	make
