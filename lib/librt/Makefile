# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 12:49:52 by bgolding          #+#    #+#              #
#    Updated: 2024/08/16 17:06:35 by bgolding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	librt.a

SRC_DIR	=	src/
OBJ_DIR	=	obj/
INC_DIR	=	inc/

TUPLE_SRC	=	error vector point equal add subtract negate multiply divide \
				magnitude normalize dot_product cross_product

COLOR_SRC 	=	rgb_conversion rgb_add rgb_subtract rgb_scale rgb_multiply \
				rgb_blend

MATRIX_SRC	=	error init equal multiply identity transpose submatrix \
				determinant cofactor inversion translation scaling reflection \
				rotation shearing

MATH_SRC	=	equalf fsquaref angle_conversions

RAY_SRC		=	ray position

SHAPE_SRC	=	error shape
			
SRCS	=	$(addprefix $(SRC_DIR)tuples/, $(addsuffix .c, $(TUPLE_SRC))) \
			$(addprefix $(SRC_DIR)colors/, $(addsuffix .c, $(COLOR_SRC))) \
			$(addprefix $(SRC_DIR)matrix/, $(addsuffix .c, $(MATRIX_SRC))) \
			$(addprefix $(SRC_DIR)math_utils/, $(addsuffix .c, $(MATH_SRC))) \
			$(addprefix $(SRC_DIR)ray/, $(addsuffix .c, $(RAY_SRC))) \
			$(addprefix $(SRC_DIR)shape/, $(addsuffix .c, $(SHAPE_SRC)))

OBJS	=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
AR		=	ar -rc

DEFAULT			=	\033[0m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $@ $(OBJS)
			@echo "$(GREEN)\t$(NAME) compiled$(DEFAULT)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(YELLOW).$(DEFAULT)"
				@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(RED)##### Removed librt object files #####$(DEFAULT)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)##### Removed librt archive file #####$(DEFAULT)"

re:			fclean all

.PHONY:		all clean fclean re