#ifndef MATICE_FUNKCIE_H
#define MATICE_FUNKCIE_H

int otestujKladneCislo();
int zistiCo();	//urci, co sa ma pocitat
void obe();	//pocita determinant aj inverznu maticu

class wrongNumber
{
private:
	const char * msg;
public:
	explicit wrongNumber(const char *sprava):msg{sprava}{};
	void getMsg () const;
};

#endif //MATICE_FUNKCIE_H
