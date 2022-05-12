#include "Lexer.hpp"

LEX_RESULT process_tokens(const std::vector<TOKEN>& tokens)
{
	for (const TOKEN& token : tokens)
	{
		
	}
	return {};	
}

LEX_RESULT merge_processed_tokens(const std::vector<PROCESSED_TOKEN>& processed_tokens)
{
	return {};
}

LEX_RESULT lex(const std::vector<TOKEN>& tokens)
{	
	LEX_RESULT processing_result = process_tokens(tokens);
	if (processing_result.status == FAIL) 
	{
		return processing_result;
	}	
	return merge_processed_tokens(processing_result.processed_tokens);
}
