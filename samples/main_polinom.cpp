

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "monom.h"
#include "list.h"
#include "polinom.h"

int main()
{
	int	n;
	List<Monom> L1;
	List<Monom> L2;
	List<Monom> L3;
	List<Monom> L4;
	List<Monom> L5;
	Polinom	P1(&L1);
	Polinom	P2(&L2);
	Polinom	P3(&L3);
	Polinom	P4(&L4);
	Polinom	P5(&L5);
	Monom	M;
	int	flag;
	double	coeff;
	int	degree;

	cout << "\n Enter polinom1:" << flush;
	flag = 1;
	while( flag )
	{
		cout << "\n Enter monom:" << flush;
		cout << "\n Enter coeff:\n" << flush;
		cin >> coeff;
		M.SetCoeff(coeff);
		cout << "\n Enter degree:\n" << flush;
		cin >> degree;
		M.SetDeg(degree);
		P1.AddElem(M);
		cout << "\n Would you like to continue: 1/0\n" << flush;
		cin >> flag;
	}
//	L1.PrintList_polinom();
	L1.SortList();

	cout << "\n\n Enter polinom2:" << flush;
	flag = 1;
	while( flag )
	{
		cout << "\n Enter monom:" << flush;
		cout << "\n Enter coeff:\n" << flush;
		cin >> coeff;
		M.SetCoeff(coeff);
		cout << "\n Enter degree:\n" << flush;
		cin >> degree;
		M.SetDeg(degree);
		P2.AddElem(M);
		cout << "\n Would you like to continue: 1/0\n" << flush;
		cin >> flag;
	}
//	L2.PrintList_polinom();
	L2.SortList();

//	L1.PrintList_polinom();
//	L2.PrintList_polinom();
	P1.Print();
	P2.Print();

	P3.Add(&P1, &P2);
	P3.Print();

	P4.Sub(&P1, &P2);
	P4.Print();

	P5.Mul(&P1, &P2);
	P5.Print();

	return 0;
}
