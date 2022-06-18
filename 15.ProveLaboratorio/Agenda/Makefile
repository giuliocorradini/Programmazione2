OBJ=lista.o tipo.o compito.o
CXXFLAGS=-Wall
EXEC=agenda

-include "dependecies"

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ)

.PHONY: clean cleanall gendeps

clean:
	rm -f *.o

cleanall:
	rm -f *.o $(EXEC)

gendeps:
	$(CXX) -MM *.h > dependecies