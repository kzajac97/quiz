CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++17

bin/quiz.out: bin/main.o bin/question.o
	g++ ${CXXFLAGS} -o bin/quiz.out bin/main.o bin/question.o

bin/question.o: inc/question.h src/question.cpp
	g++ -c ${CXXFLAGS} -o bin/question.o src/question.cpp

bin/main.o: src/main.cpp inc/question.h
	g++ -c ${CXXFLAGS} -o bin/main.o src/main.cpp

run:
	./bin/quiz.out

clean:
	rm -f bin/*.o quiz.out
