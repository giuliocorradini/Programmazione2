OBJ = main.o grafo.o coda-bfs.o
CXXFLAGS = -Wall -g
EXEC = graph

-include "dependencies"

graph: $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ)

.PHONY: clean cleanall depends
clean:
	rm -f *.o

cleanall:
	rm -f *.o $(EXEC)

depends:
	$(CXX) -MM *.cc > dependencies
