#include "Core/Error.hpp"
#include "Core/Token.hpp"
#include "Core/Tokenizer.hpp"
#include "Core/Lexer.hpp"
#include "Core/Parser.hpp"

int main(int argc, char **argv)
{
		
	std::string code = "void main() {\n"
	 "	int x += 0;\n"
	 "	int y = 1;\n"
	 "	print(x + y);\n"
	 "}\n";	
	printf("%s\n", code.c_str());
	TOKENIZE_RESULT tokenize_result = tokenize(code);
	printf("TOKENIZE RESULT------------------------------------------------\n");
	print_tokens_line_by_line(tokenize_result.tokens);
	printf("---------------------------------------------------------------\n");
	LEX_RESULT lex_result = lex(tokenize_result.tokens);
	printf("LEX RESULT-----------------------------------------------------\n");
	if (lex_result.status == LEX_STATUS::FAIL)
	{
		print_errors(lex_result.errors);
		printf("---------------------------------------------------------------\n");
		exit(-1);
	}
	print_processed_tokens_line_by_line(lex_result.processed_tokens);
	printf("---------------------------------------------------------------\n");

	return 0;
}
    