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
	if (token_type_str == "int") return DT_INT;
 	if (token_type_str == "long") return DT_LONG;
	if (token_type_str == "bigint") return DT_BIGINT;
	if (token_type_str == "bool") return DT_BOOL;
	if (token_type_str == "char") return DT_CHAR;
	if (token_type_str == "string") return DT_STRING;
	if (token_type_str == "float") return DT_FLOAT;
	if (token_type_str == "array") return DT_ARRAY;
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
		printf("L%d C%d TT[%s] \"%s\"%c %c", 
			processed_tokens[i].token.line, processed_tokens[i].token.column, 
			token_type_map[processed_tokens[i].type].name.c_str(), 
			processed_tokens[i].token.value.c_str(), i < processed_tokens.size() - 1 ? ',' : 0, i % 5 == 4 ? '\n' : 0);
	}
}

void print_processed_tokens_by_lines(const std::vector<PROCESSED_TOKEN>& processed_tokens)
{
	int current_line = 0;
	bool printed_line = false, printed_first = false;
	for (int i = 0; i < processed_tokens.size(); i++)
	{
		if (processed_tokens[i].token.line != current_line)
		{
			current_line = processed_tokens[i].token.line;
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
		printf("| C%d, TT[%s] \"%s\" ", 
			processed_tokens[i].token.column, token_type_map[processed_tokens[i].type].name.c_str(), processed_tokens[i].token.value.c_str());
	}
}

void print_processed_tokens_line_by_line(const std::vector<PROCESSED_TOKEN>& processed_tokens)
{
	for (const PROCESSED_TOKEN& processed_token : processed_tokens)
	{
		printf("LINE[%d], COLUMN[%d], TOKEN_TYPE[%s], VALUE[%s]\n", 
			processed_token.token.line, processed_token.token.column,
			token_type_map[processed_token.type].name.c_str(),
			processed_token.token.value.c_str());
	}
}