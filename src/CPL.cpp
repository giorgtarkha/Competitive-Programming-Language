#include "Core/Error.hpp"
#include "Core/Tokenizer.hpp"
#include "Core/Lexer.hpp"
#include "Core/Parser.hpp"

int main(int argc, char **argv)
{
		
	std::string code = "\"test1\" //pirveli \n /*pirvelihehe \n meore \n meorehehe*/ \"test\" \n \"aaaaa\" 'test'";
	printf("%s\n", code.c_str());
	TOKENIZE_RESULT tokenize_result = tokenize(code);
	if (tokenize_result.status == FAIL) 
	{
		print_errors(tokenize_result.errors);
		exit(-1);
	}
	else
	{
		print_tokens(tokenize_result.tokens);
	}

	return 0;
}
    