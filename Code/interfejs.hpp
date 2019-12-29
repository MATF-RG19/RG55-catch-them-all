#ifndef INTERFEJS_H_
#define INTERFEJS_H_

extern bool flagAkcija;
extern bool flagStart;

extern float lonacTekuci;
extern float gdeDolazimo;
extern float ugaoMain;
extern float ugaoDrskeJedan;
extern float ugaoDrskeDva;
extern float vremeZaPadanje;
extern int brojZauzetihMesta;

extern int propusetno;
extern int imamoParadajz;
extern int imamoPecurku;
extern int imamoSargarepu;
extern int ispaljenObjekat;
extern float dodatakTezini;

extern bool pogodjenBombom;
extern bool izgubioIgru;
extern bool pobedioIgru;
extern bool eksplozijaSiri;
extern bool eksplozijaSkuplja;
extern bool promasioPovrce;
extern int izvrniLonac;

// funkcija za iscrtavanje slova na start meniju
void interfejsStart();

// funkcija koja nam iscrtava pozadinu start menija
void prozorStart();

// funkcija koja iscrtava nas skor i ostatak zivota
void interfejsIgra();

// funkcija koja iscrtava nas end meni
void interfejsEnd();

// dunkcija koja iscrtaca nas end meni pozdinu
void prozorEnd();

#endif