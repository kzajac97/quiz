#ifndef QUIZ_SINGLE_CHOICE_QUESTION_H
#define QUIZ_SINGLE_CHOICE_QUESTION_H

#include <string>
#include <vector>

#include "question.h"

class SingleChoiceQuestion : Question
{
    public:
    SingleChoiceQuestion(std::string question_text, std::vector<std::string> answers_text, std::vector<std::string> correct_answer)
    {
        question_text = question_text;
        answers_text = answers_text;
        correct_answer = correct_answer;
    }
    
    ~SingleChoiceQuestion() {};
};

#endif //QUIZ_SINGLE_CHOICE_QUESTION_H
