OBJ = main.o albero.o stringa.o
CXXFLAGS = -Wall -DDEBUG


Alberi: $(OBJ)
	$(CXX) -o Alberi $(OBJ)

-include dependencies


.PHONY: clean clean_all gen_deps
clean:
	rm -f *.o

clean_all:
	rm -f alberi *.o

gen_deps:
	$(CXX) -MM *.cc > dependencies
