#include <iostream>
#include <limits>
#include "zlomok.h"

int otestujKladneCislo()
{
	int pocet;
	while(true)
	{
		try
		{
			if(!(std::cin >>pocet))
			{
				throw notNumber("Nebolo zadane cislo.");

			}
			if(pocet<=0)
			{
				throw notPositive("Zadane cislo musi byt vacie ako nula.");
			}
		}
		catch (const notNumber & ex)
		{
			ex.getMsg();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			//std::cin.ignore(100000,'\n');
			std::cout <<"Zadaj znova: ";
			continue;
		}
		catch( const notPositive & ex)
		{
			ex.getMsg();
			std::cout <<"Zadaj znova: ";
			continue;
		}
		break;
	}
	return pocet;
}