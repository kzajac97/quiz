#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "question.h"
#include "single_choice_question.h"
#include "multiple_choice_question.h"
#include "fill_in_question.h"
#include "reader.h"

int main(void)
{   
    auto content = read_content_from_file(std::string("data/sample.txt"));
    auto questions = read_questions(content);

    for(const auto & it : questions)
    {
        auto answer = it->ask();
        std::cout << answer << "\n";  
    }
}