#ifndef CPL_UTILS
#define CPL_UTILS

#include <string>

typedef uint32_t uint;

inline bool is_operator(const char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
		   c == '&' || c == '|' || c == '^';
}

inline bool is_space(const char c)
{
	unsigned char uc = static_cast<unsigned char>(c);
	return uc == ' ' || uc == '\f' || uc == '\n' || uc == '\r' || uc == '\t' || uc == '\v';
}

inline bool is_splittable(const char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
		   c == '&' || c == '|' || c == '^' ||
		   c == '>' || c == '<' || c == '=' ||
		   c == '?' || c == ':' || 
		   c == '(' || c == ')' || c == '{' || c == '}'	|| c == '[' || c == ']' ||
		   c == ',' || c == ';';
}

inline bool is_datatype(const std::string& s)
{
	return s == "int" || s == "long" || s == "bigint" ||
		   s == "char" || s == "string" ||
		   s == "bool";
}

inline bool is_string(const std::string& s)
{
	return s.length() >= 2 && s.front() == '"' && s.back() == '"';
}

inline bool is_char(const std::string& s)
{
	return s.length() >= 2 && s.front() == '\'' && s.back() == '\'';
}

inline bool is_bool(const std::string& s)
{
	return s == "true" || s == "false";
}

inline bool is_number(const std::string& s)
{
	if (s.length() == 0) return false;
	for (int i = 0; i < s.length(); i++)
	{
		if ((s[i] <= '0' || s[i] >= '9') && s[i] != '_') return false;
	}
	return true;
}

#endif
