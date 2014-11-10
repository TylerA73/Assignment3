CC = g++
OBJ = main.o
OBJ2 = dictionary.o

prog: $(OBJ) $(OBJ2)
	$(CC) $(OBJ) $(OBJ2) -o $@

.cpp.o:
	$(CC) -c $<

clean:
	rm *.o prog
