# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 11:21:21 by bgolding          #+#    #+#              #
#    Updated: 2024/10/07 17:41:41 by bgolding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TRUE_NAME			=	miniRT_bonus
NAME				=	$(addprefix ../, $(TRUE_NAME))

LIB					=	../lib/
SRC_DIR				=	src/
OBJ_DIR				=	obj/
INC_DIR				=	inc/
COMMON_INC_DIR		=	../inc/
LIBFT_DIR 			=	$(LIB)libft/
MINILIBX_DIR		=	$(LIB)mlx/
LIBGRAPHIC_DIR		=	$(LIB)libgraphic/
LIBDLIST			=	$(LIB)libdlist/

MAIN_FILES			=	main
ERROR_FILES			=	error input_error
PARSING_FILES		=	file_validation lexer tokenize token_utils parser validate_single_element_1 \
						validate_shape validate_info_1 validate_info_2 validate_utils validate_bonus \
						validate_bonus_info_1 validate_bonus_info_2 validate_single_element_2
DATA_FILES			=	init_data destroy_data init_world destroy_world init_input destroy_input init_utils \
						init_render destroy_render
WINDOW_FILES		=	init_mlx
HOOKS_FILES			=	hooks keypress mouse
REFRACTION_FILES	=	refraction shape_containers_utils init_shape_containers destroy_shape_containers \
						reset_shape_containers
RENDERING_FILES		=	render draw_utils view_transform camera intersect_world color_at reflection \
						multi_threading multi_threading_utils shadow
INTERSECT_FILES		=	clear_intersection hit_intersection new_intersection details_intersection utils
RAY_FILES			=	ray position transform
SHAPE_FILES			=	init_shapes shape error material normal shape_bonus \
						sphere sphere_intersect sphere_normal \
						plane plane_intersect plane_normal \
						cylinder cylinder_intersect cylinder_normal cylinder_intersect_caps
LIGHT_FILES			=	new_light destroy_light lighting
TEST_FILES			=	print print_utils time reflection_and_refraction reflection_and_refraction_utils

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
									$(COMMON_INC_DIR) \
									$(MINILIBX_DIR) \
									$(LIBFT_DIR)inc \
									$(LIBGRAPHIC_DIR)inc \
									$(LIBDLIST)inc)

SRC_FILES		=	$(addprefix main/, $(MAIN_FILES)) \
					$(addprefix error/, $(ERROR_FILES)) \
					$(addprefix parsing/, $(PARSING_FILES)) \
					$(addprefix data/, $(DATA_FILES)) \
					$(addprefix window/, $(WINDOW_FILES)) \
					$(addprefix hooks/, $(HOOKS_FILES)) \
					$(addprefix refraction/, $(REFRACTION_FILES)) \
					$(addprefix rendering/, $(RENDERING_FILES)) \
					$(addprefix intersection/, $(INTERSECT_FILES)) \
					$(addprefix ray/, $(RAY_FILES)) \
					$(addprefix shape/, $(SHAPE_FILES)) \
					$(addprefix light/, $(LIGHT_FILES)) \
					$(addprefix test/, $(TEST_FILES))

SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

LIB_LINK		=	-L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -L$(LIBGRAPHIC_DIR) -lgraphic -L$(LIBDLIST) -ldlist $(OS_FLAGS)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -pthread -O2
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

$(STATIC_LIBS):
				@echo "$(YELLOW)Compiling static libraries...$(DEF_COLOR)"
				@make -C $(MINILIBX_DIR)
				@make -C $(LIBFT_DIR)
				@make -C $(LIBGRAPHIC_DIR)
				@make -C $(LIBDLIST)
				@echo "$(GREEN)All static libraries compiled$(DEF_COLOR)"

$(NAME):		$(STATIC_LIBS) $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) $(LIB_LINK) -o $@
				@printf "$(CLEAR_LINE)"
				@echo "\r$(GREEN)Successfully created executable: $(TRUE_NAME) $(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@$(eval COMPILED_COUNT=$(shell echo $$(($(COMPILED_COUNT) + 1))))
				@printf "\r$(YELLOW)[$(COMPILED_COUNT)/$(TOTAL_FILES)] Compiling $(TRUE_NAME) files$(DEF_COLOR)"
				@$(CC) $(CFLAGS) $(INC_PATHS) -c $< -o $@

clean:
				@$(RM) -rf $(OBJ_DIR)
				@make clean -C $(LIBFT_DIR)
				@make clean -C $(LIBGRAPHIC_DIR)
				@make clean -C $(LIBDLIST)
				@echo "$(YELLOW)clean complete $(DEF_COLOR)"

fclean:			clean fcleanlibs
				@$(RM) $(NAME)
				@echo "$(YELLOW)fclean complete $(DEF_COLOR)"

fcleanlibs:
				@make clean -C $(MINILIBX_DIR)
				@make fclean -C $(LIBFT_DIR)
				@make fclean -C $(LIBGRAPHIC_DIR)
				@make fclean -C $(LIBDLIST)

re:				fclean all

libft:
				@make -C $(LIBFT_DIR)

libgraphic:
				@make -C $(LIBGRAPHIC_DIR)

libdlist:
				@make -C $(LIBDLIST)

mlx:
				@make -C $(MINILIBX_DIR)

.PHONY:			all clean fclean re fcleanlibs libft libgraphic libdlist mlx
