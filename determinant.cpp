#include <iostream>
#include "zlomok.h"
#include "funkcie.h"
#include "determinant.h"

void determinant()
{
	int n; //rozmer
	std::cout <<"Rozmer: ";
	n=otestujKladneCislo();
	Zlomok * matica;
	try
	{
		matica=new Zlomok [n*n];
	}
	catch (std::bad_alloc &ba)
	{
		std::cout <<ba.what() <<std::endl;
		exit(EXIT_FAILURE);
	}
	nacitaj(n, matica);
	Zlomok determinant=vypocitaj(matica, n);
	std::cout <<std::endl <<"Determinant" <<std::endl <<determinant <<std::endl;
	delete [] matica;
}

void determinant(Zlomok *matrix, int rozmer)
{
	Zlomok determinant=vypocitaj(matrix, rozmer);
	std::cout <<std::endl <<"Determinant" <<std::endl <<determinant <<std::endl;
}

void nacitaj(int kolko, Zlomok * matrix)
{
	for (int i=0; i<kolko*kolko; ++i)
	{
		if(i%kolko==0)
		{
			std::cout <<i/kolko+1 <<" riadok: ";
		}
		std::cin >>*(matrix+i);
	}
}

Zlomok vypocitaj (Zlomok * pole, int velkost)
{
	if(velkost*velkost==4)	//ak je matica 2x2, vypocita to rovno determinant
	{
		Zlomok a=(*pole)*(*(pole+3));
		Zlomok b=(*(pole+1))*(*(pole+2));
		return a-b;
	}
	Zlomok vysledok(0,1);
	for (int i=0; i<velkost; ++i)	//zopakuje sa to tolkokrat, aky je stupen matice
	{
		int poziciaPovodne=0;	//pozicia v povodnom poli
		int pomocneVelkost=(velkost-1)*(velkost-1);	//velkost noveho pola pre maticu nizsieho stupna
		Zlomok  * pomocnePole;
		try
		{
			pomocnePole=new Zlomok [pomocneVelkost];
		}
		catch (std::bad_alloc &ba)
		{
			std::cout <<ba.what() <<std::endl;
			exit(EXIT_FAILURE);
		}
		for (int j=0; j<(velkost-1)*(velkost-1); ++j)	//vytvorenie novej matice o stupen nizsej, rozvoj podla posledneho riadka
		{
			if(poziciaPovodne%velkost==i)	//ak je to prave stlpec, co sa vynechava
			{
				++poziciaPovodne;	//preskoci sa hodnota
				--j;				//aby sa ale nepreskocilo miesto v novom poli
			}
			else
			{
				*(pomocnePole+j)=*(pole+poziciaPovodne);	//zapise sa hodnota do noveho
				++poziciaPovodne;
			}
		}
		int znamienko = ((i+1+velkost)%2==0) ? 1: -1;	//ci treba dat plus alebo minus
		vysledok+=(vypocitaj(pomocnePole, velkost-1)*znamienko*(*(pole+i+(velkost*(velkost-1)))));	//pripocitanie k medzisuctu
		delete [] pomocnePole;	//uvolnenie pomocneho
	}
	return vysledok;
}
