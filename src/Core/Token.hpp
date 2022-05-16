#ifndef CPL_TOKEN
#define CPL_TOKEN

#include <string>
#include <vector>

#include "Utils.hpp"

enum TOKEN_TYPE 
{
	KW_IF,
	KW_ELSE,
	KW_FOR,
	KW_RETURN,
	KW_CONTINUE,
	KW_BREAK,
	KW_TRUE,
	KW_FALSE,
	KW_NULL,
	DT_INT,
	DT_LONG,
	DT_BIGINT,
	DT_BOOL,
	DT_CHAR,
	DT_STRING,
	DT_FLOAT,
	DT_ARRAY,
	OP_ASSIGN,
	OP_ADD,
	OP_SUBTRACT,
	OP_MULTIPLY,
	OP_DIVIDE,
	OP_MODULO,
	OP_POWER,
	OP_AND,
	OP_OR,
	OP_XOR,
	OP_NOT,
	OP_LSHIFT,
	OP_RSHIFT,
	OP_ADD_ASSIGN,
	OP_SUBTRACT_ASSIGN,
	OP_MULTIPLY_ASSIGN,
	OP_DIVIDE_ASSIGN,
	OP_MODULO_ASSIGN,
	OP_POWER_ASSIGN,
	OP_AND_ASSIGN,
	OP_OR_ASSIGN,
	OP_XOR_ASSIGN,
	OP_LSHIFT_ASSIGN,
	OP_RSHIFT_ASSIGN,
	OP_TERNARYQ,
	OP_TERNARYD,
	OP_GREATER_THAN,
	OP_LESS_THAN,
	OP_GREATER_THAN_EQ,
	OP_LESS_THAN_EQ,
	OP_EQ,
	OP_NOT_EQ,
	SC_LPARENTHESIS,
	SC_RPARENTHESIS,
	SC_LBRACKET,
	SC_RBRACKET,
	SC_LBRACE,
	SC_RBRACE,
	SP_COMMA,
	SP_SEMICOLON,
	TK_LITERAL,
	TK_IDENTIFIER,
	TK_UNKNOWN
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

TOKEN_TYPE get_token_type(const std::string& token_type_str);
void print_tokens(const std::vector<TOKEN>& tokens);
void print_tokens_by_lines(const std::vector<TOKEN>& tokens);
void print_processed_tokens(const std::vector<PROCESSED_TOKEN>& processed_tokens);
void print_processed_tokens_by_lines(const std::vector<PROCESSED_TOKEN>& processed_tokens);

#endif