CFLAGS = -I..
LDFLAGS = ../apue.o

EXEC = 8-1 8-4 8-5 8-6 8-8 8-9 8-10 8-13

all: $(EXEC)

8-4: 8-3.o
8-13: 8-3.o 8-12.o

clean:
	-rm $(EXEC) *.o
