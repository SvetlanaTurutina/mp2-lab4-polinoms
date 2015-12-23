#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


template <class T>
class Elem
{
private:
	T d;
	T *pd;
	Elem<T> *next;

public:
	Elem(T value)
	{ 
		d = value;
		pd = &d;
		next = NULL;
	}
	
	T GetValue() { return d; }
	T* GetAddr() { return pd; }
	Elem<T> *GetNext() { return next; }
	void SetNext(Elem<T> *ptr) { next = ptr; }

};


template <class T>
class List
{
private:
	int size;
	Elem<T> *first;
	Elem<T> *last;

public:
	List()
	{ 
		size = 0; 
		first = NULL;
		last = NULL;
	}
	~List()
	{
		Elem<T>	*ptr = first;
		Elem<T>	*ptr_next;
		int	i;
		for( i=0; i<size; i++ )
		{
			ptr_next = (*ptr).GetNext();
			delete ptr;
			ptr = ptr_next;
		}
		size = 0;
	}
	
	int IsEmpty()
	{
		if( (size==0) && (first==NULL) && (last==NULL) )
			return 1;
		else
			return 0;
	}
	int GetSize() const
	{
		return size;
	}
	Elem<T>* GetFirst() { return first; };
	void AddElem(T d);
	void PrintList();
//	void PrintList_polinom();
	void SortList();
};


template <class T>
void List<T>::AddElem(T d)
{
	Elem<T> *pElem = new Elem<T>(d);
	Elem<T> *Curr;
	if( this->size == 0 )
		this->first = pElem;
	else
	{
		Curr = this->last;
		(*Curr).SetNext(pElem);
	}
	this->last = pElem;
	this->size = size+1;
}

template <class T>
void List<T>::PrintList()
{
	int n, i;
	T	d;
	Elem<T>	*ptr;
	n = this->size;
	ptr = this->first;
	cout << "\n" << flush;
	for( i=0; i<n; i++ )
	{
		d = (*ptr).GetValue();
		cout << " " << d << flush;
		ptr = (*ptr).GetNext();
	}
}
/*void List<Monom>::PrintList_polinom()
{
	int n, i;
	Monom	d;
	double	coeff;
	int		degree;
	int		degree_x, degree_y, degree_z;
	Elem<Monom>	*ptr;
	n = this->size;
	ptr = this->first;
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
			cout << d.GetCoeff() << "*x^" << degree_x << "*y^" << degree_y << "*z^" << degree_z << flush;
		else
			cout << " + " << d.GetCoeff() << "*x^" << degree_x << "*y^" << degree_y << "*z^" << degree_z << flush;
		ptr = (*ptr).GetNext();
	}
}
*/
void List<Monom>::SortList()
{
	int n, i, j;
	Monom	d1, d2;
	Monom	*pd1, *pd2;
	double	coeff1, coeff_min;
	int		degree1, degree2, degree_min;
	Elem<Monom>	*ptr1, *ptr2, *ptr;
	n = this->size;
	ptr1 = this->first;
	for( i=0; i<n; i++ )
	{
		d1 = (*ptr1).GetValue();
		pd1 = (*ptr1).GetAddr();
		degree1 = d1.GetDeg();
		coeff1 = d1.GetCoeff();
		degree_min = degree1;
		ptr2 = (*ptr1).GetNext();
		ptr = NULL;
		for( j=i+1; j<n; j++ )
		{
			d2 = (*ptr2).GetValue();
			degree2 = d2.GetDeg();
			if( degree2 < degree_min )
			{
				degree_min = degree2;
				coeff_min = d2.GetCoeff();
				ptr = ptr2;
			}
			ptr2 = (*ptr2).GetNext();
		}
		if( ptr != NULL )
		{
//			d2 = (*ptr).GetValue();
			pd2 = (*ptr).GetAddr();
			(*pd1).SetDeg(degree_min);
			(*pd1).SetCoeff(coeff_min);
			(*pd2).SetDeg(degree1);
			(*pd2).SetCoeff(coeff1);
		}
		ptr1 = (*ptr1).GetNext();
	}
}