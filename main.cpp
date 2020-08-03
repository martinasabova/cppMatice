#include <iostream>
#include <limits>
#include "zlomok.h"
#include "funkcie.h"
#include "determinant.h"
#include "inverzna.h"

int main()
{
	void (*pFunkcie[]) ()={determinant, inverzna, obe};
	pFunkcie[zistiCo()-1]();

	return 0;
}
