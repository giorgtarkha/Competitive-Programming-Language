#include "Tokenizer.hpp" 

bool check_for_single_line_comment_start(int& index, const std::string& code, bool& inside_single_line_comment)
{	
	if (code[index] == '/' && index + 1 < code.length() && code[index + 1] == '/')
	{
		index += 2;
		inside_single_line_comment = true;
		return true;
	}

	return false;
}

void check_for_single_line_comment_end(int& index, const std::string& code, bool& inside_single_line_comment)
{
	if (code[index++] == '\n')
	{
		inside_single_line_comment = false;
	}		
}

bool check_for_multiline_comment_start(int& index, const std::string& code, bool& inside_multiline_comment)
{                                               
	if (code[index] == '/' && index + 1 < code.length() && code[index + 1] == '*')
	{
		index += 2;
		inside_multiline_comment = true;
		return true;
	}     

	return false;
}

void check_for_multiline_comment_end(int & index, const std::string& code, bool& inside_multiline_comment)
{
	if (code[index] == '*' && index + 1 < code.length() && code[index + 1] == '/')
	{
		index += 2;
		inside_multiline_comment = false;
	}
	else
	{
		index++;
	}
}

bool check_for_string_start(int& index, const std::string& code, std::string& current_token, bool& inside_string)
{
    if (code[index] == '"')
    {
		current_token += code[index++];
		inside_string = true;
		return true;
    }

    return false;
}

void check_for_string_end(int& index, const std::string& code, std::string& current_token, bool& inside_string)
{
	if (code[index] == '"')
	{
		if (!(current_token.length() > 0 && current_token.back() == '\\'))
		{
			inside_string = false;	
		}	
	}
	current_token += code[index++];
}

bool check_for_char_start(int& index, const std::string& code, std::string& current_token, bool& inside_char)
{
    if (code[index] == '\'')
    {
		current_token += code[index++];
		inside_char = true;
		return true;
    }

    return false;	
}

void check_for_char_end(int& index, const std::string& code, std::string& current_token, bool& inside_char)
{
	if (code[index] == '\'')
	{
		if (!(current_token.length() > 0 && current_token.back() == '\\'))
		{
			inside_char = false;	
		}	
	}
	current_token += code[index++];
}

bool check_for_whitespace(int& index, const std::string& code)
{
	if (is_space(code[index]))
	{
		index++;
		return true;
	}	

	return false;
}

TOKENIZE_RESULT tokenize(const std::string& code)
{
	TOKENIZE_RESULT result = {
		SUCCESS,
		{},
		{}
	};
	int index = 0;
	bool inside_single_line_comment = false;
	bool inside_multiline_comment = false;
	bool inside_string = false;
	bool inside_char = false;
	std::string current_token = "";                                                    
	while (index < code.length())
	{
		if (inside_single_line_comment)
		{
			check_for_single_line_comment_end(index, code, inside_single_line_comment);
			continue;
		}
		if (inside_multiline_comment)
		{
			check_for_multiline_comment_end(index, code, inside_multiline_comment);
			continue;
		}
		if (inside_string)
		{
			check_for_string_end(index, code, current_token, inside_string);
			if (!inside_string)
			{
				result.tokens.push_back(current_token);
				current_token = "";			
			}
			continue;
		}
		if (inside_char)
		{
			check_for_char_end(index, code, current_token, inside_char);
			if (!inside_char)
			{
				result.tokens.push_back(current_token);
				current_token = "";
			}
			continue;
		}
		
		if (check_for_single_line_comment_start(index, code, inside_single_line_comment)) continue;
		if (check_for_multiline_comment_start(index, code, inside_multiline_comment)) continue;
		if (check_for_string_start(index, code, current_token, inside_string)) continue;
		if (check_for_char_start(index, code, current_token, inside_char)) continue;
		if (check_for_whitespace(index, code)) 
		{
			if (current_token.length() > 0)
			{
				result.tokens.push_back(current_token);
			}
			continue;
		}
		index++;
	}
	
	return result;
}

void print_tokens(const std::vector<std::string>& tokens)
{
	for (int i = 0; i < tokens.size(); i++)
	{
		printf("%s%c %c", tokens[i].c_str(), i < tokens.size() - 1 ? ',' : 0, i % 5 == 4 ? '\n' : 0);
	}
}