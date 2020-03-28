#ifndef MATICE_INVERZNA_H
#define MATICE_INVERZNA_H

void inverzna();
void alokuj (Zlomok *** matica, int kolko);
void nacitajPovodnu(Zlomok **maticaMeni, Zlomok ** maticaNemeni, int hodnost);
void spravJednotkovu(Zlomok **matica, int hodnost);	//inverznu maticu najskor nastavi na jednotkovu
int vypocitajInverznu(Zlomok ** maticaP, Zlomok ** maticaI, int hodnost);
int skontroluj (Zlomok **matica, int kolko);	//skontroluje, ci inverzna existuje
void vynasob (Zlomok **maticaP, Zlomok ** maticaI, int kolko);
void spravVynulovanu (Zlomok ** matica, int kolko);
void uvolni (Zlomok ** matica, int hodnost);
void vypis(Zlomok**matica, int kolko);

#endif //MATICE_INVERZNA_H
