#ifndef READER_HH
#define READER_HH

#include <memory>
#include <string>
#include <vector>

#include "question.h"

std::vector<std::string> split_string(std::string content, char delimiter);
std::vector<std::string> read_content_from_file(std::string file_name);
std::vector<std::unique_ptr<Question>> read_questions(std::vector<std::string> file_content);

#endif //READER_HH