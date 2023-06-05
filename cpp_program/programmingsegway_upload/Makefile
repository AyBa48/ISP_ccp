CC = g++ -std=c++11
EXE = main
OBJ = main.o func.o func_rk4.o func_segway.o

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
