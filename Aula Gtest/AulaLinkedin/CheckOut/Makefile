ECHO=echo -e
PROG = ./PROG
UNITTEST = ./UNITTEST
INCLUDE = ./INCLUDE
OBJ = ./obj
LIB = ./lib

LIBS = -lcompile -L $(LIB)
FLAGS = -O3 -Wall 

all: compile test

compile: $(OBJ)/Checkout.o $(OBJ)/CheckoutTest.o build
	$(ECHO) Compiling...
	

build: $(OBJ)/Checkout.o
	ar -rcs $(LIB)/libcompile.a $(OBJ)/*.o

test:
	$(ECHO) Testing...
	g++ $(UNITTEST)/CheckoutTest.cpp $(PROG)/Checkout.cpp -lgtest -lgtest_main -pthread
	./a.out


$(OBJ)/%.o: $(PROG)/%.cpp $(INCLUDE)/%.h
	$(ECHO) Compiling...
	gcc $(FLAGS) -c $< $(LIBS) -I $(INCLUDE) -o $@

$(OBJ)/%.o: $(UNITTEST)/%.cpp
	$(ECHO) Compiling...
	gcc $(FLAGS) -c $< -o $@
	

tree: 
	$(ECHO) Showing Tree
	tree .

clean:
	rm ./obj/* $(LIB)/*