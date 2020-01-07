NAME = fractol
SRCS = ./srcs/burning_ship/init_burning_ship.c \
	./srcs/control/push_control.c \
	./srcs/control/push_key.c \
	./srcs/control/push_mouse.c \
	./srcs/draw.c \
	./srcs/init_params/cl_buffer.c \
	./srcs/init_params/cl_init.c \
	./srcs/init_params/create_cl_kernel.c \
	./srcs/init_params/error.c \
	./srcs/init_params/init_params.c \
	./srcs/init_params/mlx_params.c \
	./srcs/init_params/read_cl_src.c \
	./srcs/init_params/set_cl_args.c \
	./srcs/init_params/usage.c \
	./srcs/julia/init_julia.c \
	./srcs/main.c \
	./srcs/mandelbrot/init_maldelbrot.c \
	./srcs/multi-julia/init_multi_julia.c 

CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./libft/ \
	-I./minilibx_macos/ \
	-I./srcs/control/ \
	-I./srcs/ 

LIBSINC = -L./libft/ \
	-L./minilibx_macos/ 

LIBFTPATH = ./libft/
MINILIBXPATH = ./minilibx_macos/

LIBS = -lft \
	-lmlx 

LIBSNAME = libft.a \
	libmlx.a 

INCNAME = ./srcs/control/control.h  \
	./srcs/fractol.h


all: $(NAME)

%.o: %.c $(INCNAME)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFTPATH)
	@$(MAKE) -C $(MINILIBXPATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBSINC) $(LIBS) -framework OpenGL -framework AppKit -framework OpenCL

clean:
	$(MAKE) fclean -C $(LIBFTPATH)
	$(MAKE) clean -C $(MINILIBXPATH)
	/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

