CC=clang
CFLAGS= -Wall -Wextra -g
DEPS = graph.h stack.h queue.h search.h path.h
OBJ = graph.o stack.o queue.o search.o path.o
MAINSRC = main.c

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o  $@ $<

main.out: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(MAINSRC)

.PHONY: clean

clean:
	rm -f *.out *.o
