#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -w

DEF_COLOR		=	\033[0;39m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m

all: $(NOM)

start_msg:
	@printf "$(YELLOW)Compiling $(NOM)...$(DEF_COLOR)"

$(NOM):	start_msg $(OBJ)
	@ar -rc $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "\r$(GREEN)$(NOM) (MacOS) ready$(DEF_COLOR)"

%.o:	%.c
	@cc $(CFLAGS) -c $^ -o $@

%.o:	%.m
	@cc $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
