#ifndef CPL_LEXER
#define CPL_LEXER

#include <vector>

#include "Token.hpp"
#include "Error.hpp"

enum LEX_STATUS
{
	SUCCESS,
	FAIL
};

typedef struct
{
	LEX_STATUS status;
	std::vector<PROCESSED_TOKEN> processed_tokens;
	std::vector<ERROR> errors;
} LEX_RESULT;

LEX_RESULT lex(const std::vector<TOKEN>& tokens);


#endif