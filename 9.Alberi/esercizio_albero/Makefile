OBJ = main.o albero.o stringa.o
EXEC = Alberi
CXXFLAGS = -Wall


$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ)

-include dependencies

debug: set_debug_flags $(EXEC)

.PHONY: clean clean_all gen_deps set_debug_flags
set_debug_flags: clean
	CXXFLAGS = $(CXXFLAGS) -DDEBUG	#not working

clean:
	rm -f *.o

clean_all:
	rm -f alberi *.o

gen_deps:
	$(CXX) -MM *.cc > dependencies
