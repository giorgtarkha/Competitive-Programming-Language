#include "Token.hpp"

TOKEN_TYPE get_token_type(const std::string& token_type_str)
{
	if (token_type_str == "if") return KW_IF;
 	if (token_type_str == "else") return KW_ELSE;
	if (token_type_str == "for") return KW_FOR;
	if (token_type_str == "return") return KW_RETURN;
	if (token_type_str == "continue") return KW_CONTINUE;
	if (token_type_str == "break") return KW_BREAK;
	if (token_type_str == "true") return KW_TRUE;
	if (token_type_str == "false") return KW_FALSE;
	if (token_type_str == "null") return KW_NULL;
	if (token_type_str == "void") return KW_VOID;
	if (token_type_str == "int") return DT_INT;
 	if (token_type_str == "long") return DT_LONG;
	if (token_type_str == "bigint") return DT_BIGINT;
	if (token_type_str == "bool") return DT_BOOL;
	if (token_type_str == "char") return DT_CHAR;
	if (token_type_str == "string") return DT_STRING;
	if (token_type_str == "float") return DT_FLOAT;
	if (token_type_str == "array") return DT_ARRAY;
	if (token_type_str == "stack") return DT_STACK;
	if (token_type_str == "queue") return DT_QUEUE;
	if (token_type_str == "deque") return DT_DEQUE;
	if (token_type_str == "set") return DT_SET;
	if (token_type_str == "hashset") return DT_HASHSET;
	if (token_type_str == "multiset") return DT_MULTISET;
	if (token_type_str == "map") return DT_MAP;
	if (token_type_str == "hashmap") return DT_HASHMAP;
	if (token_type_str == "bits") return DT_BITS;
	if (token_type_str == "=") return OP_ASSIGN;
 	if (token_type_str == "+") return OP_ADD;
	if (token_type_str == "-") return OP_SUBTRACT;
	if (token_type_str == "*") return OP_MULTIPLY;
	if (token_type_str == "/") return OP_DIVIDE;
	if (token_type_str == "%") return OP_MODULO;
	if (token_type_str == "**") return OP_POWER;
	if (token_type_str == "&") return OP_AND;
	if (token_type_str == "|") return OP_OR;
	if (token_type_str == "^") return OP_XOR;
	if (token_type_str == "!") return OP_NOT;
 	if (token_type_str == "<<") return OP_LSHIFT;
	if (token_type_str == ">>") return OP_RSHIFT;
	if (token_type_str == "+=") return OP_ADD_ASSIGN;
	if (token_type_str == "-=") return OP_SUBTRACT_ASSIGN;
	if (token_type_str == "*=") return OP_MULTIPLY_ASSIGN;
	if (token_type_str == "/=") return OP_DIVIDE_ASSIGN;
	if (token_type_str == "%=") return OP_MODULO_ASSIGN;
	if (token_type_str == "**=") return OP_POWER_ASSIGN;
	if (token_type_str == "&=") return OP_AND_ASSIGN;
 	if (token_type_str == "|=") return OP_OR_ASSIGN;
	if (token_type_str == "^=") return OP_XOR_ASSIGN;
	if (token_type_str == "<<=") return OP_LSHIFT_ASSIGN;
	if (token_type_str == ">>=") return OP_RSHIFT_ASSIGN;
	if (token_type_str == "?") return OP_TERNARYQ;
	if (token_type_str == ":") return OP_TERNARYD;
	if (token_type_str == ">") return OP_GREATER_THAN;
	if (token_type_str == "<") return OP_LESS_THAN;
	if (token_type_str == ">=") return OP_GREATER_THAN_EQ;
	if (token_type_str == "<=") return OP_LESS_THAN_EQ;
	if (token_type_str == "==") return OP_EQ;
	if (token_type_str == "!=") return OP_NOT_EQ;
	if (token_type_str == "(") return SC_LPARENTHESIS;
	if (token_type_str == ")") return SC_RPARENTHESIS;
	if (token_type_str == "[") return SC_LBRACKET;
	if (token_type_str == "]") return SC_RBRACKET;
	if (token_type_str == "{") return SC_LBRACE;
	if (token_type_str == "}") return SC_RBRACE;
	if (token_type_str == ",") return SP_COMMA;
	if (token_type_str == ";") return SP_SEMICOLON;
	bool have_alph = false, valid_chars = true;
	for (int i = 0; i < token_type_str.length(); i++)
	{
		const char c = token_type_str[i];
		if ((c >= 'a' && c <= 'z') ||
		    (c >= 'A' && c <= 'Z'))
		{
			have_alph = true;
		}
		if (have_alph ? !is_valid_identifier_char(c) : !is_valid_literal_char(c))
		{
			valid_chars = false;
			break;
		}
				
	}
	if (valid_chars)
	{
		if (have_alph)
		{
			return is_digit(token_type_str[0]) ? TK_UNKNOWN : TK_IDENTIFIER;
		}
		return TK_LITERAL;
	}
	return TK_UNKNOWN;
}

