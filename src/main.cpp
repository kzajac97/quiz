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
    unsigned int score = 0;
    auto content = read_content_from_file(std::string("data/sample.txt"));
    auto questions = read_questions(content);

    for(const auto & it : questions)
    {
        auto answer = it->ask();
        score += it->check(answer);
        std::cout << answer << "\n";
        if(it->check(answer) == 1) { std::cout << "Correct!\n"; }  
    }

    std::cout << "Your score is: " << score << "\n";
}