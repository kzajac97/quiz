#include <fstream>
#include <iostream>
#include <string>
#include <memory>

#include "reader.h"
#include "question.h"
#include "single_choice_question.h"
#include "multiple_choice_question.h"
#include "fill_in_question.h"


std::vector<std::string> read_content_from_file(std::string file_name)
{
    std::ifstream infile(file_name);
    std::vector<std::string> file_content;

    if (infile.is_open())
    {
        std::string line;
        while (std::getline(infile, line))
            { file_content.push_back(line); }
    }

    infile.close();
    return file_content;
}


int read_questions(std::vector<std::string> file_content)
{
    std::vector<std::vector<std::string>> questions_content;
    std::vector<std::string> question_buffer;
    std::vector<std::shared_ptr<Question>> questions;

    for(unsigned int iterator = 0; iterator < file_content.size(); ++iterator)
    {
        if(file_content[iterator][0] == '#')
        {
            for(unsigned int counter=1; counter <= 4; ++counter)
                { question_buffer.push_back(file_content[iterator + counter]); }
            questions_content.push_back(question_buffer);
            question_buffer.clear();
        }
    }

    for(const auto content : questions_content)
    {
        if(content[1] == "type: single")
            { std::cout << "build single\n"; }
        else if(content[1] == "type: multiple")
            { std::cout << "build multiple\n"; }
        else if(content[1] == "type: fill")
            { std::cout << "build fill in\n"; }
    }

    return 0;
}