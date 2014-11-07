#include <string>  //std::string
#include <vector>  //std::vector
#include <stack>   //std::stack
#include <cctype>  //isdigit()
#include <iostream>

int comparePiority(const char lhs, const char rhs); // lhs>rhs returns 1, lhs=rhs returns 0, lhs<rhs return -1
int getPiority(const char oper);

std::string infixtorpn(const std::string &infix)
{
	std::stack<char> op_stk;
	std::string res;
	for(auto iter=infix.begin();
			iter!=infix.end()||!op_stk.empty();
			/*Empty*/)
	{
		if (iter==infix.end()&&!op_stk.empty())
		{
			while(!op_stk.empty())
			{
				char c = op_stk.top();
				res.append(1,c);
				res.append(" ");
				op_stk.pop();
			}		
		}
		else if(std::isdigit(*iter))
		{
			auto beg=iter;
			while (iter != infix.end()&&(std::isdigit(*iter) || *iter == '.'))
			{
				++iter;
			}
			res.append(infix,beg-infix.begin(),iter-beg);
			res.append(" "); //for spacing
		}
		else if(*iter=='(')
		{
			op_stk.push(*iter);
			++iter;
		}
		else if(*iter==')')
		{
			while(op_stk.top()!='(')
			{
				const char c = op_stk.top();
				res.append(1,c);
				res.append(" ");
				op_stk.pop();
			}
			op_stk.pop(); //pop '('
			++iter;
		}
		else //for other operator
		{
			if (!op_stk.empty())
			{
				while (!op_stk.empty()&&comparePiority(op_stk.top(), *iter) > -1)
				{
					const char c = op_stk.top();
					res.append(1, c);
					res.append(" ");
					op_stk.pop();
				}
			}
			op_stk.push(*iter);
			++iter;
		}
	}
	return res;
}

int comparePiority(const char lhs, const char rhs)
{
	if(getPiority(lhs)>getPiority(rhs))
		return 1;
	else if(getPiority(lhs)==getPiority(rhs))
		return 0;
	else
		return -1;
}

int getPiority(const char oper)
{
	switch(oper)
	{
		case '(':
			return 1;
		case '+':
		case '-':
			return 2;
		case '|':
		case '*':
		case '/':
			return 3;
		case '^':
			return 4;
	}
}

int main()
{

	std::string str;
	std::cin>>str;
	std::cout<<infixtorpn(str);
	return 0;
}
