#ifndef QUIZ_FILL_IN_QUESTION_H
#define QUIZ_FILL_IN_QUESTION_H

#include <string>
#include <vector>

#include "question.h"

class FillInQuestion : public Question
{
    public:
    FillInQuestion(std::string question_text, std::string correct_answer)
    {
        question_text = question_text;
        correct_answer = correct_answer;
    }
    
    ~FillInQuestion() {};
};

#endif //QUIZ_FILL_IN_QUESTION_H
