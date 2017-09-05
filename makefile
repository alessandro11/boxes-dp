CC=gcc

CFLAGS=-Wall

DEFINES =
OBJS = sunconjuntos.o prox-subconj.o

ifdef DEBUG
	CFLAGS += -g
	DEFINES += -DDEBUG
else
	CFLAGS += -O3
endif

.SUFFIXES: .c
.c.o:
	$(CC) $(DEFINES) $(CFLAGS) -c $<

all: subconjuntos prox-subconj

subconjuntos: subconjuntos.o
	$(CC) -o $(@) $^

prox-subconj: prox-subconj.o
	$(CC) -o $(@) $^

subconjuntos.o: subconjuntos.c
prox-subconj.o: prox-subconj.c

clean:
	@rm --recursive --force *.o subconjuntos prox-subconj
