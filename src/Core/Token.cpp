#include "Token.hpp"

void print_tokens(const std::vector<TOKEN>& tokens)
{
	for (int i = 0; i < tokens.size(); i++)
	{
		
		printf("L%d C%d \"%s\"%c %c", tokens[i].line, tokens[i].column, tokens[i].value.c_str(), i < tokens.size() - 1 ? ',' : 0, i % 5 == 4 ? '\n' : 0);
	}
}

void print_tokens_by_lines(const std::vector<TOKEN>& tokens)
{
	int current_line = 0;
	bool printed_line = false, printed_first = false;
	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i].line != current_line)
		{
			current_line = tokens[i].line;
			printed_line = false;
			if (printed_first)
			{
				printf("\n");
			}
			printed_first = true;	
		}	
		if (!printed_line)
		{                                       
			printf("L%d ", current_line);				
			printed_line = true;
		}
		printf("| C%d, \"%s\" ", tokens[i].column, tokens[i].value.c_str());
	}
}
