#ifndef MATICE_ROVNICE_H
#define MATICE_ROVNICE_H

void rovnice();
void nacitaj(Zlomok **matica, int kolko);
void vypocitaj(Zlomok **matica, int kolko);
void vypocitajKorene(Zlomok ** matica, Zlomok * riesenia, int kolko);

namespace sustavaRovnic	//bilo sa to s funkciami z inverznej matice
{
	void alokuj(Zlomok ***matica, int kolko);
	int skontroluj(Zlomok **matica, int kolko);
	void uvolni(Zlomok **matica, int kolko);
}
#endif //MATICE_ROVNICE_H
