#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include "zlomok.h"


Zlomok Zlomok::operator+(const Zlomok &other) const
{
	Zlomok Novy(this->citatel*other.menovatel+other.citatel*this->menovatel, this->menovatel*other.menovatel);
	Novy.uprav();
	return Novy;
}

Zlomok Zlomok::operator-(const Zlomok &other) const
{
	Zlomok Novy(this->citatel*other.menovatel-other.citatel*this->menovatel, this->menovatel*other.menovatel);
	Novy.uprav();
	return Novy;
}

Zlomok Zlomok::operator*(const Zlomok &other) const
{
	Zlomok Novy(this->citatel*other.citatel, this->menovatel*other.menovatel);
	Novy.uprav();
	return Novy;
}

Zlomok Zlomok::operator/(const Zlomok &other) const
{
	Zlomok Novy(this->citatel*other.menovatel, this->menovatel*other.citatel);
	Novy.uprav();
	return Novy;
}

Zlomok Zlomok::operator*(int cislo) const
{
	Zlomok Novy{this->citatel*cislo, this->menovatel};
	Novy.uprav();
	return Novy;
}

Zlomok operator*(int cislo, const Zlomok &other)
{
	Zlomok Novy{other.citatel*cislo, other.menovatel};
	Novy.uprav();
	return Novy;
}

Zlomok &Zlomok::operator+=(const Zlomok &other)
{
	*this=*this+other;
	return *this;
}

Zlomok &Zlomok::operator-=(const Zlomok &other)
{
	*this=*this-other;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Zlomok &moj)
{
	(moj.menovatel==1)? out <<moj.citatel : out <<moj.citatel <<"/" <<moj.menovatel;
	return out;
}

std::istream &operator>>(std::istream &in, Zlomok &moj)
{
	std::string nacitane;
	std::cin >>nacitane;
	auto najdeneLomeno=nacitane.find('/');
	while(true)
	{
		try
		{
			if (najdeneLomeno == std::string::npos)
			{
				moj.menovatel = 1;
				moj.citatel = std::stoi(nacitane);
			}
			else
			{
				moj.citatel = std::stoi(nacitane);
				moj.menovatel = std::stoi(nacitane.substr(najdeneLomeno + 1));
			}
		}
		catch (const std::invalid_argument &ex)
		{
			std::cerr <<"Nebolo zadane cislo. " << "\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout <<"Znova: ";
			std::cin >>nacitane;
			najdeneLomeno=nacitane.find('/');
			continue;
		}
		break;
	}
	moj.uprav();
	return in;
}

void Zlomok::uprav()
{
	int vacsie=abs(this->citatel);
	int mensie=abs(this->menovatel);
	if (mensie>vacsie)
	{
		int tmp=mensie;
		mensie=vacsie;
		vacsie=tmp;
	}
	int delitel=Zlomok::euklidovAlgoritmus(vacsie, mensie);
	this->citatel=this->citatel/delitel;
	this->menovatel=this->menovatel/delitel;
	if(menovatel<0)
	{
		citatel*=(-1);
		menovatel*=(-1);
	}
}

int Zlomok::euklidovAlgoritmus(int viac, int menej)
{
	while (menej!=0)
	{
		int prechodneVacsie=menej;
		menej=viac%menej;
		viac=prechodneVacsie;
	}
	return viac;
}


void notNumber::getMsg() const
{
	std::cout <<msg <<std::endl;
}


void notPositive::getMsg() const
{
	std::cout <<msg <<std::endl;
}

