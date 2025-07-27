# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

NAME 			= minitalk
NAME_BONUS		= minitalk_bonus

# ══ Colors ══════════════════════════════════════════════════════════════════ #
#    ------                                                                    #

DEL_LINE 		= \033[2K
ITALIC 			= \033[3m
BOLD 			= \033[1m
DEF_COLOR 		= \033[0;39m
GRAY 			= \033[0;90m
RED 			= \033[0;91m
GREEN 			= \033[0;92m
YELLOW 			= \033[0;93m
BLUE 			= \033[0;94m
MAGENTA 		= \033[0;95m
CYAN 			= \033[0;96m
WHITE 			= \033[0;97m
BLACK 			= \033[0;99m
ORANGE 			= \033[38;5;209m
BROWN 			= \033[38;2;184;143;29m
DARK_GRAY 		= \033[38;5;234m
MID_GRAY 		= \033[38;5;245m
DARK_GREEN 		= \033[38;2;75;179;82m
DARK_YELLOW 	= \033[38;5;143m

# ══ Compilation══════════════════════════════════════════════════════════════ #
#    -------                                                                   #

CC 				= clang
CFLAGS 			= -Wall -Werror -Wextra
AR 				= ar rcs
RM 				= rm -f
MK 				= make -C
MKD				= mkdir -p
MCL 			= make clean -C
MFCL 			= make fclean -C
MK_				= && make


# ══ Directories ═════════════════════════════════════════════════════════════ #
#    ------- 

LIBFT_DIR		= ./libft
LIBFT_A			= ${LIBFT_DIR}/libft.a
PRINTFT_DIR		= ./printf
PRINTFT_A		= ${PRINTFT_DIR}/printft.a

OBJ_DIR			= ./obj

IFLAGS			= -I./includes
LFLAGS			= -L./libft -lft -L./printf -lftprintf

# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

SRC_C 			= client.c
SRC_S			= server.c

NAME_C			= client
NAME_S			= server

SRC_C_BN		= client_bonus.c
SRC_S_BN		= server_bonus.c

NAME_C_BN		= client_bonus
NAME_S_BN		= server_bonus

OBJ_S 			= ${SRC_S:.c=.o}
OBJ_C 			= ${SRC_C:.c=.o}

OBJ_S_BN		= ${SRC_S_BN:.c=.o}
OBJ_C_BN		= ${SRC_C_BN:.c=.o}

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all: ${NAME} 

${NAME}: ftlibft ftprintf ${OBJ_S} ${OBJ_C}
	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME_S} ${OBJ_S} ${LFLAGS}
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME_C} ${OBJ_C} ${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

ftlibft:
	@cd ${LIBFT_DIR} ${MK_} all

ftprintf:
	@cd ${PRINTFT_DIR} ${MK_} all

bonus: ${NAME_BONUS}

${NAME_BONUS}: ftlibft ftprintf ${OBJ_S_BN} ${OBJ_C_BN}
	@echo "$(YELLOW)Compiling bonus root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME_S_BN} ${OBJ_S_BN} ${LFLAGS}
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME_C_BN} ${OBJ_C_BN} ${LFLAGS}
	@echo "$(GREEN) $(NAME_BONUS) all bonus created ✓$(DEF_COLOR)"

clean:
	@echo "$(YELLOW)Remove main .o  ...$(DEF_COLOR)"

	@cd ${LIBFT_DIR} ${MK_} clean
	@cd ${PRINTFT_DIR} ${MK_} clean
	@$(RM) $(OBJ_S) $(OBJ_C)
	@$(RM) $(OBJ_S_BN) $(OBJ_C_BN)
	@${RM} ${NAME_S} ${NAME_C}
	@${RM} ${NAME_S_BN} ${NAME_C_BN}

	@echo "$(RED)OBJS deleted $(DEF_COLOR)"

fclean:	clean
	@echo "$(YELLOW)Remove main lib ...$(DEF_COLOR)"

	@cd ${LIBFT_DIR} ${MK_} fclean
	@cd ${PRINTFT_DIR} ${MK_} fclean

	@echo "$(RED)$(NAME)|$(NAME_BONUS) deleted$(DEF_COLOR)"

re:	fclean all

.PHONY : all libft printf clean fclean bonus re
