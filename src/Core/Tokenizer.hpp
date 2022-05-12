#ifndef CPL_TOKENIZER
#define CPL_TOKENIZER

#include <string>
#include <vector>

#include "Error.hpp"
#include "Utils.hpp"
#include "Token.hpp"

typedef struct
{
	std::vector<TOKEN> tokens;
} TOKENIZE_RESULT;

TOKENIZE_RESULT tokenize(const std::string& code);

#endif 
