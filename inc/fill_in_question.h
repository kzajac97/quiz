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
        this->question_text = question_text;
        this->correct_answer = correct_answer;
    }
    
    ~FillInQuestion() {};

    const std::string ask(void);
    unsigned int check(std::string user_answer);
};

#endif //QUIZ_FILL_IN_QUESTION_H