TOKEN_GROUP get_token_group(const TOKEN_TYPE token_type)
{
	if (token_type == KW_IF) return TG_KEYWORD;
	if (token_type == KW_ELSE) return TG_KEYWORD;
	if (token_type == KW_FOR) return TG_KEYWORD;
	if (token_type == KW_RETURN) return TG_KEYWORD;
	if (token_type == KW_CONTINUE) return TG_KEYWORD;
	if (token_type == KW_BREAK) return TG_KEYWORD;
	if (token_type == KW_TRUE) return TG_KEYWORD;
	if (token_type == KW_FALSE) return TG_KEYWORD;
	if (token_type == KW_NULL) return TG_KEYWORD;
	if (token_type == KW_VOID) return TG_KEYWORD;
	if (token_type == DT_INT) return TG_DATATYPE;
	if (token_type == DT_LONG) return TG_DATATYPE;
	if (token_type == DT_BIGINT) return TG_DATATYPE;
	if (token_type == DT_BOOL) return TG_DATATYPE;
	if (token_type == DT_CHAR) return TG_DATATYPE;
	if (token_type == DT_STRING) return TG_DATATYPE;
	if (token_type == DT_FLOAT) return TG_DATATYPE;
	if (token_type == DT_ARRAY) return TG_DATATYPE;
	if (token_type == DT_STACK) return TG_DATATYPE;
	if (token_type == DT_QUEUE) return TG_DATATYPE;
	if (token_type == DT_DEQUE) return TG_DATATYPE;
	if (token_type == DT_SET) return TG_DATATYPE;
	if (token_type == DT_HASHSET) return TG_DATATYPE;
	if (token_type == DT_MULTISET) return TG_DATATYPE;
	if (token_type == DT_MAP) return TG_DATATYPE;
	if (token_type == DT_HASHMAP) return TG_DATATYPE;
	if (token_type == DT_BITS) return TG_DATATYPE;
	if (token_type == OP_ASSIGN) return TG_OPERATOR;
	if (token_type == OP_ADD) return TG_OPERATOR;
	if (token_type == OP_SUBTRACT) return TG_OPERATOR;
	if (token_type == OP_MULTIPLY) return TG_OPERATOR;
	if (token_type == OP_DIVIDE) return TG_OPERATOR;
	if (token_type == OP_MODULO) return TG_OPERATOR;
	if (token_type == OP_POWER) return TG_OPERATOR;
	if (token_type == OP_AND) return TG_OPERATOR;
	if (token_type == OP_OR) return TG_OPERATOR;
	if (token_type == OP_XOR) return TG_OPERATOR;
	if (token_type == OP_NOT) return TG_OPERATOR;
	if (token_type == OP_LSHIFT) return TG_OPERATOR;
	if (token_type == OP_RSHIFT) return TG_OPERATOR;
	if (token_type == OP_ADD_ASSIGN) return TG_OPERATOR;
	if (token_type == OP_SUBTRACT_ASSIGN) return TG_OPERATOR;
	if (token_type == OP_MULTIPLY_ASSIGN) return TG_OPERATOR;
	if (token_type == OP_DIVIDE_ASSIGN) return TG_OPERATOR;
	if (token_type == OP_MODULO_ASSIGN) return TG_OPERATOR;
	if (token_type == OP_POWER_ASSIGN) return TG_OPERATOR;
	if (token_type == OP_AND_ASSIGN) return TG_OPERATOR;
	if (token_type == OP_OR_ASSIGN) return TG_OPERATOR;
	if (token_type == OP_XOR_ASSIGN) return TG_OPERATOR;
	if (token_type == OP_LSHIFT_ASSIGN) return TG_OPERATOR;
	if (token_type == OP_RSHIFT_ASSIGN) return TG_OPERATOR;
	if (token_type == OP_TERNARYQ) return TG_OPERATOR;
	if (token_type == OP_TERNARYD) return TG_OPERATOR;
	if (token_type == OP_GREATER_THAN) return TG_OPERATOR;
	if (token_type == OP_LESS_THAN) return TG_OPERATOR;
	if (token_type == OP_GREATER_THAN_EQ) return TG_OPERATOR;
	if (token_type == OP_LESS_THAN_EQ) return TG_OPERATOR;
	if (token_type == OP_EQ) return TG_OPERATOR;
	if (token_type == OP_NOT_EQ) return TG_OPERATOR;
	if (token_type == SC_LPARENTHESIS) return TG_SCOPE;
	if (token_type == SC_RPARENTHESIS) return TG_SCOPE;
	if (token_type == SC_LBRACKET) return TG_SCOPE;
	if (token_type == SC_RBRACKET) return TG_SCOPE;
	if (token_type == SC_LBRACE) return TG_SCOPE;
	if (token_type == SC_RBRACE) return TG_SCOPE;
	if (token_type == SP_COMMA) return TG_SEPARATOR;
	if (token_type == SP_SEMICOLON) return TG_SEPARATOR;
	if (token_type == TK_LITERAL) return TG_TOKEN;
	if (token_type == TK_IDENTIFIER) return TG_TOKEN;
	return TG_UNKNOWN;
}

