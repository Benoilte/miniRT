# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 12:49:52 by bgolding          #+#    #+#              #
#    Updated: 2024/08/28 00:19:32 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libgraphic.a

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/

TUPLE_SRC	=	error vector point equal add subtract negate multiply divide \
				magnitude normalize dot_product cross_product reflect

COLOR_SRC 	=	rgb_new rgb_equal rgb_destroy rgb_conversion rgb_add \
				rgb_subtract rgb_scale rgb_multiply rgb_blend error

MATRIX_SRC	=	error init equal multiply identity transpose submatrix \
				determinant cofactor inversion translation scaling reflection \
				rotation shearing

MATH_SRC	=	equalf fsquaref angle_conversions

SRCS		=	$(addprefix $(SRC_DIR)tuples/, $(addsuffix .c, $(TUPLE_SRC))) \
				$(addprefix $(SRC_DIR)colors/, $(addsuffix .c, $(COLOR_SRC))) \
				$(addprefix $(SRC_DIR)matrix/, $(addsuffix .c, $(MATRIX_SRC))) \
				$(addprefix $(SRC_DIR)math_utils/, $(addsuffix .c, $(MATH_SRC)))

OBJS		=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar -rc

DEFAULT		=	\033[0m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
CLEAR_LINE	=	\033[2K

TOTAL_FILES		=	$(words $(SRCS))
COMPILED_COUNT	=	0

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $@ $(OBJS)
			@printf "$(CLEAR_LINE)"
			@echo "\r$(GREEN)$(NAME) compiled$(DEFAULT)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@$(eval COMPILED_COUNT=$(shell echo $$(($(COMPILED_COUNT) + 1))))
				@printf "\r$(YELLOW)[$(COMPILED_COUNT)/$(TOTAL_FILES)] Compiling libgraphic files$(DEF_COLOR)"
				@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
			@$(RM) -rf $(OBJ_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
