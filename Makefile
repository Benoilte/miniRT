# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 14:03:36 by bebrandt          #+#    #+#              #
#    Updated: 2024/10/28 11:54:18 by bgolding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT
NAME_BONUS		=	miniRT_bonus

MANDATORY_DIR	=	mandatory/
BONUS_DIR		=	bonus/

LIB				=	lib/
LIBFT_DIR 		=	$(LIB)libft/
MINILIBX_DIR	=	$(LIB)mlx/
LIBGRAPHIC_DIR	=	$(LIB)libgraphic/
LIBDLIST		=	$(LIB)libdlist/

UNAME_S			=	$(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MINILIBX_DIR	:=	$(addsuffix Linux/, $(MINILIBX_DIR))
else ifeq ($(UNAME_S), Darwin)
	MINILIBX_DIR	:=	$(addsuffix MacOS/, $(MINILIBX_DIR))
else
	$(error OS not supported)
	exit 1
endif

MAKEFLAGS		=	--no-print-directory

# Mandatory rules

$(NAME):		mandatory

mandatory:		
				@make all -C $(MANDATORY_DIR)

clean:
				@make clean -C $(MANDATORY_DIR)

fclean:
				@make fclean -C $(MANDATORY_DIR)

re:				fclean mandatory

# bonus rules

$(NAME_BONUS):	bonus

bonus:
				@make all -C $(BONUS_DIR)

cleanbonus:
				@make clean -C $(BONUS_DIR)

fcleanbonus:
				@make fclean -C $(BONUS_DIR)

rebonus:		fcleanbonus bonus

# Common rules

all:			$(NAME) $(NAME_BONUS)

cleanall:		clean cleanbonus

fcleanall:		fclean fcleanbonus

reall:			fcleanall all

fcleanlibs:
				@make clean -C $(MINILIBX_DIR)
				@make fclean -C $(LIBFT_DIR)
				@make fclean -C $(LIBGRAPHIC_DIR)
				@make fclean -C $(LIBDLIST)


libft:
				@make -C $(LIBFT_DIR)

libgraphic:
				@make -C $(LIBGRAPHIC_DIR)

libdlist:
				@make -C $(LIBDLIST)

mlx:
				@make -C $(MINILIBX_DIR)

.PHONY:			mandatory clean fclean re \
				bonus cleanbonus fcleanbonus rebonus \
				all cleanall fcleanall reall \
				fcleanlibs libft libgraphic libdlist mlx
