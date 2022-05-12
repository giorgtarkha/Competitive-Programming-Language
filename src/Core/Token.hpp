#ifndef CPL_TOKEN
#define CPL_TOKEN

#include <string>

#include "Utils.hpp"

enum TOKEN_TYPE 
{
	
};

typedef struct
{
	std::string value;
	uint line;
	uint column;
} TOKEN;

#endif
