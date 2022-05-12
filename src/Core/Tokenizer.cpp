#include "Tokenizer.hpp" 

bool check_for_single_line_comment_start(uint& index, uint& column, const std::string& code, bool& inside_single_line_comment)
{	
	if (code[index] == '/' && index + 1 < code.length() && code[index + 1] == '/')
	{
		index += 2;
		column += 2;
		inside_single_line_comment = true;
		return true;
	}

	return false;
}

void check_for_single_line_comment_end(uint& index, uint& column, const std::string& code, bool& inside_single_line_comment)
{
	if (code[index++] == '\n')
	{
		inside_single_line_comment = false;
	}
	column++;		
}

bool check_for_multiline_comment_start(uint& index, uint& column, const std::string& code, bool& inside_multiline_comment)
{                                               
	if (code[index] == '/' && index + 1 < code.length() && code[index + 1] == '*')
	{
		index += 2;
		column += 2;
		inside_multiline_comment = true;
		return true;
	}     

	return false;
}

void check_for_multiline_comment_end(uint& index, uint& column, const std::string& code, bool& inside_multiline_comment)
{
	if (code[index] == '*' && index + 1 < code.length() && code[index + 1] == '/')
	{
		index += 2;
		column += 2;
		inside_multiline_comment = false;
	}
	else
	{
		column++;
		index++;
	}
}

bool check_for_string_start(uint& index, uint& column, const std::string& code, std::string& current_token, bool& inside_string)
{
    if (code[index] == '"')
    {
		current_token += code[index++];
		column++;
		inside_string = true;
		return true;
    }

    return false;
}

void check_for_string_end(uint& index, uint& column, const std::string& code, std::string& current_token, bool& inside_string)
{
	if (code[index] == '"')
	{
		if (!(current_token.length() > 0 && current_token.back() == '\\'))
		{
			inside_string = false;	
		}	
	}
	current_token += code[index++];
	column++;
}

bool check_for_char_start(uint& index, uint& column, const std::string& code, std::string& current_token, bool& inside_char)
{
    if (code[index] == '\'')
    {
		current_token += code[index++];
		column++;
		inside_char = true;
		return true;
    }

    return false;	
}

void check_for_char_end(uint& index, uint& column, const std::string& code, std::string& current_token, bool& inside_char)
{
	if (code[index] == '\'')
	{
		if (!(current_token.length() > 0 && current_token.back() == '\\'))
		{
			inside_char = false;	
		}	
	}
	current_token += code[index++];
	column++;
}

//TODO Calculate line/column increments while using different spaces correctly
bool check_for_whitespace(uint& index, uint& line, uint& column, const std::string& code)
{
	if (is_space(code[index]))
	{
		if (code[index] == '\n')
		{
			line++;
			column = 1;
		}
		else
		{
			column++;
		}
		index++;
		return true;
	}	

	return false;
}

//TODO Check that current token is always appended when splitting 
TOKENIZE_RESULT tokenize(const std::string& code)
{
	TOKENIZE_RESULT result = {{}};
	std::string current_token = "";
	uint line = 1, column = 1, current_token_line = 1, current_token_column = 1,
		 index = 0;
	bool inside_single_line_comment = false,
		 inside_multiline_comment = false,
		 inside_string = false,
		 inside_char = false;                                                    
	while (index < code.length())
	{
		if (inside_single_line_comment)
		{
			check_for_single_line_comment_end(index, column, code, inside_single_line_comment);
			continue;
		}
		if (inside_multiline_comment)
		{
			check_for_multiline_comment_end(index, column, code, inside_multiline_comment);
			continue;
		}
		if (inside_string)
		{
			check_for_string_end(index, column, code, current_token, inside_string);
			if (!inside_string)
			{
				result.tokens.push_back({current_token, current_token_line, current_token_column});
				current_token = "";
				current_token_line = line;
				current_token_column = column;			
			}
			continue;
		}
		if (inside_char)
		{
			check_for_char_end(index, column, code, current_token, inside_char);
			if (!inside_char)
			{
				result.tokens.push_back({current_token, current_token_line, current_token_column});
				current_token = "";
				current_token_line = line;
				current_token_column = column;
			}
			continue;
		}
		
		if (check_for_single_line_comment_start(index, column, code, inside_single_line_comment)) continue;
		if (check_for_multiline_comment_start(index, column, code, inside_multiline_comment)) continue;
		if (check_for_string_start(index, column, code, current_token, inside_string)) continue;
		if (check_for_char_start(index, column, code, current_token, inside_char)) continue;
		if (check_for_whitespace(index, line, column, code)) 
		{
			if (current_token.length() > 0)
			{
				result.tokens.push_back({current_token, current_token_line, current_token_column});
				current_token = "";
			}
			current_token_line = line;
			current_token_column = column;
			continue;
		}
		if (is_splittable(code[index]))
		{
			if (current_token.length() > 0)
			{
				result.tokens.push_back({current_token, current_token_line, current_token_column});
				current_token = "";
			}
			current_token_line = line;
			current_token_column = column++;
			result.tokens.push_back({std::string(1, code[index++]), current_token_line, current_token_column});
			continue;
		}
		if (current_token.length() == 0)
		{
			current_token_line = line;
			current_token_column = column;
		}
		current_token += code[index++];
		column++;
	}
	if (current_token.length() > 0)
	{
		result.tokens.push_back({current_token, current_token_line, current_token_column});
	}
	
	return result;
}