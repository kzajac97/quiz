#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "question.h"
#include "reader.h"

int main(void)
{   
    auto content = read_content_from_file(std::string("data/sample.txt"));
    auto questions = read_questions(content);
}