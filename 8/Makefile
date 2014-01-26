CFLAGS = -I..
LDFLAGS = ../apue.o

EXEC = 8-1 8-4 8-5 8-6 8-8 8-9 8-10 8-13 8-14 8-15 8-16 8-17 8-18

all: $(EXEC)

8-4: 8-3.o
8-13: 8-3.o 8-12.o
8-14: 8-3.o
8-18: 8-3.o

clean:
	-rm $(EXEC) *.o
