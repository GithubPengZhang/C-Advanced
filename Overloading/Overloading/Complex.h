
#pragma once
#include <iostream>

using namespace std;

namespace CaveOfComplex
{
	class Complex
	{
	private:
		double real;
		double imaginary;
	
	public:
		~Complex();
		Complex();
		Complex(double real, double imaginary);
		Complex(const Complex &other);
		const Complex & operator=(const Complex & other);
		bool operator==(const Complex &other) const;
		bool operator!=(const Complex &other) const;
		Complex operator*() const;
	
	public:
		void clone(const Complex &other);
	
		double GetReal() const;
		void SetReal(double val);
	
		double GetImaginary() const;
		void SetImaginary(double val);
	};
	
	ostream &operator<<(ostream &out, const Complex &other);
	Complex operator+ (const Complex &c1, const Complex &c2);
	Complex operator+ (const Complex &c1, double d);

}