#ifndef CPL_ERROR
#define CPL_ERROR

#include <string>
#include <vector>

#include "Utils.hpp"

typedef struct
{
	uint line;
	uint column;
	std::string message;
} ERROR;

void print_errors(const std::vector<ERROR>& errors);

#endif
