OBJ = compito.o liste.o tipo.o
CXXFLAGS = -Wall

-include "dependecies"

compito: $(OBJ)
	$(CXX) -o compito $(OBJ)

.PHONY: clean cleanall depends
clean:
	rm -f *.o

cleanall:
	rm -f *.o compito

depends:
	$(CXX) -MM *.cc > dependecies