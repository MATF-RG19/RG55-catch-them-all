#ifndef OBJEKTI_H_
#define OBJEKTI_H_

// flag za Akciju i Start
extern bool flagAkcija;
extern bool flagStart;

extern float lonacTekuci;
extern float gdeDolazimo;
extern float ugaoLonca;
extern float ugaoDrskeJedan;
extern float ugaoDrskeDva;

// onTimer funkcija za transliranje lonca
void onTimer(int val);

// onTimerMain funkcija za stalno rotiranje lonca
void onTimerMain(int val);

// funkcija za crtanje tela lonca
void crtajLonac(float lonacTekuci);

// funkcija za crtanje leve drske lonca
void prvaDrska(float lonacTekuci);

// funkcija za crtanje desne drske lonca
void drugaDrska(float lonacTekuci);

// funkcija koja crta jedan tanjir
void crtajTanjir(float pozicija);

void crtajSargarepu();

void crtajParadajz();

void crtajLuk();

void crtajBombu();

#endif