

#ifndef RPN_HPP
#define RPN_HPP
# include <queue>
# include <string>
# include <cstdlib>

class RPN
{
public:
	RPN();
	~RPN();
	RPN(const std::string &s);
	RPN(const RPN &rpn);
	RPN& operator=(const RPN &rpn);
	int get_result();
private:
	std::queue<char> calc;
};


#endif