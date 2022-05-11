#include "Core/Error.hpp"
#include "Core/Tokenizer.hpp"
#include "Core/Lexer.hpp"
#include "Core/Parser.hpp"

int main(int argc, char **argv)
{
		
	std::string code = "";

	TOKENIZE_RESULT tokenize_result = tokenize(code);
	if (tokenize_result.status == FAIL) 
	{
		print_errors(tokenize_result.errors);
		exit(1);
	}

	return 0;
}
    