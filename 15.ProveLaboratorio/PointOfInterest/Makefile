OBJ=grafo.o liste.o tipo.o compito.o
CXXFLAGS=-Wall

-include "dependencies"

compito: $(OBJ)
	$(CXX) -o compito $(OBJ)

.PHONY: clean cleanall gendeps

clean:
	rm -f *.o

cleanall:
	rm -f *.o compito

gendeps:
	$(CXX) -MM *.h > dependencies