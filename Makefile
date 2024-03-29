C_SOURCES = $(wildcard */*.c *.c)
HEADERS = $(wildcard */*.h *.h)
OBJ = ${C_SOURCES:.c=.o}
C_FLAGS = -O3 -g -lcurl

CC = gcc

all: ds_c_test

%.o: %.c
	${CC} ${C_FLAGS} -c -o $@ $^

ds_c_test: ${OBJ} 	
	${CC} ${C_FLAGS} -o $@ $^

run:
	./ds_c_test

test:
	valgrind ./ds_c_test

clean:
	rm -f */*.o *.o 
	rm -f ds_c_test
