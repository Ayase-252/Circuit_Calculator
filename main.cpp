#include <string>
#include <iostream>
#include "Parser.h"
#include "Complex.h"
std::wstring version(L"1.0.0");


int main()
{
	std::wstring input;
	std::wcout << "Circuit Calculator Interactive Mode" << std::endl
		<< "Version: " << version << std::endl
		<< "Programmed by AragakiAyase in 2014."
		<< "Push Ctrl-Z to terminate the program" << std::endl;
	while (std::wcin >> input)
	{
		try
		{
			std::cout << evalrpn(infixtorpn(input))<<std::endl;
		}
		catch (std::runtime_error)
		{
			std::wcerr << "The expression input ( " << input <<
				" ) goes wrong, please recheck it." << std::endl;
		}
	}

}
