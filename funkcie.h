#ifndef MATICE_FUNKCIE_H
#define MATICE_FUNKCIE_H

int otestujKladneCislo();
int zistiCo();
void obe();

class wrongNumber
{
private:
	const char * msg;
public:
	explicit wrongNumber(const char *sprava):msg{sprava}{};
	void getMsg () const;
};

#endif //MATICE_FUNKCIE_H
