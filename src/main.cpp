#include <iostream>
#include <string>

#include "question.h"
#include "reader.h"

int main(void)
{   
    read_questions_from_file(std::string("file_name"));
    read_question(std::string("dict"));

    std::cout << "Quiz\n";
}
