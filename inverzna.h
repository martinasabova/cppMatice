#ifndef MATICE_INVERZNA_H
#define MATICE_INVERZNA_H

void inverzna();
void inverzna(Zlomok *matica, int rozmer); //vola sa, ak sa pocita aj determinant
void alokuj (Zlomok *** matica, int kolko);
void nacitajPovodnu(Zlomok **maticaMeni, Zlomok ** maticaNemeni, int hodnost);
void nacitajPovodnu(Zlomok **maticaMeni, int hodnost, Zlomok *maticaRiadok); //ked sa pocita aj determinant
void spravJednotkovu(Zlomok **matica, int hodnost);	//inverznu maticu najskor nastavi na jednotkovu
int vypocitajInverznu(Zlomok ** maticaP, Zlomok ** maticaI, int hodnost);
int skontroluj (Zlomok **matica, int kolko);	//skontroluje, ci inverzna existuje
void vynasob (Zlomok **maticaP, Zlomok ** maticaI, int kolko);
void spravVynulovanu (Zlomok ** matica, int kolko);
void uvolni (Zlomok ** matica, int hodnost);
void vypis(Zlomok**matica, int kolko);

#endif //MATICE_INVERZNA_H
