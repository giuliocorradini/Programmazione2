OBJ = grafo.o main.o
CXXFLAGS = -Wall
EXEC = graph

-include "dependencies"

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ)

grafo.o:
	g++ -o grafo.o grafo.cc

.PHONY: clean cleanall depends
clean:
	rm -f *.o

cleanall:
	rm -f *.o $(EXEC)

depends:
	$(CXX) -MM *.cc > dependencies
