#include <iostream>
#include <string>
#include <vector>

#include "multiple_choice_question.h"


const std::string MultipleChoiceQuestion::ask(void)
{
    unsigned int user_answer; 
    std::cout << this->question_text << "\n";

    for(unsigned int iter=0; iter < this->answers_text.size(); ++iter)
        { std::cout << iter + 1 << "." << this->answers_text[iter] << "\n"; }
    std::cout << "\n";
    
    std::cin >> user_answer;
    return this->answers_text[user_answer];
}