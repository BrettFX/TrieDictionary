all: Driver.o TrieDictionary.o
	g++ -Wall Driver.o TrieDictionary.o -o output.out

TrieDictionary.o: TrieDictionary.cpp
	g++ -Wall -c TrieDictionary.cpp
	
Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch *#[

run:
	./output.out
