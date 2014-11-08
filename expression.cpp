/**************************
 * Author: AragakiAyase(Deng Qingyu)
 * Revise Time: Sat Nov  8 15:23:49 CST 2014 
 * Email: bitdqy@hotmail.com
 * description: all of Circuit_Calculator
 **************************/
#include <string>  //std::string
#include <vector>  //std::vector
#include <stack>   //std::stack
#include <cctype>  //isdigit()
#include <cstdlib> //stod()
#include <map>     //std::map
#include <iostream>

std::string version("1.0.0");

//declaration of operation function
double plus(double, double);
double subtract(double, double);
double multiple(double, double);
double divide(double, double);
double parallel(double, double);

std::map<char, double(*)(double, double)> oper_map
{
	std::make_pair('+', plus),
	std::make_pair('-', subtract),
	std::make_pair('*', multiple),
	std::make_pair('/', divide),
	std::make_pair('|', parallel)
};

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

double evalrpn(const std::string &rpn)
{
	std::stack<double> stk;
	for (auto iter = rpn.begin();
		iter != rpn.end();
		/*Empty*/)
	{ 
		if (std::isdigit(*iter))
		{
			auto beg = iter;			
			while (*iter != ' ') //make iter reaching spacing char
			{
				++iter;
			}
			stk.push(std::stod(rpn.substr(beg - rpn.begin())));
			++iter; //points to the next
		}
		else //the iter points to an operator
		{
			if (stk.size() > 1)
			{
				double lhs = stk.top();
				stk.pop();
				double rhs = stk.top();
				stk.pop();
				stk.push(oper_map.find(*iter)->second(lhs, rhs));
			}
			else //something goes wrong
			{
				throw std::runtime_error("The expression is illegl");
			}
			++iter;//to skip spacing char
			++iter; 
		}
	}
	return stk.top(); 
}

double plus(double lhs, double rhs)
{
	return lhs + rhs;
}

double subtract(double lhs, double rhs)
{
	return lhs - rhs;
}

double multiple(double lhs, double rhs)
{
	return lhs*rhs;
}

double divide(double lhs, double rhs)
{
	return lhs / rhs;
}

double parallel(double lhs, double rhs)
{
	return (1 / ((1 / lhs) + (1 / rhs)));
}

int main()
{
	std::string input;
	std::cout << "Circuit Calculator Interactive Mode" << std::endl
		<< "Version: " << version << std::endl
		<< "Programmed by AragakiAyase in 2014."
		<< "Push Ctrl-Z to terminate the program" << std::endl;
	while (std::cin >> input)
	{
		try
		{
			std::cout << evalrpn(infixtorpn(input))<<std::endl;
		}
		catch (std::runtime_error)
		{
			std::cerr << "The expression input ( " << input <<
				" ) goes wrong, please recheck it." << std::endl;
		}
	}
}
