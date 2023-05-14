PROG=	writer
OBJS=	writer.o
CFLAGS= -Wall -g
CC=	$(CROSS_COMPILE)gcc

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all: ${PROG}

${PROG}: ${OBJS}
	${CC} ${OBJS} ${CFLAGS} -o ${PROG} ${LDFLAGS}

clean:
	rm -rf ${PROG} ${OBJS}
