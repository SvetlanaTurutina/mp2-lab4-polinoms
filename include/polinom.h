
// класс Полином - упорядоченный односвязный список Мономов
// поддерживает операции Печать, Вставка монома, Удаление монома,  
// Поиск монома, Сложение полиномов(слияние упорядоченных списков), 
// Умножение полиномов
#pragma once

#include "monom.h"
#include "list.h"

class Polinom
{
public:
	List<Monom> *polinom;
	//Monom *Data;
	int size;

	Polinom() { polinom=NULL, size = 0;};
	Polinom(List<Monom> *list)
	{
		polinom = list;
		size = (*list).GetSize();
	};
	Polinom(const Polinom &p);    //
	
	int GetSize() { return size; };
	List<Monom>* GetList() { return polinom; };
	void AddElem(Monom m);
	void Print();
	void Add(Polinom *p1, Polinom *p2);
	void Sub(Polinom *p1, Polinom *p2);
	void Mul(Polinom *p1, Polinom *p2);

	Polinom& operator= (Polinom &p);  //
//	Polinom& operator+ (const Polinom& p1, const Polinom& p2);  //
	Polinom& operator- (Polinom &p);  //
	Polinom& operator* (Polinom &p);  //

	friend ostream& operator<< (ostream &os, Polinom &p);
};
void Polinom::AddElem(Monom m)
{
	(*polinom).AddElem(m);
	size = (*polinom).GetSize();
}

void Polinom::Print()
{
	int n, i;
	Monom	d;
	double	coeff;
	int		degree;
	int		degree_x, degree_y, degree_z;
	Elem<Monom>	*ptr;
	n = (*polinom).GetSize();
	ptr = (*polinom).GetFirst();
	cout << "\n" << flush;
	for( i=0; i<n; i++ )
	{
		d = (*ptr).GetValue();
		coeff = d.GetCoeff();
		degree = d.GetDeg();
		degree_x = degree/100;
		degree_y = degree%100;
		degree_z = degree_y%10;
		degree_y = degree_y/10;
		if( i==0 )
			cout << coeff << "*x^" << degree_x << "*y^" << degree_y << "*z^" << degree_z << flush;
		else
			if( coeff > 0. )
				cout << " + " << coeff << "*x^" << degree_x << "*y^" << degree_y << "*z^" << degree_z << flush;
			else
				cout << coeff << "*x^" << degree_x << "*y^" << degree_y << "*z^" << degree_z << flush;
		ptr = (*ptr).GetNext();
	}
}

//const Polinom& operator+(const Polinom& p1, const Polinom& p2)
//{
//	List<Monom> L;
//	Elem<Monom>	*ptr1, *ptr2;
//	ptr1 = *(p1->polinom).GetFirst();
//	ptr2 = *(p2->polinom).GetFirst();
//	return *this;
//}

void Polinom::Add(Polinom *p1, Polinom *p2)
{
	List<Monom> *l1, *l2;
	Elem<Monom>	*ptr1, *ptr2;
	Monom		d1, d2, m;
	int			ind1, ind2;
	double		c;
	int			degree;
	int	n1, n2;
	l1 = (*p1).GetList();
	l2 = (*p2).GetList();
	n1 = (*l1).GetSize();
	n2 = (*l2).GetSize();
	ptr1 = (*l1).GetFirst();
	ptr2 = (*l2).GetFirst();
	ind1 = 0;
	ind2 = 0;
	while( (ind1 < n1) && (ind2 < n2) )
	{
		d1 = (*ptr1).GetValue();
		d2 = (*ptr2).GetValue();
		if( d1 < d2 )
		{
			(*this->polinom).AddElem(d1);
			ind1++;
			ptr1 = (*ptr1).GetNext();
		}
		else if( d1 == d2 )
		{
			c = d1+d2; 
			degree = d1.GetDeg();
			m.SetCoeff(c);
			m.SetDeg(degree);
			(*this->polinom).AddElem(m);
			ind1++;
			ind2++;
			ptr1 = (*ptr1).GetNext();
			ptr2 = (*ptr2).GetNext();
		}
		else
		{
			(*this->polinom).AddElem(d2);
			ind2++;
			ptr2 = (*ptr2).GetNext();
		}
	}
	while( ind1 < n1 )
	{
		d1 = (*ptr1).GetValue();
		(*this->polinom).AddElem(d1);
		ind1++;
		ptr1 = (*ptr1).GetNext();
	}
	while( ind2 < n2 )
	{
		d2 = (*ptr2).GetValue();
		(*this->polinom).AddElem(d2);
		ind2++;
		ptr2 = (*ptr2).GetNext();
	}
}

