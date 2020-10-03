#include <iostream>
#include "zlomok.h"
#include "funkcie.h"
#include "determinant.h"
#include "inverzna.h"
#include "rovnice.h"

int main()
{
	void (*pFunkcie[]) ()={determinant, inverzna, obe, rovnice};
	pFunkcie[zistiCo()-1]();
	return 0;
}
