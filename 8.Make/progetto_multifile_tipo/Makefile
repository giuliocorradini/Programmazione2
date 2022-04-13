OBJ = main.o fun-app.o liste.o tipo.o
CXXFLAGS = -Wall

Web-list: $(OBJ)
	g++ -Wall -o Web-list $(OBJ)

-include dependencies

.PHONY: clean cleanall depend
clean:
	rm -f *.o

cleanall:
	rm -f Web-list *.o

depend:
	g++ -MM *.cc > dependencies
