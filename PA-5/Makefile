OBJ = main.o graph.o topological_sort.o # Part 2
#OBJ = main.o graph.o 
MAIN = main

$(MAIN): $(OBJ)
	$(CXX) -g -std=c++11 -o $(MAIN) $(OBJ)

main.o: main.cpp
	$(CXX) -g -std=c++11 -c main.cpp

graph.o: graph.cpp graph.h
	$(CXX) -g -std=c++11 -c graph.cpp

topological_sort.o: topological_sort.cpp graph.h
	$(CXX) -g -std=c++11 -c topological_sort.cpp

clean: 
	rm -f $(OBJ) $(MAIN)
