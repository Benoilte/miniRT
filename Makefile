# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 11:21:21 by bgolding          #+#    #+#              #
#    Updated: 2024/09/05 11:05:03 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT

NAME_TEST		=	test_miniRT

LIB				=	lib/
INC				=	inc/
SRC_DIR			=	src/
OBJ_DIR			=	obj/
INC_DIR			=	inc/
LIBFT_DIR 		=	$(LIB)libft/
MINILIBX_DIR	=	$(LIB)mlx/
LIBGRAPHIC_DIR	=	$(LIB)libgraphic/
LIBDLIST		=	$(LIB)libdlist/

MAIN_FILES		=	main
TEST_FILES		=	test default_world first_scene shadow
ERROR_FILES		=	error
DATA_FILES		=	init_data destroy_data init_world destroy_world
WINDOW_FILES	=	init_mlx
HOOKS_FILES		=	hooks keypress mouse
RENDERING_FILES	=	render draw_utils view_transform camera intersect_world color_at
INTERSECT_FILES	=	clear_intersection hit_intersection new_intersection details_intersection utils
RAY_FILES		=	ray position transform
SHAPE_FILES		=	shape error material sphere sphere_intersect sphere_normal normal
LIGHT_FILES		=	new_light destroy_light lighting

# OS specific settings
UNAME_S			=	$(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MINILIBX_DIR	:=	$(addsuffix Linux/, $(MINILIBX_DIR))
	OS_FLAGS		:=	-lXext -lX11 -lm
	WINDOW_FILES	+=	destroy_mlx_linux close_linux
else ifeq ($(UNAME_S), Darwin)
	MINILIBX_DIR	:=	$(addsuffix MacOS/, $(MINILIBX_DIR))
	OS_FLAGS		:=	-framework OpenGL -framework AppKit
	WINDOW_FILES	+=	destroy_mlx_macos close_macos
else
	$(error OS not supported)
	exit 1
endif

STATIC_LIBS		=	$(LIBFT_DIR)libft.a \
					$(MINILIBX_DIR)libmlx.a \
					$(LIBGRAPHIC_DIR)libgraphic.a \
					$(LIBDLIST)libdlist.a

INC_PATHS		=	$(addprefix -I, $(INC_DIR) \
									$(MINILIBX_DIR) \
									$(LIBFT_DIR)inc \
									$(LIBGRAPHIC_DIR)inc \
									$(LIBDLIST)inc)

SRC_FILES		=	$(addprefix error/, $(ERROR_FILES)) \
					$(addprefix data/, $(DATA_FILES)) \
					$(addprefix window/, $(WINDOW_FILES)) \
					$(addprefix hooks/, $(HOOKS_FILES)) \
					$(addprefix rendering/, $(RENDERING_FILES)) \
					$(addprefix intersection/, $(INTERSECT_FILES)) \
					$(addprefix ray/, $(RAY_FILES)) \
					$(addprefix shape/, $(SHAPE_FILES)) \
					$(addprefix light/, $(LIGHT_FILES))

SRC_MAIN		=	$(addprefix main/, $(MAIN_FILES))

SRC_TEST		=	$(addprefix test/, $(TEST_FILES))


SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES) $(SRC_MAIN) $(SRC_TEST)))
OBJS			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJS_MAIN		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAIN)))
OBJS_TEST		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_TEST)))

LIB_LINK		=	-L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -L$(LIBGRAPHIC_DIR) -lgraphic -L$(LIBDLIST) -ldlist $(OS_FLAGS)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
AR				=	ar -r

MAKEFLAGS		=	--no-print-directory

DEF_COLOR		=	\033[0;39m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
CLEAR_LINE		=	\033[2K

TOTAL_FILES		=	$(words $(SRCS))
COMPILED_COUNT	=	0


all:			$(STATIC_LIBS) $(NAME)

test:			$(STATIC_LIBS) $(NAME_TEST)

$(STATIC_LIBS):
				@echo "$(YELLOW)Compiling static libraries...$(DEF_COLOR)"
				@make -C $(MINILIBX_DIR)
				@make -C $(LIBFT_DIR)
				@make -C $(LIBGRAPHIC_DIR)
				@make -C $(LIBDLIST)
				@echo "$(GREEN)All static libraries compiled$(DEF_COLOR)"

$(NAME):		$(OBJS) $(OBJS_MAIN) $(STATIC_LIBS)
				@$(CC) $(CFLAGS) $(OBJS) $(OBJS_MAIN) $(LIB_LINK) -o $@
				@printf "$(CLEAR_LINE)"
				@echo "\r$(GREEN)Successfully created executable: $(NAME) $(DEF_COLOR)"

$(NAME_TEST):	$(OBJS) $(OBJS_TEST) $(STATIC_LIBS)
				@$(CC) $(CFLAGS) $(OBJS) $(OBJS_TEST) $(LIB_LINK) -o $@
				@printf "$(CLEAR_LINE)"
				@echo "\r$(GREEN)Successfully created executable: $(NAME) $(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@$(eval COMPILED_COUNT=$(shell echo $$(($(COMPILED_COUNT) + 1))))
				@printf "\r$(YELLOW)[$(COMPILED_COUNT)/$(TOTAL_FILES)] Compiling $(NAME) files$(DEF_COLOR)"
				@$(CC) $(CFLAGS) $(INC_PATHS) -c $< -o $@

clean:
				@$(RM) -rf $(OBJ_DIR)
				@make clean -C $(LIBFT_DIR)
				@make clean -C $(LIBGRAPHIC_DIR)
				@make clean -C $(LIBDLIST)
				@echo "$(YELLOW)clean complete $(DEF_COLOR)"

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(NAME_TEST)
				@make clean -C $(MINILIBX_DIR)
				@make fclean -C $(LIBFT_DIR)
				@make fclean -C $(LIBGRAPHIC_DIR)
				@make fclean -C $(LIBDLIST)
				@echo "$(YELLOW)fclean complete $(DEF_COLOR)"

re:				fclean all

retest:				fclean test

libft:
				@make -C $(LIBFT_DIR)

libgraphic:
				@make -C $(LIBGRAPHIC_DIR)

libdlist:
				@make -C $(LIBDLIST)

mlx:
				@make -C $(MINILIBX_DIR)

.PHONY:			all clean fclean re test retest
