#include "Error.hpp"

void print_errors(std::vector<ERROR>& errors)
{
	for (ERROR& error : errors)
	{
		printf("Error occured at line[%d], column[%d] \n%s\n", 
				error.line, error.column, error.message);		
	}
}
