#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <memory>

#include "const.h"
#include "reader.h"
#include "question.h"
#include "single_choice_question.h"
#include "multiple_choice_question.h"
#include "fill_in_question.h"


/**
 * Split one string into vector of string
 *
 * @param content: input string
 * @param delimiter: indicates character to split with
 *  
 * @return vector containing strings, splitted substring in each element
 */

std::vector<std::string> split_string(std::string content, char delimiter)
{
    std::stringstream ss(content);
    std::vector<std::string> result;

    while(ss.good())
    {
        std::string substr;
        std::getline(ss, substr, delimiter);
        result.push_back(substr);
    }

    return result;
}


/**
 * Read file with question into vector of strings
 *
 * @param file_name: string with file name or path
 *  
 * @return vector containing strings, each line in one element
 */
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


/**
 * Build polymorphic vector of Question object from file conetents
 *
 * @param file_content: vector of strings with input file content
 *  
 * @return vector of Questions
 */ 
std::vector<std::unique_ptr<Question>> read_questions(std::vector<std::string> file_content)
{
    std::vector<std::vector<std::string>> questions_content;
    std::vector<std::string> question_buffer;
    std::vector<std::unique_ptr<Question>> questions;

    for(unsigned int iterator = 0; iterator < file_content.size(); ++iterator)
    {
        if(file_content[iterator][0] == QUESTION_INDICATOR)
        {
            for(unsigned int counter=1; counter <= 4; ++counter)
                { question_buffer.push_back(file_content[iterator + counter]); }
            questions_content.push_back(question_buffer);
            question_buffer.clear();
        }
    }

    for(const auto content : questions_content)
    {
        if(content[TYPE_INDICATOR_INDEX].substr(TYPE_SUB_STR_SIZE) == "single")
        {
            auto question_content = content[QUESTION_INDICATOR_INDEX].substr(QUESTION_SUB_STR_SIZE);
            auto answers_content = split_string(content[ANSWER_INDICATOR_INDEX].substr(ANSWER_SUB_STR_SIZE), ',');
            auto correct_content = content[CORRECT_INDICATOR_INDEX].substr(CORRECT_SUB_STR_SIZE);

            std::unique_ptr<Question> placeholder(new SingleChoiceQuestion(question_content, answers_content, correct_content));
            questions.push_back(std::move(placeholder));
        }
        else if(content[TYPE_INDICATOR_INDEX].substr(TYPE_SUB_STR_SIZE) == "multiple")
        {
            auto question_content = content[QUESTION_INDICATOR_INDEX].substr(QUESTION_SUB_STR_SIZE);
            auto answers_content = split_string(content[ANSWER_INDICATOR_INDEX].substr(ANSWER_SUB_STR_SIZE), ',');
            auto correct_content = split_string(content[CORRECT_INDICATOR_INDEX].substr(CORRECT_SUB_STR_SIZE), ',');

            std::unique_ptr<Question> placeholder(new MultipleChoiceQuestion(question_content, answers_content, correct_content));
            questions.push_back(std::move(placeholder));
        }

        else if(content[TYPE_INDICATOR_INDEX].substr(TYPE_SUB_STR_SIZE) == "fill")
        {
            // get question and answer without tags from raw string
            auto question_content = content[QUESTION_INDICATOR_INDEX].substr(QUESTION_SUB_STR_SIZE);
            auto correct_content = content[CORRECT_INDICATOR_INDEX].substr(CORRECT_SUB_STR_SIZE);

            std::unique_ptr<Question> placeholder(new FillInQuestion(question_content, correct_content));
            questions.push_back(std::move(placeholder));
        }
    }

    return questions;
}