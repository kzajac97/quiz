#include <iostream>
#include <string>
#include <vector>

#include "multiple_choice_question.h"


void MultipleChoiceQuestion::ask(void)
{
    std::cout << this->question_text << "\n";

    for(unsigned int iter=0; iter < this->answers_text.size(); ++iter)
        { std::cout << iter + 1 << "." << this->answers_text[iter] << "\n"; }

    std::cout << "\n";
}