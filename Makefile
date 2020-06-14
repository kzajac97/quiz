CXXFLAGS=-g -Iinc -Wall -Wextra -pedantic -std=c++17

bin/quiz.out: bin/main.o bin/question.o bin/reader.o
	g++ ${CXXFLAGS} -o bin/quiz.out bin/main.o bin/question.o bin/reader.o

bin/question.o: inc/question.h src/question.cpp
	g++ -c ${CXXFLAGS} -o bin/question.o src/question.cpp

bin/reader.o: inc/reader.h src/reader.cpp
	g++ -c ${CXXFLAGS} -o bin/reader.o src/reader.cpp

bin/main.o: src/main.cpp src/question.cpp src/reader.cpp inc/question.h inc/reader.h
	g++ -c ${CXXFLAGS} -o bin/main.o src/main.cpp

run:
	./bin/quiz.out

clean:
	rm -f bin/*.o quiz.out
