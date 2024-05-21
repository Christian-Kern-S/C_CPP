#----------- VARIABLES -----------
ECHO = echo -e

F_PROG = $(PROG)/*.cpp
PROG = ./PROG
F_UNITTEST = $(UNITTEST)/*.cpp
UNITTEST = ./UNITTEST
F_INCLUDE = $(INCLUDE)/*.hpp
INCLUDE = ./INCLUDE
F_MOCKS = $(MOCK)/*.hpp
MOCK = ./MOCKS
FILES_O = $(OBJ)/Bank.o $(OBJ)/Deposit.o $(OBJ)/Draft.o $(OBJ)/Transfer.o $(OBJ)/PhysicalAccount.o $(OBJ)/LegalAccount.o $(OBJ)/Container.o $(OBJ)/IAccount.o $(OBJ)/NullAccount.o $(OBJ)/Observer.o $(OBJ)/MockObserver.o
OBJ = ./obj
LIB = ./lib
#----------- FLAGS -----------
LIBS = -lcompile -L $(LIB)
FLAGS = -O3 -Wall -std=c++17
#----------- CODE -----------

all: compile test

compile: dir $(FILES_O) build
	$(ECHO) COMPILED...

build: $(FILES_O)
	ar -rcs $(LIB)/libcompile.a $(OBJ)/*.o

test:
	$(ECHO) TESTING...
	g++ $(F_UNITTEST) $(F_PROG) -lgtest -lgmock -lgtest_main -pthread
	./a.out

dir:
	rm -rf obj lib
	mkdir obj lib
#----------- TEMPLATE -----------
$(OBJ)/%.o: $(PROG)/%.cpp $(INCLUDE)/%.hpp
	g++ $(FLAGS) -c $< $(LIBS) -I $(INCLUDE) -o $@

$(OBJ)/%.o: $(INCLUDE)/%.hpp
	g++ $(FLAGS) -c $< $(LIBS) -o $@

$(OBJ)/%.o: $(MOCK)/%.hpp
	g++ $(FLAGS) -c $< $(LIBS) -o $@