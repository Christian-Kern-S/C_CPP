#----------- VARIABLES -----------

ECHO = echo -e
OBJ = ./obj
LIB = ./lib
TESTS = ./Tests
FILES = $(TESTS)/*.cpp 
FILES_O = $(OBJ)/Test_.o $(OBJ)/Test_2.o $(OBJ)/Test_3.o $(OBJ)/Test_4.o

TEST_FILE ?= Test_.cpp

#-----------FLAGS -----------

LIBS = -lcompile -L $(LIB)
FLAGS = -O3 -Wall

#----------- CODE -----------

all: compile test

compile: $(FILES_O) build
	$(ECHO) Compiling...

build: $(FILES_O)
	ar -rcs $(LIB)/libcompile.a $(OBJ)/*.o

test:
	$(ECHO) Testing...
	g++ $(FILES) -lgtest -lgtest_main -pthread
	./a.out

test_single: $(TESTS)/main.cpp $(TESTS)/$(TEST_FILE)
	$(ECHO) Testing a single file...
	g++ $^ -lgtest -lgtest_main -pthread
	./a.out

tree:
	$(ECHO) Showing Tree
	tree .

clean:
	rm -rf ./obj/* ./lib/*

#----------- TEMPLATE -----------

$(OBJ)/%.o: $(TESTS)/%.cpp
	gcc ${FLAGS} -c $< -o $@

