#ifndef CPL_TOKEN
#define CPL_TOKEN

#include <string>
#include <vector>

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

typedef struct
{
	TOKEN token;
	TOKEN_TYPE type;	
} PROCESSED_TOKEN;

void print_tokens(const std::vector<TOKEN>& tokens);
void print_tokens_by_lines(const std::vector<TOKEN>& tokens);

#endif
