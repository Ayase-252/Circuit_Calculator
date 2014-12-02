#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <string>

const double pi = 3.1415926;

class Complex
{
	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);
public:
	Complex(const double, const double);
	Complex(const Complex&);
	Complex& operator=(const Complex&);
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);
	inline double GetRealPart() const;
	inline double GetImaginaryPart() const;
	double GetArugment() const;
	double GetArugmentd() const;
	double GetAbs() const;
	std::wstring Getwstring() const;
	void SetDisplayMode(int disp); //temperary function
private:
	double real;
	double imaginary;
	static int display_mode; //0 is a+bi,1 is abs(arg).
	
};

Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);
std::wostream& operator<<(std::wostream&, const Complex&);

double Complex::GetRealPart() const
{
	return real;
}

double Complex::GetImaginaryPart() const
{
	return imaginary;
}
#endif