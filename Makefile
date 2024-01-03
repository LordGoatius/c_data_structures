C_SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJ = ${C_SOURCES:.c=.o}
C_FLAGS = -O3 -g

CC = gcc

all: ds_c_test

%.o: %.c
	${CC} ${C_FLAGS} -c -o $@ $^

ds_c_test: ${OBJ} 	
	${CC} ${C_FLAGS} -o $@ $^

run:
	./ds_c_test

clean:
	rm -f *.o 
	rm -f ds_c_test
#llc: 
#	${CC} ${C_SOURCES} ${HEADERS} -o llc
#
#run:
#	${CC} ${C_SOURCES} ${HEADERS} -o llc
#	./llc
#
#clean:
#	rm llc
