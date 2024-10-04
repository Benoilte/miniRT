# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 12:49:52 by bgolding          #+#    #+#              #
#    Updated: 2024/10/04 08:48:19 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libdlist.a

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/

DBL_LST_SRC	=	dbl_lstnew dbl_lstiter dbl_lstclear dbl_lstdelone \
				dbl_lstadd_back dbl_lstadd_front dbl_lstadd_ordered \
				dbl_lstadd_before dbl_lstadd_after dbl_lstlast \
				dbl_lstsize dbl_lstgetone dbl_lstmove_back

SRCS		=	$(addprefix $(SRC_DIR)dbl_list/, $(addsuffix .c, $(DBL_LST_SRC)))

OBJS		=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
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
				@printf "\r$(YELLOW)[$(COMPILED_COUNT)/$(TOTAL_FILES)] Compiling $(NAME) files$(DEF_COLOR)"
				@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
			@$(RM) -rf $(OBJ_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
