OBJ=bst.o carta.o compito.o
CXXFLAGS=-Wall
EXEC=compito

-include "dependencies"

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ)

.PHONY: clean cleanall gendeps

clean:
	rm -f *.o

cleanall:
	rm -f *.o $(EXEC)

gendeps:
	$(CXX) -MM *.h > dependencies