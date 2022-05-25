#include "Core/Error.hpp"
#include "Core/Token.hpp"
#include "Core/Tokenizer.hpp"
#include "Core/Lexer.hpp"
#include "Core/Parser.hpp"

//TODO behave based on arguments, introduce debug flag, use special logging only when debug flag is active
int main(int argc, char **argv)
{
	
	printf("Arg Count[%d] -------------------------------------------------\n", argc);
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}	
	printf("---------------------------------------------------------------\n");
		
	std::string code = "void main() {\n"
	 "	int x += 0;\n"
	 "	int y = 1;\n"
	 "	int z = 0.5;\n"
	 "	print(x + y + z);\n"
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
    
