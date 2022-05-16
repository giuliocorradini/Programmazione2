OBJ = grafo.o main.o
CXXFLAGS = -Wall
EXEC = graph

-include "dependencies"

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ)

grafo.o:
	cd ../grafo
	make depends
	make
	cp grafo.o *.h ../file-grafo
	cd ../file-grafo

.PHONY: clean cleanall depends
clean:
	rm -f *.o

cleanall:
	rm -f *.o $(EXEC)

depends:
	$(CXX) -MM *.cc > dependencies
