#ifndef QUIZ_QUESTION_H
#define QUIZ_QUESTION_H

#include <string>
#include <vector>

class Question
{
    private:
    // field for string hodling question content
    std::string question_text;
    // field holding possible question answers
    std::vector<std::string> answers_text;
    // field holding correct answer to question
    std::string corret_answer;

    public:
    virtual void ask();
    virtual void check();
};

#endif //QUIZ_QUESTION_H
