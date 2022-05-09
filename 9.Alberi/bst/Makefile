OBJ = bst.o main.o
CXXFLAGS = -Wall

bst: $(OBJ)
	g++ -o bst $(OBJ)

-include dependencies

.PHONY: clean cleanall depend
clean:
	rm -rf *.o

cleanall:
	rm -rf bst *.o

depend:
	g++ -MM *.cc > dependencies