void Polinom::Sub(Polinom *p1, Polinom *p2)
{
	List<Monom> *l1, *l2;
	Elem<Monom>	*ptr1, *ptr2;
	Monom		d1, d2, m;
	int			ind1, ind2;
	double		c;
	int			degree;
	int	n1, n2;
	l1 = (*p1).GetList();
	l2 = (*p2).GetList();
	n1 = (*l1).GetSize();
	n2 = (*l2).GetSize();
	ptr1 = (*l1).GetFirst();
	ptr2 = (*l2).GetFirst();
	ind1 = 0;
	ind2 = 0;
	while( (ind1 < n1) && (ind2 < n2) )
	{
		d1 = (*ptr1).GetValue();
		d2 = (*ptr2).GetValue();
		if( d1 < d2 )
		{
			(*this->polinom).AddElem(d1);
			ind1++;
			ptr1 = (*ptr1).GetNext();
		}
		else if( d1 == d2 )
		{
			c = d1-d2; 
			degree = d1.GetDeg();
			m.SetCoeff(c);
			m.SetDeg(degree);
			(*this->polinom).AddElem(m);
			ind1++;
			ind2++;
			ptr1 = (*ptr1).GetNext();
			ptr2 = (*ptr2).GetNext();
		}
		else
		{
			c = d2*(-1); 
			degree = d2.GetDeg();
			m.SetCoeff(c);
			m.SetDeg(degree);
			(*this->polinom).AddElem(m);
			ind2++;
			ptr2 = (*ptr2).GetNext();
		}
	}
	while( ind1 < n1 )
	{
		d1 = (*ptr1).GetValue();
		(*this->polinom).AddElem(d1);
		ind1++;
		ptr1 = (*ptr1).GetNext();
	}
	while( ind2 < n2 )
	{
		c = d2*(-1); 
		degree = d2.GetDeg();
		m.SetCoeff(c);
		m.SetDeg(degree);
		(*this->polinom).AddElem(m);
		ind2++;
		ptr2 = (*ptr2).GetNext();
	}
}

void Polinom::Mul(Polinom *p1, Polinom *p2)
{
	List<Monom> *l1, *l2;
	Elem<Monom>	*ptr1, *ptr2;
	Monom		d1, d2, m;
	int			n1, n2;
	int			i, j;
	double		c1, c2;
	int			degree1, degree2;
	n1 = (*p1).GetSize();
	n2 = (*p2).GetSize();
	l1 = (*p1).GetList();
	l2 = (*p2).GetList();
	ptr1 = (*l1).GetFirst();
	for( i=0; i<n1; i++ )
	{
		d1 = (*ptr1).GetValue();
		c1 = d1.GetCoeff();
		degree1 = d1.GetDeg();
		ptr2 = (*l2).GetFirst();
		for( j=0; j<n2; j++ )
		{
			d2 = (*ptr2).GetValue();
			c2 = d2.GetCoeff();
			degree2 = d2.GetDeg();
			m.SetCoeff(c1*c2);
			m.SetDeg(degree1+degree2);
			this->AddElem(m);
			ptr2 = (*ptr2).GetNext();
		}
		ptr1 = (*ptr1).GetNext();
	}
}

