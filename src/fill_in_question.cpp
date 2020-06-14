#include <iostream>
#include <string>
#include <vector>

#include "fill_in_question.h"


const std::string FillInQuestion::ask(void)
{
    std::string user_answer;

    std::cout << question_text << "\n\n";
    std::cin >> user_answer;

    return user_answer;
}