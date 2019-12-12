#ifndef OBJEKTI_H_
#define OBJEKTI_H_

#define BROJ_TANJIRA 5
#define BROJ_TELA 4

// flag za Akciju i Start
extern bool flagAkcija;
extern bool flagStart;

extern float lonacTekuci;
extern float gdeDolazimo;
extern float ugaoMain;
extern float ugaoDrskeJedan;
extern float ugaoDrskeDva;
extern float vremeZaPadanje;

extern float polozajPadajucihTela[BROJ_TANJIRA];
extern bool zauzetPozicija[BROJ_TANJIRA];
extern float pozicijaUVazduhu[BROJ_TANJIRA];
extern bool koPada[BROJ_TELA];

// onTimer funkcija za transliranje lonca
void onTimer(int val);

// onTimerMain funkcija za stalno rotiranje lonca
void onTimerMain(int val);

// funkcija za crtanje tela lonca
void crtajLonac(float lonacTekuci);

// funkcija za crtanje leve drske lonca
void prvaDrska(float lonacTekuci);

// funkcija za crtanje desne drske
void drugaDrska(float lonacTekuci);

// crtanje tela sargarepe
void crtajSargarepu();

// crtanje peteljke sargarepe
void crtajPeteljkaSargarepe();

// crtanje paradajza
void crtajParadajz();

// crtanje peteljke paradajza
void crtajPeteljkaParadajz();

// crtamoi Pecurku
void crtajPecurku();

// crtamo stablo pecurke
void crtajStabloPecurke();

// crtanje tela bombe
void crtajBombu();

// crtanje drske od bombe
void crtajDrskuBombe();

// crtanje fitilja od bombe
void crtajFitilj();

// crta 5 tanjira na stolu
void crtajTanjire();

// crtanje supe u loncu
void crtajSupu();

// crtamo sto(platforma igre)
void crtajSto();
#endif