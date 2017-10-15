CC=g++

CFLAGS=-Wall

DEFINES =
OBJS = caixas.o

ifdef DEBUG
	CFLAGS += -g
	DEFINES += -DDEBUG
else
	CFLAGS += -O3
endif

.SUFFIXES: .c
.c.o:
	$(CC) $(DEFINES) $(CFLAGS) -c $<

all: caixas

caixas: caixas.o
	$(CC) -o $(@) $^

caixas.o: caixas.c

clean:
	@rm --recursive --force *.o caixas
