#ifndef QUIZ_RETURN_CODES_H
#define QUIZ_RETURN_CODES_H

// return codes
const int OK_CODE = 0;
const int FILE_IO_ERROR = -1;
// symbols
const char QUESTION_INDICATOR = '#';
// indices
const unsigned int QUESTION_INDICATOR_INDEX = 0;
const unsigned int TYPE_INDICATOR_INDEX = 1;
const unsigned int ANSWER_INDICATOR_INDEX = 2;
const unsigned int CORRECT_INDICATOR_INDEX = 3;
// string slicing
const unsigned int QUESTION_SUB_STR_SIZE = 10;
const unsigned int TYPE_SUB_STR_SIZE = 6;
const unsigned int ANSWER_SUB_STR_SIZE = 8;
const unsigned int CORRECT_SUB_STR_SIZE = 9;

#endif //QUIZ_RETURN_CODES_H
