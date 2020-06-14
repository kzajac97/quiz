#include <iostream>
#include <string>
#include <vector>

#include "single_choice_question.h"


void SingleChoiceQuestion::ask(void)
{
    std::cout << question_text << "\n";

    for(unsigned int iter=0; iter < this->answers_text.size(); ++iter)
        { std::cout << iter + 1 << "." << this->answers_text[iter] << "\n"; }

    std::cout << "\n";
}