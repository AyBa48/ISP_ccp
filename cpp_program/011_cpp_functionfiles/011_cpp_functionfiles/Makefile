CC = g++
EXE = helloworld_function
OBJ = main.o func.o

ifndef VERBOSE
.SILENT:
endif

@all:
	make comp
	make run
	make clean

comp: $(OBJ)
	$(CC) -o $(EXE) $(OBJ)

%.o: %.cpp
	$(CC) -c $*.cpp

run:
	./$(EXE)

clean: 
	touch bmp~
	rm $(OBJ) *~ $(EXE)
