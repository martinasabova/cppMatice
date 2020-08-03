#include <iostream>
#include <limits>
#include "zlomok.h"
#include "funkcie.h"
#include "inverzna.h"
#include "determinant.h"

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

int zistiCo()
{
	std::string pokyny ="Na vypocet \n determinantu zadajte 1 \n inverznej matice zadajte 2 \n oboch zadajte 3 \n sustavy rovnic zadajte 4\n";
	int ktore=0;
	std::cout <<pokyny;
	while (true)
	{
		try
		{
			if(!(std::cin >>ktore))
			{
				throw notNumber("Nebolo zadane cislo.");
			}
			if(ktore<=0 || ktore>4)
			{
				throw wrongNumber("Zadane cislo nie je v ponuke.");
			}

		}
		catch (const notNumber & ex)
		{
			ex.getMsg();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			//std::cin.ignore(100000,'\n');
			std::cout <<pokyny <<std::endl;
			continue;
		}
		catch( const wrongNumber & ex)
		{
			ex.getMsg();
			std::cout <<pokyny <<std::endl;
			continue;
		}
		break;
	}
	return ktore;
}

void obe()
{
	determinant();
	inverzna();
}

void wrongNumber::getMsg() const
{
	std::cout <<msg <<std::endl;
}
