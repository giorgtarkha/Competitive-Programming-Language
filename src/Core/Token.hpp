#ifndef CPL_TOKEN
#define CPL_TOKEN

#include <string>
#include <vector>
#include <unordered_map>

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
	KW_VOID,
	DT_INT,
	DT_LONG,
	DT_BIGINT,
	DT_BOOL,
	DT_CHAR,
	DT_STRING,
	DT_FLOAT,
	DT_ARRAY,
	DT_STACK,
	DT_QUEUE,
	DT_DEQUE,
	DT_SET,
	DT_HASHSET,
	DT_MULTISET,
	DT_MAP,
	DT_HASHMAP,
	DT_BITS,
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

enum TOKEN_GROUP
{
	TG_KEYWORD,
	TG_DATATYPE,
	TG_OPERATOR,
	TG_SCOPE,
	TG_SEPARATOR,
	TG_TOKEN,
	TG_UNKNOWN
};

typedef struct
{
	std::string name;
} TOKEN_TYPE_DATA;

typedef struct 
{
	std::string name;
} TOKEN_GROUP_DATA;

static std::unordered_map<TOKEN_TYPE, TOKEN_TYPE_DATA> token_type_map = {
	{KW_IF, {"KW_IF"}},
	{KW_ELSE, {"KW_ELSE"}},
	{KW_FOR, {"KW_FOR"}},
	{KW_RETURN, {"KW_RETURN"}},
	{KW_CONTINUE, {"KW_CONTINUE"}},
	{KW_BREAK, {"KW_BREAK"}},
	{KW_TRUE, {"KW_TRUE"}},
	{KW_FALSE, {"KW_FALSE"}},
	{KW_NULL, {"KW_NULL"}},
	{KW_VOID, {"KW_VOID"}},
	{DT_INT, {"DT_INT"}},
	{DT_LONG, {"DT_LONG"}},
	{DT_BIGINT, {"DT_BIGINT"}},
	{DT_BOOL, {"DT_BOOL"}},
	{DT_CHAR, {"DT_CHAR"}},
	{DT_STRING, {"DT_STRING"}},
	{DT_FLOAT, {"DT_FLOAT"}},
	{DT_ARRAY, {"DT_ARRAY"}},
	{DT_STACK, {"DT_STACK"}},
	{DT_QUEUE, {"DT_QUEUE"}},
	{DT_DEQUE, {"DT_DEQUE"}},
	{DT_SET, {"DT_SET"}},
	{DT_HASHSET, {"DT_HASHSET"}},
	{DT_MULTISET, {"DT_MULTISET"}},
	{DT_MAP, {"DT_MAP"}},
	{DT_HASHMAP, {"DT_HASHMAP"}},
	{DT_BITS, {"DT_BITS"}},
	{OP_ASSIGN, {"OP_ASSIGN"}},
	{OP_ADD, {"OP_ADD"}},
	{OP_SUBTRACT, {"OP_SUBTRACT"}},
	{OP_MULTIPLY, {"OP_MULTIPLY"}},
	{OP_DIVIDE, {"OP_DIVIDE"}},
	{OP_MODULO, {"OP_MODULO"}},
	{OP_POWER, {"OP_POWER"}},
	{OP_AND, {"OP_AND"}},
	{OP_OR, {"OP_OR"}},
	{OP_XOR, {"OP_XOR"}},
	{OP_NOT, {"OP_NOT"}},
	{OP_LSHIFT, {"OP_LSHIFT"}},
	{OP_RSHIFT, {"OP_RSHIFT"}},
	{OP_ADD_ASSIGN, {"OP_ADD_ASSIGN"}},
	{OP_SUBTRACT_ASSIGN, {"OP_SUBTRACT_ASSIGN"}},
	{OP_MULTIPLY_ASSIGN, {"OP_MULTIPLY_ASSIGN"}},
	{OP_DIVIDE_ASSIGN, {"OP_DIVIDE_ASSIGN"}},
	{OP_MODULO_ASSIGN, {"OP_MODULO_ASSIGN"}},
	{OP_POWER_ASSIGN, {"OP_POWER_ASSIGN"}},
	{OP_AND_ASSIGN, {"OP_AND_ASSIGN"}},
	{OP_OR_ASSIGN, {"OP_OR_ASSIGN"}},
	{OP_XOR_ASSIGN, {"OP_XOR_ASSIGN"}},
	{OP_LSHIFT_ASSIGN, {"OP_LSHIFT_ASSIGN"}},
	{OP_RSHIFT_ASSIGN, {"OP_RSHIFT_ASSIGN"}},
	{OP_TERNARYQ, {"OP_TERNARYQ"}},
	{OP_TERNARYD, {"OP_TERNARYD"}},
	{OP_GREATER_THAN, {"OP_GREATER_THAN"}},
	{OP_LESS_THAN, {"OP_LESS_THAN"}},
	{OP_GREATER_THAN_EQ, {"OP_GREATER_THAN_EQ"}},
	{OP_LESS_THAN_EQ, {"OP_LESS_THAN_EQ"}},
	{OP_EQ, {"OP_EQ"}},
	{OP_NOT_EQ, {"OP_NOT_EQ"}},
	{SC_LPARENTHESIS, {"SC_LPARENTHESIS"}},
	{SC_RPARENTHESIS, {"SC_RPARENTHESIS"}},
	{SC_LBRACKET, {"SC_LBRACKET"}},
	{SC_RBRACKET, {"SC_RBRACKET"}},
	{SC_LBRACE, {"SC_LBRACE"}},
	{SC_RBRACE, {"SC_RBRACE"}},
	{SP_COMMA, {"SP_COMMA"}},
	{SP_SEMICOLON, {"SP_SEMICOLON"}},
	{TK_LITERAL, {"TK_LITERAL"}},
	{TK_IDENTIFIER, {"TK_IDENTIFIER"}},
	{TK_UNKNOWN, {"TK_UNKNOWN"}}
};

static std::unordered_map<TOKEN_GROUP, TOKEN_GROUP_DATA> token_group_map = {
	{TG_KEYWORD, {"TG_KEYWORD"}},
	{TG_DATATYPE, {"TG_DATATYPE"}},
	{TG_OPERATOR, {"TG_OPERATOR"}},
	{TG_SCOPE, {"TG_SCOPE"}},
	{TG_SEPARATOR, {"TG_SEPARATOR"}},
	{TG_TOKEN, {"TG_TOKEN"}},
	{TG_UNKNOWN, {"TG_UNKNOWN"}}
};

typedef struct
{
	std::string value;
	uint line;
	uint column;
} TOKEN;

typedef struct
{
	std::string value;
	uint line;
	uint column;
	TOKEN_TYPE type;
	TOKEN_GROUP group;	
} PROCESSED_TOKEN;

TOKEN_TYPE get_token_type(const std::string& token_type_str);
TOKEN_GROUP get_token_group(const TOKEN_TYPE token_type);
void print_tokens(const std::vector<TOKEN>& tokens);
void print_tokens_by_lines(const std::vector<TOKEN>& tokens);
void print_tokens_line_by_line(const std::vector<TOKEN>& tokens);
void print_processed_tokens(const std::vector<PROCESSED_TOKEN>& processed_tokens);
void print_processed_tokens_by_lines(const std::vector<PROCESSED_TOKEN>& processed_tokens);
void print_processed_tokens_line_by_line(const std::vector<PROCESSED_TOKEN>& processed_tokens);

#endif