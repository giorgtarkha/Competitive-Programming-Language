#include "Core/Error.hpp"
#include "Core/Token.hpp"
#include "Core/Tokenizer.hpp"
#include "Core/Lexer.hpp"
#include "Core/Parser.hpp"

int main(int argc, char **argv)
{
		
	std::string code = "void main() {\n"
	 "	int x = 0;\n"
	 "	int y = 1;\n"
	 "	print(x + y);\n"
	 "}\n";	
	printf("%s\n", code.c_str());
	TOKENIZE_RESULT tokenize_result = tokenize(code);
	print_tokens_by_lines(tokenize_result.tokens);
	LEX_RESULT lex_result = lex(tokenize_result.tokens);

	return 0;
}
    