void print_tokens(const std::vector<TOKEN>& tokens)
{
	for (int i = 0; i < tokens.size(); i++)
	{		
		printf("L%d C%d \"%s\"%c %c",
			tokens[i].line, tokens[i].column, 
			tokens[i].value.c_str(), i < tokens.size() - 1 ? ',' : 0, i % 5 == 4 ? '\n' : 0);
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

void print_tokens_line_by_line(const std::vector<TOKEN>& tokens)
{
	for (const TOKEN& token : tokens)
	{
		printf("LINE[%d], COLUMN[%d], VALUE[%s]\n", 
			token.line, token.column, token.value.c_str());
	}
}

void print_processed_tokens(const std::vector<PROCESSED_TOKEN>& processed_tokens)
{
	for (int i = 0; i < processed_tokens.size(); i++)
	{		
		printf("L%d C%d TT[%s] TG[%s] \"%s\"%c %c", 
			processed_tokens[i].line, processed_tokens[i].column, 
			token_type_map[processed_tokens[i].type].name.c_str(), 
			token_group_map[processed_tokens[i].group].name.c_str(),
			processed_tokens[i].value.c_str(), i < processed_tokens.size() - 1 ? ',' : 0, i % 5 == 4 ? '\n' : 0);
	}
}

void print_processed_tokens_by_lines(const std::vector<PROCESSED_TOKEN>& processed_tokens)
{
	int current_line = 0;
	bool printed_line = false, printed_first = false;
	for (int i = 0; i < processed_tokens.size(); i++)
	{
		if (processed_tokens[i].line != current_line)
		{
			current_line = processed_tokens[i].line;
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
		printf("| C%d, TT[%s], TG[%s] \"%s\" ", 
			processed_tokens[i].column, 
			token_type_map[processed_tokens[i].type].name.c_str(), 
			token_group_map[processed_tokens[i].group].name.c_str(),
			processed_tokens[i].value.c_str());
	}
}

void print_processed_tokens_line_by_line(const std::vector<PROCESSED_TOKEN>& processed_tokens)
{
	for (const PROCESSED_TOKEN& processed_token : processed_tokens)
	{
		printf("LINE[%d], COLUMN[%d], TOKEN_TYPE[%s], TOKEN_GROUP[%s], VALUE[%s]\n", 
			processed_token.line, processed_token.column,
			token_type_map[processed_token.type].name.c_str(),
			token_group_map[processed_token.group].name.c_str(),
			processed_token.value.c_str());
	}
}