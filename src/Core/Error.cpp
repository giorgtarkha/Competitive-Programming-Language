#include "Error.hpp"

void print_errors(const std::vector<ERROR>& errors)
{
	for (const ERROR& error : errors)
	{
		printf("Error occured at line[%d], column[%d], %s\n", 
				error.line, error.column, error.message.c_str());		
	}
}
