CXXFLAGS=-g -Iinc -Wall -Wextra -pedantic -std=c++17

bin/quiz.out: bin/main.o bin/question.o bin/reader.o bin/fill_in_question.o bin/single_choice_question.o bin/multiple_choice_question.o
	g++ ${CXXFLAGS} -o bin/quiz.out bin/main.o bin/question.o bin/reader.o bin/fill_in_question.o bin/single_choice_question.o bin/multiple_choice_question.o

bin/question.o: inc/question.h src/question.cpp
	g++ -c ${CXXFLAGS} -o bin/question.o src/question.cpp

bin/reader.o: inc/reader.h src/reader.cpp
	g++ -c ${CXXFLAGS} -o bin/reader.o src/reader.cpp

bin/single_choice_question.o: inc/single_choice_question.h src/single_choice_question.cpp
	g++ -c ${CXXFLAGS} -o bin/single_choice_question.o src/single_choice_question.cpp

bin/multiple_choice_question.o: inc/multiple_choice_question.h src/multiple_choice_question.cpp
	g++ -c ${CXXFLAGS} -o bin/multiple_choice_question.o src/multiple_choice_question.cpp

bin/fill_in_question.o: inc/fill_in_question.h src/fill_in_question.cpp
	g++ -c ${CXXFLAGS} -o bin/fill_in_question.o src/fill_in_question.cpp

bin/main.o: src/main.cpp src/question.cpp src/reader.cpp inc/question.h inc/reader.h \
			inc/fill_in_question.h inc/single_choice_question.h inc/multiple_choice_question.h \
			src/fill_in_question.cpp src/single_choice_question.cpp src/multiple_choice_question.cpp
	g++ -c ${CXXFLAGS} -o bin/main.o src/main.cpp

run:
	./bin/quiz.out

clean:
	rm -f bin/*.o quiz.out
