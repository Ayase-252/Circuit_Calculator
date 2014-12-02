#include <cmath>
#include <sstream>
#include "Complex.h"

int Complex::display_mode = 0;

Complex::Complex(const double re, const double im) :real(re), imaginary(im)
{

}

Complex::Complex(const Complex &rhs) : real(rhs.real), imaginary(rhs.imaginary)
{

}

Complex&
Complex::operator=(const Complex &rhs)
{
	real = rhs.real;
	imaginary = rhs.imaginary;
	return *this;
}

Complex&
Complex::operator+=(const Complex &rhs)
{
	real += rhs.real;
	imaginary += rhs.imaginary;
	return *this;
}

Complex
operator+(const Complex &lhs, const Complex &rhs)
{
	auto res(lhs);
	res += rhs;
	return res;
}

Complex&
Complex::operator-=(const Complex &rhs)
{
	real -= rhs.real;
	imaginary -= rhs.imaginary;
	return *this;
}

Complex
operator-(const Complex &lhs, const Complex &rhs)
{
	auto res(lhs);
	res -= rhs;
	return res;
}

Complex&
Complex::operator*=(const Complex &rhs)
{
	double ori_real = real;
	double ori_imaginary = imaginary;
	real = ori_real*rhs.real - ori_imaginary*rhs.imaginary;
	imaginary = ori_real*rhs.imaginary + ori_imaginary*rhs.real;
	return *this;
}

Complex
operator*(const Complex &lhs, const Complex &rhs)
{
	auto res(lhs);
	res *= rhs;
	return res;
}

Complex&
Complex::operator/=(const Complex &rhs)
{
	//when we have equation a1+b1i/a2+b2i,
	//we can calculate this by
	//(a1+b1i)(a2-b2i)/(a2^2+b2^2)
	*this *= Complex(rhs.real, -rhs.imaginary);
	real /= rhs.real*rhs.real + rhs.imaginary*rhs.imaginary;
	imaginary /= rhs.real*rhs.real + rhs.imaginary*rhs.imaginary;
	return *this;
}

Complex
operator/(const Complex &lhs, const Complex &rhs)
{
	auto res(lhs);
	res /= rhs;
	return res;
}

double
Complex::GetArugment() const
{
	return std::atan2(imaginary, real);
}

double
Complex::GetArugmentd() const
{
	return GetArugment() / pi * 180;
}

double
Complex::GetAbs() const
{
	return std::sqrt(real*real + imaginary*imaginary);
}

void
Complex::SetDisplayMode(int disp)
{
	display_mode = disp;
}

std::wstring
Complex::Getwstring() const
{
	std::wstring res;
	if (display_mode == 0)
	{
		res.append(std::to_wstring(real));
		if (imaginary > 0)
		{
			res.append(L"+" + std::to_wstring(imaginary)+L"i");
		}
		else
		{
			res.append(L"-" + std::to_wstring(imaginary)+L"i");
		}
	}
	else
	{
		res.append(std::to_wstring(GetAbs()) + L'D' + std::to_wstring(GetArugmentd()));
	}
	return res;
}

std::wostream&
operator<<(std::wostream &os, const Complex &rhs)
{
	os << rhs.Getwstring();
	return os;
}