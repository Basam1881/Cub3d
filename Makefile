PURPLE = \033[1;35m
BLUE   = \033[1;34m
WHITE   = \033[1;37m
LIGHT_BLUE  = \033[1;36m
GREEN    = \033[1;32m
RED = \033[1;31m
BYELLOW  = \033[1;33m
IYELLOW  = \033[3;33m
NO_COLOR    = \033[m

OS = $(shell uname)
ifeq (${OS},Darwin)
	OP = mac
	MOUSE = -D MOUSE_FLAG=0
else
	OP = linux
	MOUSE = -D MOUSE_FLAG=1
endif


#Mention the Authors names over here
AUTHORS = Bnaji AND Mmekky

#mention the Team name here
TEAM_NAME =  $(BLUE)ᕙ(🔥 ︹ ́🔥)ᕗ$(BYELLOW)  CubMB  $(BLUE)(ง ͡▀̿ ̿  ͟ʖ͡▀̿ ̿  )ง$(GREEN)

#mention the project name here
PROJECT_NAME = CUB3D

#write down the date you started working on your project
DATE = 20 - 03 - 2022

C_FILES =  $(PRS_NAME) $(MINIMAP_NAME) $(KEY_HANDLER_NAME)\
			$(DISPLAY_MAIN_SCREEN_NAME) $(MAIN_NAME) $(SPRITES_NAME)

PRS_FILES = parser.c elements_parser.c parser_checks.c\
			file_pos_atoi.c ft_strdup_2_space.c map_parser.c\
			map_allocation.c is_valid_file.c is_map_char_allowed.c

MINIMAP_FILES =  minimap.c minimaps_player.c fm.c\
				draw_fm_rays.c fm_colors.c visible_fm.c\
				minimaps_plotter.c fm_rays_sender.c\
				draw_fm_board.c minimap_elements_effects.c\

KEY_HANDLER_FILES = keyhooks.c mousehooks.c move.c\
					look_back.c look_back_rotation.c\
					look_back_regions.c door_switch.c\
					collectables_check.c rotate.c\
					portal.c portal2.c portal_valid.c\

DISPLAY_MAIN_SCREEN_FILES = map.c raycast.c fc.c wall_hit.c\
							draw_shooting_elements.c plot_fc.c\
							screen_update.c

MAIN_FILES = main.c ft_exit.c init.c

SPRITES_FILES = moving_sprites.c sprites.c init_sprite.c\
				youwin.c set_sprites_specs.c

PRS_NAME =  $(addprefix $(PRS_DIR), $(PRS_FILES))

MINIMAP_NAME = $(addprefix $(MINIMAP_DIR), $(MINIMAP_FILES))

KEY_HANDLER_NAME = $(addprefix $(KEYS_HANDLER_DIR), $(KEY_HANDLER_FILES))

DISPLAY_MAIN_SCREEN_NAME = $(addprefix $(DISPLAY_MAIN_SCREEN_DIR), $(DISPLAY_MAIN_SCREEN_FILES))

MAIN_NAME = $(addprefix $(MAIN_DIR), $(MAIN_FILES))

SPRITES_NAME = $(addprefix $(SPRITES_DIR), $(SPRITES_FILES))

#These are the .c files for your project
SRC_NAME =  $(addprefix $(SRC_DIR), $(C_FILES))

#These are the .o files that will be created for your project
OBJ_NAME = $(addprefix $(OBJ_DIR), ${C_FILES:%.c=%.o})

#mention the compilation flags here
CFLAGS = -Wall -Wextra -Werror -g

#Here is the libft directory
LIBFT_DIR = ./libft/

#Here is the libft library
LIBFT_LIB = libft.a

#Here are all the libraries you have created
LIBS = $(addprefix $(LIBS_DIR), *.a)

#Here is the the source directory for .c files of your project
SRC_DIR = ./src/

PRS_DIR = parse/

MINIMAP_DIR = minimap/

KEYS_HANDLER_DIR = keys_handler/

DISPLAY_MAIN_SCREEN_DIR = display_main_screen/

MAIN_DIR = main/

SPRITES_DIR = sprites/

MINILIBX_LINUX_DIR = ./minilibx-linux/

MINILIBX_MACOS_DIR = ./minilibx-macos/

#Here is the the objects directory for .c files of your project
OBJ_DIR = ./objs/

#Here is the headers directory
HEADERS_DIR = ./includes/

#Here is the libraries directory
LIBS_DIR = ./libraries/

#Here is the final library that contains all the objects files needed for this project
#ALL_LIBS = $(LIBS_DIR)$(NAME) $(LIBS_DIR)${LIBFT_LIB}

#Here is the name of the executable file
NAME = cub3d

CC = gcc

all: NAME

NAME: $(OP)


mac: header $(LIBFT_LIB) $(OBJ_NAME)
	@$(MAKE) --no-print-directory -C ./minilibx-macos
	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Minilibx Is Done\n$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(OBJ_NAME) -L ./libft -lft -L ./minilibx-macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Cub3d Is Ready\n$(NO_COLOR)"
	@echo "$(BYELLOW)⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡"
	@echo "$(BYELLOW)⚡\t\t\t\t\t\t\t\t\t$(BYELLOW)READY\t\t\t\t\t\t\t\t\t\t$(BYELLOW)⚡"
	@echo "$(BYELLOW)⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡$(NO_COLOR)"

linux: header $(LIBFT_LIB) $(OBJ_NAME)
	@$(MAKE) --no-print-directory -C ./minilibx-linux
	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Minilibx Is Done\n$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(OBJ_NAME) $(LIBS_DIR)$(LIBFT_LIB) -L ./minilibx-linux -lmlx -lm -lX11 -lXext -o $(NAME)
	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Cub3d Is Ready\n$(NO_COLOR)"
	@echo "$(BYELLOW)⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡"
	@echo "$(BYELLOW)⚡\t\t\t\t\t\t\t\t\t$(BYELLOW)READY\t\t\t\t\t\t\t\t\t\t$(BYELLOW)⚡"
	@echo "$(BYELLOW)⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡$(NO_COLOR)"

linux-debug: header $(LIBFT_LIB) $(OBJ_NAME)
	@$(MAKE) --no-print-directory -C ./minilibx-linux
	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Minilibx Is Done\n$(NO_COLOR)"
	@$(CC) $(CFLAGS) -g $(SRC_NAME) $(LIBS_DIR)$(LIBFT_LIB) -L ./minilibx-linux -lmlx -lm -lX11 -lXext -o $(NAME)
	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Cub3d Is Ready\n$(NO_COLOR)"
	@echo "$(BYELLOW)⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡"
	@echo "$(BYELLOW)⚡\t\t\t\t\t\t\t\t\t$(BYELLOW)READY\t\t\t\t\t\t\t\t\t\t$(BYELLOW)⚡"
	@echo "$(BYELLOW)⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡$(NO_COLOR)"

mac-debug: header ${LIBFT_LIB} $(OBJ_NAME)
	rm -rf libmlx.dylib
	@$(MAKE) --no-print-directory -C ./minilibx-macos && cp ./minilibx-macos/libmlx.dylib .
	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Minilibx Is Done\n$(NO_COLOR)"
	@$(CC) $(CFLAGS) -g $(SRC_NAME) -L ./libft -lft -L ./minilibx-macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Cub3d Is Ready\n$(NO_COLOR)"
	@echo "$(BYELLOW)⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡"
	@echo "$(BYELLOW)⚡\t\t\t\t\t\t\t\t\t$(BYELLOW)READY\t\t\t\t\t\t\t\t\t\t$(BYELLOW)⚡"
	@echo "$(BYELLOW)⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡$(NO_COLOR)"

${LIBFT_LIB}:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) all && cp $(LIBFT_DIR)$(LIBFT_LIB) $(LIBS_DIR)
	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)LIBFT Is Done\n$(NO_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@gcc ${CFLAGS} $(MOUSE) -c $< -o $@ -I libft

header:
	@printf "\n%b" "$(PURPLE)"
	@echo
	@echo "\t\t\t\t ▄████████ ███    █▄  ▀█████████▄    ▄▄▄▄███▄▄▄▄   ▀█████████▄ "
	@echo "\t\t\t\t███    ███ ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███"
	@echo "\t\t\t\t███    █▀  ███    ███   ███    ███ ███   ███   ███   ███    ███"
	@echo "\t\t\t\t███        ███    ███  ▄███▄▄▄██▀  ███   ███   ███  ▄███   ██▀ "
	@echo "\t\t\t\t███        ███    ███ ▀▀███▀▀▀██▄  ███   ███   ███ ▀▀███   ██▄ "
	@echo "\t\t\t\t███    █▄  ███    ███   ███    ██▄ ███   ███   ███   ███    ██▄"
	@echo "\t\t\t\t███    ███ ███    ███   ███    ███ ███   ███   ███   ███    ███"
	@echo "\t\t\t\t████████▀  ████████▀  ▄█████████▀   ▀█   ███   █▀  ▄█████████▀ "
	@echo
	@echo
	@printf "\n%b" "$(BYELLOW)"
	@echo "\t\t\t\t\t                     888.;@X8t;X"
	@echo "\t\t\t\t\t                   8SS% %%SX8%%.:S"
	@echo "\t\t\t\t\t                  S  S8X @8888:t% ;"
	@echo "\t\t\t\t\t                  .;:tS X  %@ t %t @"
	@echo "\t\t\t\t\t                    @;t%  X @X8 SS.t :;"
	@echo "\t\t\t\t\t                   X 8 ;t:   t;t@X%.%; @    S8@.  :X@%%@: "
	@echo "\t\t\t\t\t              ;8:.S8S;%@8:;tX%S;@8.X @X  888SX @X%   @  ;                                    /"
	@echo "\t\t\t\t\t          ..8;8S8 ;%X@  8;8t88%8:;..88@@88.8:X8.SS .;%t.Sttt;t;;;:;::::                    / /"
	@echo "\t\t\t\t\t          X@      @X  %SX;X8888X8X.8X  XS:@8.;@%@ 8SS%SSSSS%SSSSS%S%St@SSSSSX@@888888@@S@: --  -- -- -- -- -- ---->>"
	@echo "\t\t\t\t\t            .....:%.@X%S;..;       S@8X@ t;;%t888t S8@8888888@@@@SX8X.%                    \ \ "
	@echo "\t\t\t\t\t       ;8::;t;;;%@@X::;;t%SX@88.X   8S: X.@8XX %XXS;                                         \ "
	@echo "\t\t\t\t\t        ttSXXtSt%@@S     t88S@  S@ XX;@.@ 88@ @S  ;:"
	@echo "\t\t\t\t\t        ttSSt@S8XXSS@X@@;t;8%t:%88X:SS t88S@; X.:"
	@echo "\t\t\t\t\t      8;X%XSXt%t%X88X@S88;tXX@88t;8 8X@XXSXX."
	@echo "\t\t\t\t\t       8%8S8S@SSS8X88@Xt%8SXX@@8t%t8%t@XXS88"
	@echo "\t\t\t\t\t     .%SXX88X%%SS8S@X%8X@t@SSX@@8@8888@XS8.S"
	@echo "\t\t\t\t\t     @S8SS@@8@SX8@X88@StX8S@S@S8X888SX8S8X%"
	@echo "\t\t\t\t\t     :8t8S@XX8%8%88888SX8@@@%%888888X@88"
	@echo "\t\t\t\t\t     S8X@8:SX88Xt@%888SSSS8.SX8@XX88@88 %"
	@echo "\t\t\t\t\t    @88@8Xt@%88@@;%X@8XSS88tSt X%88888 .8"
	@echo "\t\t\t\t\t    @8S888SX@@@SS8;S8SSX@ %88S@@88@:S:;t;;"
	@echo "\t\t\t\t\t   ; @888@S8t8@@8@%;;;%St@:8;@SXS8;X X:%t ;"
	@echo "\t\t\t\t\t   8888@S%@@XXS8S@XX;t;X;t8X88@@88@X   ;:.X"
	@echo "\t\t\t\t\t    8@X88@X@8SXSS@t;@t%@8@8XX8@88888   :: ;"
	@echo "\t\t\t\t\t   8@8%@8@X88888XXX%t@8@X888888@@;88S; :%X"
	@echo "\t\t\t\t\t   S88@XS%8@S88X8:S88888SX@8888 t%88X%8S@ ;"
	@echo "\t\t\t\t\t   XS@t@88888XXS@88888@88X888@: :@8@%@S8t8"
	@echo "\t\t\t\t\t   88888888@@8@@@888888@88@8 8  S@XX@8XS@"
	@echo "\t\t\t\t\t   @@88XS@@888888X:SSXXX8 ;% ...88SX8%8"
	@echo "\t\t\t\t\t     X88888888888;X:t8;%%       88S8SX8X"
	@echo "\t\t\t\t\t    8X8888888888@S:;@X:         X8888S8%"
	@echo "\t\t\t\t\t     X;X88888@@@@t8;           ;;@X8S8"
	@echo "\t\t\t\t\t  ;t:%%t88@@8XXX@S88           ;%8X888t"
	@echo "\t\t\t\t\t %S888tt88X88XSS@X%@S          tX@@888t"
	@echo "\t\t\t\t\t X888@8%;@@88@XX8@@SXS         %@8@S%@X"
	@echo "\t\t\t\t\t %88888@S;t8tXX8SSXXS:%        X8888%@8"
	@echo "\t\t\t\t\t %%%88X;@@%88SX@@@XSX%          S88888 @"
	@echo "\t\t\t\t\t 8888X8@8@88@@888888SSS88     .:@88@88X8% .;X8"
	@echo "\t\t\t\t\t  88@8@; ..8SXt888XS88SX;     X888@8@88888888%%"
	@echo "\t\t\t\t\t @%X@88@%S t;@888%S8@SX88     %;X888X%88888S.X8"
	@echo "\t\t\t\t\t  :@t:t%8 ..:X:8;8888%8@"
	@echo "\t\t\t\t\t               8 @8X8"
	@echo
	@echo
	@printf "\t$(LIGHT_BLUE)AUTHORS\t\t:\t$(BYELLOW)%b\n\t$(LIGHT_BLUE)TEAM NAME\t:\t$(BYELLOW)%b\n\t$(LIGHT_BLUE)Project NAME\t:\t$(BYELLOW)%b\n\t$(LIGHT_BLUE)DATE\t\t:\t$(BYELLOW)%b\n\n" "$(AUTHORS)" "$(TEAM_NAME)" "$(PROJECT_NAME)" "$(DATE)"
	@echo "\t$(BYELLOW)LOADING...$(NO_COLOR)\n"
	@mkdir -p $(HEADERS_DIR)
	@mkdir -p $(SRC_DIR)
	@mkdir -p $(OBJ_DIR) && cd $(OBJ_DIR) && mkdir -p $(PRS_DIR) $(MINIMAP_DIR) $(KEYS_HANDLER_DIR) $(DISPLAY_MAIN_SCREEN_DIR) $(MAIN_DIR) $(SPRITES_DIR)

clean: clean_minilibx_$(OP)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

clean_minilibx_mac:
	@$(MAKE) --no-print-directory -C $(MINILIBX_MACOS_DIR) clean

clean_minilibx_linux:
	@$(MAKE) --no-print-directory -C $(MINILIBX_LINUX_DIR) clean

fclean: clean
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

remac: fclean mac

renux: fclean linux

.PHONY: all clean fclean re
