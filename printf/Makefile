NAME 	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	ft_printf.c print_str.c print_num.c print_unum.c print_hex.c print_ptr.c minus.c wdt_prc.c

SRCS_B	=	ft_printf.c print_str.c print_num.c print_unum.c print_hex.c print_ptr.c minus.c wdt_prc.c

RM		=	rm -f

HEADER	=	ft_printf.h

OBJ		=	$(patsubst %.c,%.o,$(SRCS))

OBJ_B	=	$(patsubst %.c,%.o,$(SRCS_B))

all:		${NAME}

${NAME}:	${OBJ}
	ar rcs ${NAME} ${OBJ} ${HEADER}

%.o :		%.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

bonus:		${OBJ} ${OBJ_B}
	ar rcs ${NAME} ${OBJ} ${OBJ_B} ${HEADER}

clean:	
	${RM} *.o

fclean:		clean
	${RM} ${NAME} bonus

re:			fclean all

.PHONY:		all bonus clean fclean re
