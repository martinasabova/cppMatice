#ifndef MATICE_ZLOMOK_H
#define MATICE_ZLOMOK_H


class Zlomok
{
private:
	int citatel;
	int menovatel;
public:
	Zlomok():citatel{0}, menovatel{1}{};
	explicit Zlomok(int a):citatel{a}, menovatel{1} {};
	Zlomok(int a, int b):citatel{a}, menovatel{b} {};

	int getCitatel() const {return citatel;};
	int getMenovatel() const {return menovatel;};

	Zlomok operator + (const Zlomok &other) const;
	Zlomok operator - (const Zlomok &other) const;
	Zlomok operator * (const Zlomok &other) const;
	Zlomok operator / (const Zlomok &other) const;
	Zlomok operator * (int cislo) const;
	friend Zlomok operator * (int cislo, const Zlomok &other);
	Zlomok & operator += (const Zlomok &other);
	Zlomok & operator -= (const Zlomok &other);

	friend std::ostream & operator<< (std::ostream &out, const Zlomok &moj);
	friend std::istream & operator >>(std::istream &in, Zlomok &moj);

	void uprav ();
	static int euklidovAlgoritmus (int viac, int menej);
};

class notNumber
{
private:
	const char * msg;
public:
	explicit notNumber(const char *sprava):msg{sprava}{};
	void getMsg () const;
};

class notPositive
{
private:
	const char * msg;
public:
	explicit notPositive(const char *sprava):msg{sprava}{};
	void getMsg () const;
};

/*
void alokuj (Zlomok *** matica, int kolko);
void alokuj (Zlomok **korienky, int kolko);
void nacitaj(Zlomok **matica, int kolko);
void vypis(Zlomok **matica, int kolko);
void vypis (const Zlomok *korienky, int kolko);
void uprav(Zlomok **matica, int kolko);
void vypocitajKorene(Zlomok **matica, int kolko, Zlomok *korienky);
void uvolni (Zlomok ** matica, int kolko, Zlomok *korienky);
*/








#endif //MATICE_ZLOMOK_H
