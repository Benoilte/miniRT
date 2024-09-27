# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 14:03:36 by bebrandt          #+#    #+#              #
#    Updated: 2024/09/26 16:02:16 by bgolding         ###   ########.fr        #
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

# Mandatory rules

$(NAME):		mandatory

mandatory:		
				@make all -C $(MANDATORY_DIR) --no-print-directory

clean:
				@make clean -C $(MANDATORY_DIR) --no-print-directory

fclean:
				@make fclean -C $(MANDATORY_DIR) --no-print-directory

re:				fclean mandatory

# bonus rules

$(NAME_BONUS):	bonus

bonus:
				@make all -C $(BONUS_DIR) --no-print-directory

cleanbonus:
				@make clean -C $(BONUS_DIR) --no-print-directory

fcleanbonus:
				@make fclean -C $(BONUS_DIR) --no-print-directory

rebonus:		fcleanbonus bonus

# Common rules

all:			$(NAME) $(NAME_BONUS)

cleanall:		clean cleanbonus

fcleanall:		fclean fcleanbonus

reall:			fcleanall all

fcleanlibs:
				@make clean -C $(MINILIBX_DIR) --no-print-directory
				@make fclean -C $(LIBFT_DIR) --no-print-directory
				@make fclean -C $(LIBGRAPHIC_DIR) --no-print-directory
				@make fclean -C $(LIBDLIST) --no-print-directory


libft:
				@make -C $(LIBFT_DIR) --no-print-directory

libgraphic:
				@make -C $(LIBGRAPHIC_DIR) --no-print-directory

libdlist:
				@make -C $(LIBDLIST) --no-print-directory

mlx:
				@make -C $(MINILIBX_DIR) --no-print-directory

.PHONY:			mandatory clean fclean re \
				bonus cleanbonus fcleanbonus rebonus \
				all cleanall fcleanall reall \
				fcleanlibs libft libgraphic libdlist mlx
