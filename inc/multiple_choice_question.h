#ifndef QUIZ_MULTIPLE_CHOICE_QUESTION_H
#define QUIZ_MULTIPLE_CHOICE_QUESTION_H

#include <string>
#include <vector>

#include "question.h"

class MultipleChoiceQuestion : public Question
{
    private:
    std::vector<std::string> correct_answers;
    public:
    MultipleChoiceQuestion(std::string question_text, std::vector<std::string> answers_text, std::vector<std::string> correct_answers)
    {
        this->question_text = question_text;
        this->answers_text = answers_text;
        this->correct_answers = correct_answers;
    }
    
    ~MultipleChoiceQuestion() {};

    const std::string ask(void);
    unsigned int check(std::string user_answer);
};

#endif //QUIZ_MULTIPLE_CHOICE_QUESTION_H
