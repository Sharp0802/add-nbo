

OBJs := main.o

all: $(OBJs)
	$(CC) $< -o add-nbo

clean:
	rm add-nbo
	rm -rf *.o

*.o: *.c
	$(CC) -c $< -o %@

