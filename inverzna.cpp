#include <iostream>
#include <iomanip>
#include "zlomok.h"
#include "inverzna.h"

void inverzna()
{
	Zlomok **povodna;
	Zlomok **inverzna;
	Zlomok **nemeniaca;
	std::cout <<"Zadaj rozmer matice: ";
	int rozmer=otestujKladneCislo();
	alokuj(&povodna, rozmer);
	alokuj(&inverzna, rozmer);
	alokuj(&nemeniaca, rozmer);
	nacitajPovodnu(povodna,nemeniaca,rozmer);
	spravJednotkovu(inverzna,rozmer);
	std::cout <<"Povodna:" <<std::endl;
	vypis(nemeniaca,rozmer);
	if(vypocitajInverznu(povodna, inverzna, rozmer)==1)	//aby sa nahodou nedelilo nulou
	{
		uvolni(povodna,rozmer);
		uvolni(inverzna,rozmer);
		uvolni(nemeniaca,rozmer);
		exit(0);
	}
	std::cout <<"Inverzna:" <<std::endl;
	vypis(inverzna,rozmer);
	vynasob(nemeniaca, inverzna, rozmer);
	uvolni(povodna,rozmer);
	uvolni(inverzna,rozmer);
	uvolni(nemeniaca,rozmer);
}

void alokuj (Zlomok ***matica, int hodnost)
{
	try
	{
		*matica=new Zlomok * [hodnost];
		for (int i=0; i<hodnost; ++i)
		{
			*(*matica+i)=new Zlomok [hodnost];
		}
	}
	catch(std::bad_alloc &ba)
	{
		std::cout <<ba.what() <<std::endl;
		exit(EXIT_FAILURE);
	}
}

void nacitajPovodnu(Zlomok **maticaMeni, Zlomok ** maticaNemeni, int hodnost)
{
	for (int i=0;i<hodnost;++i)
	{
		std::cout <<i+1 <<" riadok: ";
		for (int j=0;j<hodnost;++j)
		{
			std::cin >>(*((*(maticaMeni+i))+j));
			*((*(maticaNemeni+i))+j)=*((*(maticaMeni+i))+j);
		}
	}
}

void spravJednotkovu(Zlomok **matica, int hodnost)
{
	for (int i=0;i<hodnost;++i)
	{
		for(int j=0;j<hodnost;++j)
		{
			*((*(matica+i))+j)=(j==i)?Zlomok{1}:Zlomok{0,1};
		}
	}
}

int vypocitajInverznu(Zlomok ** maticaP, Zlomok ** maticaI, int hodnost)
{
	for (int i=0;i<hodnost;++i) //vynulovanie pod
	{
		int dole=i+1;
		while (dole<hodnost)
		{
			Zlomok k=(-1)*(maticaP[dole][i])/maticaP[i][i];
			for (int l=i;l<hodnost;++l)
			{
				maticaP[dole][l]=maticaP[dole][l]+k*maticaP[i][l];	//pre povodnu
			}
			for(int l=0; l<hodnost; ++l)
			{
				maticaI[dole][l]+=k*maticaI[i][l];	//pre inverznu
			}
			++dole;
		}
	}
	for (int i=1;i<hodnost;++i) //vynulovanie nad
	{
		int hore=0;
		while(hore<i)
		{
			Zlomok k=(-1)*maticaP[hore][i]/maticaP[i][i];
			for (int l=i;l<hodnost;++l) //pre povodnu
			{
				maticaP[hore][l]=maticaP[hore][l]+k*maticaP[i][l];
			}
			for(int l=0; l<hodnost; ++l) //pre inverznu
			{
				maticaI[hore][l]+=k*maticaI[i][l];
			}
			++hore;
		}
	}
	if (skontroluj(maticaP, hodnost)==1)
	{
		return 1;
	}
	for (int i=0;i<hodnost; ++i) //spravenie jednotkovej z povodnej
	{
		Zlomok k=maticaP[i][i];
		for (int j=0;j<hodnost;++j)
		{
			maticaI[i][j]=maticaI[i][j]/k;
			maticaP[i][j]=maticaP[i][j]/k;
		}
	}
	return 0;
}

int skontroluj (Zlomok **matica, int kolko)
{
	for(int i=0;i<kolko;++i)
	{
		if(matica[i][i].getCitatel()==0)
		{
			std::cout <<"Na hlavnej diagonale v povodnej matici je po uprave nula.\nInverzna neexistuje.";
			return 1;
		}
	}
	return 0;
}

void vynasob (Zlomok **maticaP, Zlomok ** maticaI, int kolko)
{
	Zlomok ** vynasobena;
	alokuj(&vynasobena, kolko);
	spravVynulovanu(vynasobena,kolko);
	for (int i=0;i<kolko;++i)
	{
		for (int j=0;j<kolko;++j)
		{
			for(int l=0;l<kolko;++l)
			{
				vynasobena[i][j]+=(maticaP[i][l]*maticaI[l][j]);
			}
		}
	}
	std::cout <<"Vynasobene" <<std::endl;
	vypis(vynasobena,kolko);
	uvolni(vynasobena,kolko);
}

void spravVynulovanu (Zlomok ** matica, int hodnost)
{
	for (int i=0;i<hodnost;++i)
	{
		for (int j=0;j<hodnost;++j)
		{
			*(*(matica+i)+j)=Zlomok{0,1};
		}
	}
}

void uvolni (Zlomok ** matica, int hodnost)
{
	for (int i=0;i<hodnost;++i)
	{
		delete [] *(matica+i);
	}
	delete [] matica;
}

void vypis(Zlomok ** matica, int hodnost)
{
	for (int i = 0; i < hodnost; ++i)
	{
		for (int j = 0; j < hodnost; ++j)
		{
			std::cout <<std::setw(6) <<*(*(matica + i) + j);
		}
		std::cout <<std::endl;
	}
}
