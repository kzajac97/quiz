#ifndef QUIZ_MULTIPLE_CHOICE_QUESTION_H
#define QUIZ_MULTIPLE_CHOICE_QUESTION_H

#include <string>
#include <vector>

#include "question.h"

class MultipleChoiceQuestion : Question
{
    private:
    std::vector<std::string> correct_answers;
    public:
    MultipleChoiceQuestion(std::string question_text, std::vector<std::string> answers_text, std::vector<std::string> correct_answers)
    {
        question_text = question_text;
        answers_text = answers_text;
        correct_answers = correct_answers;
    }
    
    ~MultipleChoiceQuestion() {};
};

#endif //QUIZ_MULTIPLE_CHOICE_QUESTION_H
