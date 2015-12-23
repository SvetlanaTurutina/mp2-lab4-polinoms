#include "monom.h"


Monom& Monom::operator= (const Monom &m)
{
	if (this == &m) {
		return *this;
	}
	Coeff = m.Coeff; 
	Deg = m.Deg;
	return *this;
}

