#include <iostream>
#include "zlomok.h"
#include "funkcie.h"
#include "rovnice.h"

void rovnice()
{
	std::cout <<"Pocet neznamych: ";
	int n=otestujKladneCislo(); //pocet neznamych
	Zlomok **sustava;
	sustavaRovnic::alokuj(&sustava, n);
	nacitaj(sustava, n);
	vypocitaj(sustava, n);
	if(sustavaRovnic::skontroluj(sustava,n)==1)	//ci ma riesenie alebo pripadne nekonecne vela
	{
		sustavaRovnic::uvolni(sustava, n);
		exit(0);
	}
	auto * korene = new Zlomok [n];
	vypocitajKorene(sustava, korene, n);
	sustavaRovnic::uvolni(sustava, n);
	delete [] korene;
}

void sustavaRovnic::alokuj(Zlomok ***matica, int kolko)
{
	try
	{
		*matica = new Zlomok * [kolko];
		for (int i=0; i<kolko; ++i)
		{
			*(*matica+i)= new Zlomok [kolko+1];	//stlpcov ma o jeden viac, lebo je tam prava strana rovnice
		}
	}
	catch(std::bad_alloc &ba)
	{
		std::cout <<ba.what() <<std::endl;
		exit(EXIT_FAILURE);
	}

}

void nacitaj(Zlomok **matica, int kolko)
{
	for (int i=0; i<kolko; ++i)
	{
		std::cout <<i+1 <<" rovnica" <<std::endl;
		std::cout <<"lava strana koeficienty: ";
		for (int j=0; j<kolko; ++j)
		{
			std::cin >>(*((*(matica+i))+j));
		}
		std::cout <<"prava strana: ";
		std::cin >>*((*(matica+i))+kolko);
	}
}

void vypocitaj(Zlomok ** matica, int kolko)
{
	for (int i=0;i<kolko;++i) //vynulovanie pod
	{
		int dole=i+1;
		while (dole<kolko)
		{
			Zlomok k=(-1)*(matica[dole][i])/matica[i][i];
			for (int l=i;l<kolko+1;++l)
			{
				matica[dole][l]=matica[dole][l]+k*matica[i][l];
			}
			++dole;
		}
	}
	for (int i=1;i<kolko;++i) //vynulovanie nad
	{
		int hore=0;
		while(hore<i)
		{
			Zlomok k=(-1)*matica[hore][i]/matica[i][i];
			for (int l=i;l<kolko+1;++l)
			{
				matica[hore][l]=matica[hore][l]+k*matica[i][l];
			}
			++hore;
		}
	}
}

int sustavaRovnic::skontroluj (Zlomok **matica, int kolko)
{
	for(int i=0;i<kolko;++i)
	{
		if(matica[i][i].getCitatel()==0)
		{
			if (matica[i][kolko].getCitatel()==0)
			{
				std::cout <<"Sustava ma nekonecne vela rieseni.";
				return 1;
			}
			std::cout <<"Sustava nema riesenie.";
			return 1;
		}
	}
	return 0;
}

void vypocitajKorene(Zlomok ** matica, Zlomok * riesenia, int kolko)
{
	std::cout <<"K=[";
	for (int i=0;i<kolko;++i)
	{
		riesenia[i]=matica[i][kolko]/matica[i][i];
		std::cout <<riesenia[i];
		if (i!=kolko-1)
		{
			std::cout <<"; ";
		}
	}
	std::cout <<"]";
}

void sustavaRovnic::uvolni (Zlomok **matica, int kolko)
{
	for  (int i=0; i<kolko; ++i)
	{
		delete [] *(matica+i);
	}
	delete [] matica;
}