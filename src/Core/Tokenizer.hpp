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
void print_tokens(const std::vector<TOKEN>& tokens);
void print_tokens_by_lines(const std::vector<TOKEN>& tokens);

#endif 
