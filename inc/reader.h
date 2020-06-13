#ifndef READER_HH
#define READER_HH

#include <string>
#include <vector>

#include "question.h"

std::vector<std::string> read_content_from_file(std::string file_name);
int read_questions(std::vector<std::string> file_content);

#endif //READER_HH