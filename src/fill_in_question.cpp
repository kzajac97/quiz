#include <iostream>
#include <string>
#include <vector>

#include "fill_in_question.h"


const std::string FillInQuestion::ask(void)
{
    std::string user_answer;

    std::cout << "Fill in gap\n" << question_text << "\n\n";
    std::cin >> user_answer;

    return user_answer;
}


unsigned int FillInQuestion::check(std::string user_answer)
{
    return user_answer == this->correct_answer;
}
