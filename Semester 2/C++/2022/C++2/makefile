all: executable1
	./executable1

executable1: ex1.o
	g++ -o executable1 ex1.o
	
ex1.o: ex1.cpp
		g++ -c ex1.cpp

clean:
	rm ./*.o executable1
