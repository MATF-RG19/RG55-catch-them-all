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


void interfejsStart();

void prozorStart();

void interfejsIgra();

void prozorIgra();

void interfejsEnd();

void prozorEnd();

#endif