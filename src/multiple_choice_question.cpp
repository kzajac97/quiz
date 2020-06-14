#include <iostream>
#include <string>
#include <vector>

#include "multiple_choice_question.h"


void MultipleChoiceQuestion::ask(void)
{
    std::cout << this->question_text << "\n";
}