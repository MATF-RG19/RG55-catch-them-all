#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<vector>
#include<time.h>

#include"objekti.hpp"
#include"interfejs.hpp"

#define MOTION_INTERVAL 20
#define BROJ_TELA 4
#define BROJ_TANJIRA 5

int timerInterval = 0;

using namespace std;

// ugao kamere
float ugao = 90;

//flag za akciju
bool flagAkcija = false;

// flag za startovanje
bool flagStart = false;

// na koju poziciju pretenduje
float gdeDolazimo;

// pozicije kotlica
float lonacTekuci = 0;

float ugaoMain = 0.0;

// indikator kada ce telo da padne
float vremeZaPadanje = 0;

int brojZauzetihMesta = 0;

int propusetno = 0;
int imamoParadajz = 0;
int imamoPecurku = 0;
int imamoSargarepu = 0;
int ispaljenObjekat = 0;
float dodatakTezini = 0.0;

// flagovi za igru, da li smo pobedili, pogodjeni smo bombom ili smo promasili povrce
bool pogodjenBombom = false;
bool izgubioIgru = false;
bool promasioPovrce = false;
bool pobedioIgru = false;
bool eksplozijaSiri = false;
bool eksplozijaSkuplja = false;
int izvrniLonac = 1;
int timerBrisi = 0;
bool restartBrisi = false;

// 0 - bomba, 1 - paradajz, 2 - sargarepa, 3 - pecurka
bool koPada[BROJ_TELA];

vector<niz_element> niz;

// funkcije akcije tastature
// ovde prvo na klik 'j' i 'l' pomeramo kameru levo desno
// na 'a' i 'd' pomeramo loncic levo i desno
// na ESC dugme se prekida kod, a na 's' je start
void keyboardFunction(unsigned char key, int x, int y) {
    if(key == 27) {
        cout << "Izasli ste iz igrice!" << endl;
        exit(0);
    }
    if(key == 's') {
        if(flagStart != true) {
            flagStart = true;
            glutTimerFunc(MOTION_INTERVAL,onTimerMain,1);
        }
    }
    if(key == 'r' && flagStart && !eksplozijaSkuplja && !eksplozijaSiri) {
        imamoParadajz = 0;
        imamoPecurku = 0;
        imamoSargarepu = 0;
        propusetno = 0;
        timerInterval = 0;
        dodatakTezini = 0;
        izgubioIgru = false;
        pogodjenBombom = false;
        eksplozijaSiri = false;
        eksplozijaSkuplja = false;
        izvrniLonac = 1;
        promasioPovrce = false;
        lonacTekuci = 0;
        brojZauzetihMesta = 0;
        restartBrisi = true;
        for(int i=0;i<niz.size();i++) {
            niz.pop_back();
        }
        for(int i=-8;i<=8;i=i+4) {
            niz.push_back({(float)i,30,-1,false});
        }
    }
}

void SpecialInput(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_LEFT:
            if(lonacTekuci > -8.0 and flagStart and !izgubioIgru) {
                if(!flagAkcija) {
                    gdeDolazimo = lonacTekuci - 4.0;
                    flagAkcija = true;
                    glutTimerFunc(MOTION_INTERVAL,onTimer,0);
                }
            }
        break;
        case GLUT_KEY_RIGHT:
            if(lonacTekuci < 8.0 and flagStart and !izgubioIgru) {
                if(!flagAkcija) {
                    gdeDolazimo = lonacTekuci + 4.0;
                    flagAkcija = true;
                    glutTimerFunc(MOTION_INTERVAL,onTimer,0);
                }
            }
        break;
    }
    glutPostRedisplay();
}

// funkcija koja renderuje nasu sliku
void renderFunction() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

        // pogled nase kamere
        gluLookAt(0,10,15,
                    0, 10, 0,
                    0, 1, 0);


        /* Pozicija svetla (u pitanju je direkcionalno svetlo). */
        GLfloat light_position[] = { 0,7,2,1 };

        /* Ambijentalna boja svetla. */
        GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1 };

        /* Difuzna boja svetla. */
        GLfloat light_diffuse[] = { 0.7, 0.7, 0.7, 1 };

        /* Spekularna boja svetla. */
        GLfloat light_specular[] = { 0.9, 0.9, 0.9, 1 };

        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

        
        if(!flagStart) {
            prozorStart();
            interfejsStart();
        }
        else {
            if((izgubioIgru && !eksplozijaSiri && !eksplozijaSkuplja) || pobedioIgru) {
                interfejsEnd();
                prozorEnd();
            }
            if(!izgubioIgru) {
                crtajPecurku(-8.8,20,4);
                crtajParadajz(-8.9,17,4);
                crtajSargarepu(-8.8,13,4);
                interfejsIgra();
                prozorIgra();
            }
            crtajTanjire();
            if(!promasioPovrce) {
                crtajLonac(lonacTekuci);
            }

            // novi deo koda koji odredjuje interval kada iscrtavamo
            // samo iscrtavamo paradajz

            if(restartBrisi == true) {
                if(timerBrisi == 1) {
                    restartBrisi = false;
                    timerBrisi = 0;
                }
                else {
                    timerBrisi += 1;
                }
            }
            if(flagStart == true && !izgubioIgru && !restartBrisi) {
                timerInterval++;
            }
            if(timerInterval%100 == 0 && flagStart == true && !izgubioIgru && !restartBrisi) {
                srand(time(NULL));
                int biramoMesto = rand()%5;
                int biramoTip = rand()%4;
                if(niz[biramoMesto].zauzet == false && brojZauzetihMesta < 5){
                    niz[biramoMesto].tip = biramoTip;
                    niz[biramoMesto].x_pos = -8 + biramoMesto*4 ;
                    niz[biramoMesto].zauzet = true;
                    niz[biramoMesto].y_pos = 30;
                    brojZauzetihMesta += 1;
                    ispaljenObjekat += 1;
                    if(ispaljenObjekat % 5 == 0)  {
                        ispaljenObjekat += 1;
                        dodatakTezini += 0.03;
                    }
                }
            }
            for(int i=0;i<niz.size();i++) {
                if(niz[i].tip!=-1 && flagStart == true && !izgubioIgru) {
                    crtaj(niz[i],dodatakTezini,restartBrisi);
                }
            }
            if(eksplozijaSiri == true || eksplozijaSkuplja == true) {
                crtajEksploziju();
            }
            
            crtajSto();
        }
    glPopMatrix();

    glutSwapBuffers();
}

void inicijalizujGlut() {
    glClearColor(0.8,0.8,0.5,0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(90.0, 1920.0/2080.0, 0.1, 250.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc,argv);

    glutInitWindowSize(1920,1080);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("CATCH THEM ALL!!!");
    
    brojZauzetihMesta = 0;
    for(int i=-8;i<=8;i=i+4) {
        niz.push_back({(float)i,30,-1,false});
    }
    inicijalizujGlut();
    glutDisplayFunc(renderFunction);
    glutKeyboardFunc(keyboardFunction);
    glutSpecialFunc(SpecialInput);
    glutMainLoop();
    return 0;

}
