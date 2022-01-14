OBJECTS = game_of_life.o print_board.o count_neighbors.o
EXE = run.exe

$(EXE): $(OBJECTS)
	gcc -o $(EXE) $(OBJECTS)
game_of_life.o: game_of_life.c print_board.c count_neighbors.c header.h
	gcc -c game_of_life.c
print_board.o: print_board.c header.h
	gcc -c print_board.c
count_neighbors.o: count_neighbors.c header.h
	gcc -c count_neighbors.c
clean:
	del $(OBJECTS)