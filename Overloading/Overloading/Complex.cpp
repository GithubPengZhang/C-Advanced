#include "Complex.h"

namespace CaveOfComplex
{
	Complex::Complex(): real(0.0), imaginary(0.0)
	{
	}
	
	
	Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary)
	{
	
	}
	
	Complex::Complex(const Complex &other)
	{
		this->clone(other);
	}
	
	const Complex & Complex::operator=(const Complex & other)
	{
		this->clone(other);
		return *this;
	}

	bool Complex::operator==(const Complex & other) const
	{
		return (real == other.GetReal() && imaginary == other.GetImaginary());
	}

	bool Complex::operator!=(const Complex & other) const
	{
		return !(*this==other);
	}

	Complex Complex::operator*() const
	{
		return Complex(GetReal(), -GetImaginary());
	}

	void Complex::clone(const Complex &other)
	{
		SetReal(other.GetReal());
		SetImaginary(other.GetImaginary());
	}
	
	double Complex::GetReal() const
	{
		return real;
	}

	void Complex::SetReal(double val)
	{
		real = val;
	}

	double Complex::GetImaginary() const
	{
		return imaginary;
	}

	void Complex::SetImaginary(double val)
	{
		imaginary = val;
	}

	Complex::~Complex()
	{
	}
	
	std::ostream & operator<<(ostream &out, const Complex &other)
	{
		out << "(" << other.GetReal() << "," << other.GetImaginary() << ")";
		return out;
	}

	Complex operator+(const Complex &c1, const Complex &c2)
	{
		return Complex(c1.GetReal() + c2.GetReal(), c1.GetImaginary() + c2.GetImaginary());
	}

	Complex operator+(const Complex & c1, double d)
	{
		return Complex(c1.GetReal(),c1.GetImaginary()+d);
	}

}
