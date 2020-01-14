cmake_minimum_required(VERSION 3.14)
project(fractol C)

set(CMAKE_C_STANDARD 11)

find_package(OpenCL REQUIRED)

include_directories(libft minilibx srcs srcs/control)

add_library(libmlx STATIC
        minilibx/mlx_init.c
        minilibx/mlx_new_window.c
        minilibx/mlx_pixel_put.c
        minilibx/mlx_loop.c
        minilibx/mlx_mouse_hook.c
        minilibx/mlx_key_hook.c
        minilibx/mlx_expose_hook.c
        minilibx/mlx_loop_hook.c
        minilibx/mlx_int_anti_resize_win.c
        minilibx/mlx_int_do_nothing.c
        minilibx/mlx_int_wait_first_expose.c
        minilibx/mlx_int_get_visual.c
        minilibx/mlx_flush_event.c
        minilibx/mlx_string_put.c
        minilibx/mlx_new_image.c
        minilibx/mlx_get_data_addr.c
        minilibx/mlx_put_image_to_window.c
        minilibx/mlx_get_color_value.c
        minilibx/mlx_clear_window.c
        minilibx/mlx_xpm.c
        minilibx/mlx_int_str_to_wordtab.c
        minilibx/mlx_destroy_window.c
        minilibx/mlx_int_param_event.c
        minilibx/mlx_int_set_win_event_mask.c
        minilibx/mlx_hook.c
        minilibx/mlx_rgb.c
        minilibx/mlx_destroy_image.c)

add_library(libft STATIC
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_lstadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strjoinfree.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/libft.h
        libft/ft_atoi_base.c
        libft/percentage.c)

add_executable(fractol
        srcs/init_params/create_cl_kernel.c
        srcs/control/control.h
        srcs/control/push_control.c
        srcs/control/push_key.c
        srcs/control/push_mouse.c
        srcs/main.c srcs/init_params/cl_init.c srcs/fractol.h srcs/init_params/mlx_params.c srcs/init_params/init_params.c srcs/init_params/read_cl_src.c srcs/init_params/cl_buffer.c srcs/init_params/set_cl_args.c srcs/draw.c srcs/mandelbrot/init_maldelbrot.c srcs/julia/init_julia.c srcs/init_params/error.c srcs/burning_ship/init_burning_ship.c srcs/multi-julia/init_multi_julia.c srcs/init_params/usage.c)

add_compile_options(-Wall -Werror -Wextra)

target_link_libraries(fractol libmlx "-lOpenGL" -lX11 -lm -lXext -lOpenCL libft)