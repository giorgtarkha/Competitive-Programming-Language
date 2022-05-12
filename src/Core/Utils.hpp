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

#endif
