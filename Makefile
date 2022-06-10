NAME		=	minitalk
CLIENT 		=	client
SERVER		=	server
CLIENT_B 	=	client_bonus
SERVER_B	=	server_bonus

CC			=	gcc

CFLAGS	=	-Wall -Wextra -Werror -Iincludes

SRCS		=	ft_atoi.c
SRCS_CL		=	client.c 
SRCS_SV		=	server.c
SRCS_CL_B	=	client_bonus.c 
SRCS_SV_B	=	server_bonus.c

RM			=	rm -f

VPATH = srcs/\
		srcs_bonus/

HEADER		=	includes/minitalk.h\

OBJ			=	$(patsubst %.c,%.o,$(SRCS))
OBJ_CL		=	$(patsubst %.c,%.o,$(SRCS_CL))
OBJ_SV		=	$(patsubst %.c,%.o,$(SRCS_SV))
OBJ_CL_B	=	$(patsubst %.c,%.o,$(SRCS_CL_B))
OBJ_SV_B	=	$(patsubst %.c,%.o,$(SRCS_SV_B))

all:		${NAME}

${NAME}:	lib ${CLIENT} ${SERVER}

${CLIENT}:	${OBJ_CL} ${OBJ}
	${CC} ${OBJ_CL} ${OBJ} -Lprintf -lftprintf -o ${CLIENT} 
${SERVER}:	${OBJ_SV}
	${CC} ${OBJ_SV} ${OBJ} -Lprintf -lftprintf -o ${SERVER}
${CLIENT_B}:	${OBJ_CL_B} ${OBJ}
	${CC} ${OBJ_CL_B} ${OBJ} -Lprintf -lftprintf -o ${CLIENT_B} 
${SERVER_B}:	${OBJ_SV_B}
	${CC} ${OBJ_SV_B} ${OBJ} -Lprintf -lftprintf -o ${SERVER_B}

lib :
	make -C printf

%.o :	%.c Makefile ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

bonus:		lib ${CLIENT_B} ${SERVER_B}

clean:	
	${RM} *.o
	make clean -C printf

fclean:		clean
	${RM} ${CLIENT} ${SERVER} ${CLIENT_B} ${SERVER_B}
	make fclean -C printf

re:			fclean all

.PHONY:		all bonus clean fclean re
