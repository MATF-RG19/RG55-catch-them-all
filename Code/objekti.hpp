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
extern int brojZauzetihMesta;

extern float polozajPadajucihTela[BROJ_TANJIRA];
extern bool zauzetPozicija[BROJ_TANJIRA];
extern float pozicijaUVazduhu[BROJ_TANJIRA];

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

extern bool koPada[BROJ_TELA];

// tipovi -> 0 je bomba, 1 je paradajz, 2 je sargarepa, 3 je pecurka
struct niz_element{
    float x_pos;
    float y_pos;
    int tip;
    bool zauzet;
};

// onTimer funkcija za transliranje lonca
void onTimer(int val);

// onTimerMain funkcija za stalno rotiranje lonca
void onTimerMain(int val);

// funkcija za crtanje tela lonca
void crtajLonac(float lonacTekuci);

// funkcija za crtanje leve drske lonca
void prvaDrska();

// funkcija za crtanje desne drske
void drugaDrska();

// crtanje tela sargarepe
void crtajSargarepu(float x,float y,float z);

// crtanje peteljke sargarepe
void crtajPeteljkaSargarepe();

// crtanje paradajza
void crtajParadajz(float x,float y,float z);

// crtanje peteljke paradajza
void crtajPeteljkaParadajz();

// crtamoi Pecurku
void crtajPecurku(float x,float y,float z);

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

void crtajEksploziju();

void crtajZid();

void crtaj(niz_element &ne, float dodatakTezini,bool restartBrisi);
#endif
