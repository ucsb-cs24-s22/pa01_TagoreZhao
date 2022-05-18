CXX_FLAG = --std=c++11 -g

all: game

game: main.o
	g++ $(CXX_FLAG) -o game main.o

test: test.o
	g++ $(CXX_FLAG) -o test test.o

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

test.o: test.cpp
	g++ -c $(CXX_FLAG) test.cpp

utility.o: utility.cpp
	g++ -c $(CXX_FLAG) utility.cpp

clean:
	rm -f game *.o