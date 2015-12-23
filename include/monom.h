// класс или структура Монома (double коэффициент, целая свернутая степень)

// класс или структура Монома (double коэффициент, целая свернутая степень)
#pragma once

#include <iostream>

using namespace std;


class Monom
{
private:

	double Coeff;
	int Deg;

public:
	Monom() { Coeff = 0; Deg = 0; }
	Monom(double cval, int dval) { Coeff = cval; Deg = dval; }
	Monom(const Monom &m) { Coeff = m.GetCoeff(); Deg = m.GetDeg(); };
	
	void SetCoeff(double cval) { Coeff = cval; }
	double GetCoeff() const { return Coeff; }
	void SetDeg(int dval) { Deg = dval; }
	int GetDeg() const { return Deg; }

	Monom& operator= (const Monom &m);// { Coeff = m.Coeff; Deg = m.Deg; return *this; }
	//bool operator!= (const Monom &m);
//	bool operator==  (const Monom &m) { return ((Coeff == m.Coeff) && (Deg == m.Deg)); }
	int operator== (const Monom &m) { return (Deg == m.Deg); }
	int operator< (const Monom &m) { return Deg < m.Deg; }
	double operator+ (const Monom &m) { return Coeff+m.Coeff; }
	double operator- (const Monom &m) { return Coeff-m.Coeff; }
	double operator* (double v) { return Coeff*v; }
	
	friend ostream& operator<< (ostream &os, Monom &m) { os << m.Coeff << " " << m.Deg; return os; }
	
};