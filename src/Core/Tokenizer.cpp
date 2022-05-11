#include "Tokenizer.hpp" 

bool check_for_single_line_comment(int& index, std::string& code, bool& inside_single_line_comment, 
								   bool inside_multiline_comment, bool inside_string)
{	
	if (inside_multiline_comment || inside_string) return false;
	if (inside_single_line_comment)
	{
		if (code[index++] == '\n')
		{
			inside_single_line_comment = false;
		}	
		return true;
	} 

	if (code[index] == '/' && index + 1 < code.length() && code[index] == '/')
	{
		index += 2;
		inside_single_line_comment = true;
		return true;
	}

	return false;
}

bool check_for_multiline_comment(int& index, std::string& code, bool& inside_multiline_comment,
								bool inside_single_line_comment, bool inside_string)
{                                               
	if (inside_single_line_comment || inside_string) return false;
	if (inside_multiline_comment)
	{
		if (code[index] == '*' && index + 1 < code.length() && code[index + 1] == '/')
		{
			index += 2;
			inside_multiline_comment = false;
		}
		else
		{
			++index;
		}
		return true;
	}
	if (code[index] == '/' && index + 1 < code.length() && code[index + 1] == '*')
	{
		index += 2;
		inside_multiline_comment = true;
		return true;
	}     
	return false;
}

TOKENIZE_RESULT tokenize(std::string& code)
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
	while (index < code.length())
	{
		if (check_for_single_line_comment(index, code, inside_single_line_comment,
										  inside_multiline_comment, inside_string)) continue;
		if (check_for_multiline_comment(index, code, inside_multiline_comment,
										inside_single_line_comment, inside_string)) continue;     
	}	
	return result;
}