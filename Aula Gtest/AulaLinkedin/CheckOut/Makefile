#----------- VARIABLES -----------
ECHO=echo -e
PROG = ./PROG
F_PROG = $(PROG)/*.cpp
UNITTEST = ./UNITTEST
F_UNITTEST = $(UNITTEST)/*.cpp
INCLUDE = ./INCLUDE
F_INCLUDE = $(INCLUDE)/*.h
OBJ = ./obj
LIB = ./lib

#-----------FLAGS -----------

LIBS = -lcompile -L $(LIB)
FLAGS = -O3 -Wall 

#----------- CODE -----------

all: compile test

compile: $(OBJ)/Checkout.o $(OBJ)/CheckoutTest.o build
	$(ECHO) Compiling...
	

build: $(OBJ)/Checkout.o
	ar -rcs $(LIB)/libcompile.a $(OBJ)/*.o

test:
	$(ECHO) Testing...
	g++ $(F_UNITTEST) $(F_PROG) -lgtest -lgtest_main -pthread
	./a.out

#----------- TEMPLATE -----------

$(OBJ)/%.o: $(PROG)/%.cpp $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< $(LIBS) -I $(INCLUDE) -o $@

$(OBJ)/%.o: $(UNITTEST)/%.cpp
	gcc $(FLAGS) -c $< -o $@

#----------- TEMPLATE -----------

tree: 
	$(ECHO) Showing Tree
	tree .

clean:
	rm ./obj/* $(LIB)/*