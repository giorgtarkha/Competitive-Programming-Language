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
				token,
				token_type,
				token_group
			});
		}
	
	}
	return result;	
}

LEX_RESULT merge_processed_tokens(const std::vector<PROCESSED_TOKEN>& processed_tokens)
{
	LEX_RESULT result = {
		LEX_STATUS::SUCCESS,
		processed_tokens,
		{}
	};
	int index = 0;
	while (index < processed_tokens.size())
	{
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
