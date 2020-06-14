#ifndef QUIZ_QUESTION_H
#define QUIZ_QUESTION_H

#include <string>
#include <vector>

class Question
{
    public:
    // field for string hodling question content
    std::string question_text;
    // field holding possible question answers
    std::vector<std::string> answers_text;
    // field holding correct answer to question
    std::string correct_answer;

    protected:
    // default
    Question () {}
    // overriden by single choice question
    Question(std::string question_text, std::vector<std::string> answers_text, std::string correct_answer)
        : question_text(question_text), answers_text(answers_text), correct_answer(correct_answer) {}
    // overriden by fill in question
    Question(std::string question_text, std::string correct_answer)
        : question_text(question_text), correct_answer(correct_answer) {}
    
    public: // desctructor must be public to allow inheritance
    virtual ~Question() {}

    virtual void ask() {std::cout << "Base\n"; };
    // virtual void check();
};

#endif //QUIZ_QUESTION_H
