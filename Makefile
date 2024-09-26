# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 14:03:36 by bebrandt          #+#    #+#              #
#    Updated: 2024/09/25 14:28:48 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY_DIR	=	mandatory/
BONUS_DIR		=	bonus/

LIB				=	lib/
LIBFT_DIR 		=	$(LIB)libft/
MINILIBX_DIR	=	$(LIB)mlx/
LIBGRAPHIC_DIR	=	$(LIB)libgraphic/
LIBDLIST		=	$(LIB)libdlist/

# Mandatory rules

all:
				@make all -C $(MANDATORY_DIR) --no-print-directory

clean:
				@make clean -C $(MANDATORY_DIR) --no-print-directory

fclean:
				@make fclean -C $(MANDATORY_DIR) --no-print-directory

re:				fclean all

# bonus rules

bonus:
				@make all -C $(BONUS_DIR) --no-print-directory

cleanbonus:
				@make clean -C $(BONUS_DIR) --no-print-directory

fcleanbonus:
				@make fclean -C $(BONUS_DIR) --no-print-directory

rebonus:		fcleanbonus bonus

# Common rules

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

.PHONY:			all clean fclean re bonus cleanbonus fcleanbonus rebonus \
				fcleanlibs libft libgraphic libdlist mlx
