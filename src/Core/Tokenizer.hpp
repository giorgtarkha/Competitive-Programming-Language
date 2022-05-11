#ifndef CPL_TOKENIZER
#define CPL_TOKENIZER

#include <string>
#include <vector>

#include "Error.hpp"

enum TOKENIZE_RESULT_STATUS 
{
	SUCCESS,
	FAIL
};

typedef struct
{
	TOKENIZE_RESULT_STATUS status;
	std::vector<std::string> tokens;
	std::vector<ERROR> errors;
} TOKENIZE_RESULT;

TOKENIZE_RESULT tokenize(std::string& code);

#endif 
