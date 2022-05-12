#ifndef CPL_UTILS
#define CPL_UTILS

#include <string>

inline bool is_operator(const char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
		   c == '&' || c == '|' || c == '^';
}

inline bool is_operator(const std::string& s) 
{
	return s == "+" || s == "-" || s == "*" || s == "/" || s == "%" ||
		   s == "&" || s == "|" || s == "^" ||
		   s == "<<" || s == ">>";	
}

inline bool is_space(const char c)
{
	unsigned char uc = static_cast<unsigned char>(c);
	return uc == ' ' || uc == '\f' || uc == '\n' || uc == '\r' || uc == '\t' || uc == '\v';
}

#endif
