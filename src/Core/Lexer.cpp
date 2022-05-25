#include "Lexer.hpp"

LEX_RESULT process_tokens(const std::vector<TOKEN>& tokens)
{
	LEX_RESULT result = {	
		LEX_STATUS::SUCCESS,
		{},
		{}
	};
	bool with_errors = false;		
	for (const TOKEN& token : tokens)
	{
		TOKEN_TYPE token_type = get_token_type(token.value);
		TOKEN_GROUP token_group = get_token_group(token_type);
		if (token_type == TOKEN_TYPE::TK_UNKNOWN)
		{
			result.status = FAIL;
			result.errors.push_back({
				token.line,
				token.column,
				"Unknown identifier[" + token.value + "]"
			});
			with_errors = true;
		}
		else if (!with_errors)
		{	
			result.processed_tokens.push_back({
				token.value,
				token.line,
				token.column,
				token_type,
				token_group
			});
		}
	
	}
	return result;	
}

//TODO Think about subtract token, when to use as subtraction and when to use as negative literal/identifier, 
//TODO could be done in parser, one solution would be to preceed each subtraction sign with a 0
LEX_RESULT merge_processed_tokens(const std::vector<PROCESSED_TOKEN>& processed_tokens)
{
	LEX_RESULT result = {
		LEX_STATUS::SUCCESS,
		{},
		{}
	};
	bool with_errors = false;
	int index = 0;
	while (index < processed_tokens.size())
	{
		const PROCESSED_TOKEN processed_token = processed_tokens[index];
		if (processed_token.group == TOKEN_GROUP::TG_OPERATOR) 
		{
			int last_operator_index = index + 1;
			std::string current_operator = processed_token.value;
			while (last_operator_index < processed_tokens.size())
			{
				const PROCESSED_TOKEN next_processed_token = processed_tokens[last_operator_index];
				if (next_processed_token.group != TOKEN_GROUP::TG_OPERATOR || next_processed_token.type == TOKEN_TYPE::OP_NOT) break;
				current_operator += next_processed_token.value;
				last_operator_index++;
			}
			index = last_operator_index;
			TOKEN_TYPE token_type = get_token_type(current_operator);
			TOKEN_GROUP token_group = get_token_group(token_type);
			if (token_type == TOKEN_TYPE::TK_UNKNOWN)
			{
				result.status = FAIL;
				result.errors.push_back({
					processed_token.line,
					processed_token.column,
					"Unknown identifier[" + current_operator + "]"
				});
				with_errors = true;
			}
			else if (!with_errors)
			{
				result.processed_tokens.push_back({
					current_operator,
					processed_token.line,
					processed_token.column,
					token_type,
					token_group	
				});
			}
			continue;
		}

		if (processed_token.type == TOKEN_TYPE::TK_INTEGER)
		{
			if (index + 2 < processed_tokens.size() && 
			    processed_tokens[index + 1].type == TOKEN_TYPE::SP_DOT &&
			    processed_tokens[index + 2].type == TOKEN_TYPE::TK_INTEGER)
			{
				result.processed_tokens.push_back({
					processed_token.value + processed_tokens[index + 1].value + processed_tokens[index + 2].value,
					processed_token.line,
					processed_token.column,
					TOKEN_TYPE::TK_FLOAT,
					TOKEN_GROUP::TG_TOKEN
				});
				index += 3;
			}
			else
			{
				result.processed_tokens.push_back(processed_token);
				index++;
			}
			continue;												
		}

		if (!with_errors)
		{
			result.processed_tokens.push_back(processed_token);
		}

		index++;
	}
	return result;
}

LEX_RESULT lex(const std::vector<TOKEN>& tokens)
{	
	LEX_RESULT processing_result = process_tokens(tokens);
	if (processing_result.status == LEX_STATUS::FAIL) 
	{
		return processing_result;
	}	
	return merge_processed_tokens(processing_result.processed_tokens);
}
