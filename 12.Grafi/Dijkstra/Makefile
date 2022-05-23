OBJ = main.o codap.o grafo.o
CXXFLAGS = -Wall
EXEC = dijkstra

-include "dependencies"

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ)

.PHONY: clean cleanall depends
clean:
	rm -f *.o

cleanall:
	rm -f *.o $(EXEC)

depends:
	$(CXX) -MM *.cc > dependencies
