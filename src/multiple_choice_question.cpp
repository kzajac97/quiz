#include <cctype>
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
    if(user_answer <= 4 && user_answer >= 1)  
        { return this->answers_text[user_answer - 1]; }  // move one back, because of 0 indexing
    else
    {
        std::cout << "Error! You have to chose number in range [1, 4]\n";
        return std::string(" ");
    }
}


unsigned int MultipleChoiceQuestion::check(std::string user_answer)
{
    return user_answer == this->correct_answer;
}