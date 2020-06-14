#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "multiple_choice_question.h"


const std::string MultipleChoiceQuestion::ask(void)
{
    std::string user_answer;
    std::cout << "Chose multiple answers:\n" << this->question_text << "\n";

    for(unsigned int iter=0; iter < this->answers_text.size(); ++iter)
        { std::cout << iter + 1 << "." << this->answers_text[iter] << "\n"; }
    std::cout << "\n";
    
    std::cin >> user_answer;

    return user_answer;
}


unsigned int MultipleChoiceQuestion::check(std::string user_answer)
{
    std::stringstream ss(user_answer);
    std::vector<unsigned int> result;

    while(ss.good())
    {
        std::string substr;
        std::getline(ss, substr, ',');
        result.push_back(std::stoi(substr));
    }

    for(unsigned int index=0; index < result.size(); ++index)
    {
        if(this->answers_text[result[index]] != this->correct_answers[index])
            { return 0; }
    }
    
    return 1;
}