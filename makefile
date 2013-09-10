CC = gcc
CFLAGS = -g -Wall

all: disAssemble

disAssemble: disAssemble.o processOpts.o rType.o iType.o jType.o getRegister.o
	${CC} ${CFLAGS} -o disAssemble disAssemble.o processOpts.o rType.o iType.o jType.o getRegister.o

disAssemble.o: disAssemble.c disAssemble.h
	${CC} ${CFLAGS} -c disAssemble.c

processOpts.o: processOpts.c disAssemble.h
	${CC} ${CFLAGS} -c processOpts.c

rType.o: rType.c disAssemble.h
	${CC} ${CFLAGS} -c rType.c

iType.o: iType.c disAssemble.h
	${CC} ${CFLAGS} -c iType.c

jType.o: jType.c disAssemble.h
	${CC} ${CFLAGS} -c jType.c

clean:
	/bin/rm *.o
