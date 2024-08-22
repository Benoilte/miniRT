# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 12:49:52 by bgolding          #+#    #+#              #
#    Updated: 2024/08/22 09:24:57 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libdlist.a

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/

DBL_LST_SRC	=	dbl_lstnew dbl_lstiter dbl_lstclear dbl_lstdelone \
				dbl_lstadd_back dbl_lstadd_front dbl_lstadd_ordered \
				dbl_lstadd_before dbl_lstadd_after dbl_lstlast \
				dbl_lstsize dbl_lstgetone

SRCS		=	$(addprefix $(SRC_DIR)dbl_list/, $(addsuffix .c, $(DBL_LST_SRC)))

OBJS		=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar -rc

DEFAULT		=	\033[0m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m

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
