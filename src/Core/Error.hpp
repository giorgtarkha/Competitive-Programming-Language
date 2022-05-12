#ifndef CPL_ERROR
#define CPL_ERROR

#include <string>
#include <vector>

typedef struct
{
	int line;
	int column;
	std::string message;
} ERROR;

void print_errors(const std::vector<ERROR>& errors);

#endif
