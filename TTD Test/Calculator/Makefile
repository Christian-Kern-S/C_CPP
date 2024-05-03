#----------- VARIABLES -----------
ECHO = echo -e

F_PROG = $(PROG)/*.cpp
PROG = ./PROG
F_UNITTEST = $(UNITTEST)/*.cpp
UNITTEST = ./UNITTEST
F_INCLUDE = $(INCLUDE)/*.hpp
INCLUDE = ./INCLUDE
FILES_O = $(OBJ)/Calculator.o
OBJ = ./obj
LIB = ./lib
#----------- FLAGS -----------
LIBS = -lcompile -L $(LIB)
FLAGS = -O3 -Wall -std=c++17
LIBGTEST = -lgtest -lgmock -lgtest_main -pthread
#----------- CODE -----------

all: compile test

compile: dir $(FILES_O) build
	$(ECHO) COMPILED...

build: $(FILES_O)
	ar -rcs $(LIB)/libcompile.a $(OBJ)/*.o

test:
	$(ECHO) TESTING...
	g++ $(F_UNITTEST) $(F_PROG) $(LIBGTEST)
	./a.out

dir:
	rm -rf obj lib
	mkdir obj lib
#----------- TEMPLATE -----------
$(OBJ)/%.o: $(PROG)/%.cpp $(INCLUDE)/%.hpp
	g++ $(FLAGS) -c $< $(LIBS) -I $(INCLUDE) -o $@

$(OBJ)/%.o: $(INCLUDE)/%.hpp
	g++ $(FLAGS) -c $< $(LIBS) -o $@