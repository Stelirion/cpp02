NAME	= fixed
SRCS	= 	main.cpp \
			fixed.cpp \

HEADERS	= 	fixed.hpp \

DIR_SRCS = ./

DIR_HEAD = ./

DIR_OBJS = .objs/

OBJS	=	${SRCS:%.c=${DIR_OBJS}%.o}

CC	= c++

MKDIR	=	mkdir -p

CFLAGS	= -Wall -Wextra -Werror -std=c++98

all :		${NAME}

clean :
			rm -rf ${DIR_OBJS}

fclean :	clean
			rm -rf ${NAME}

re :		fclean
			$(MAKE) all

${DIR_OBJS}%.o: 	${DIR_SRCS}%.c	${addprefix ${DIR_HEAD}, ${HEADERS}} | ${DIR_OBJS}
					${CC} ${CFLAGS} -I ${DIR_HEAD} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

${NAME} :	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

.PHONY:		all clean fclean re