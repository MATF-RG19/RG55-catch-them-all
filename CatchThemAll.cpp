#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include"objekti.hpp"

#define MOTION_INTERVAL 20
#define BROJ_TELA 4
#define BROJ_TANJIRA 5

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

// 0 - bomba, 1 - paradajz, 2 - sargarepa, 3 - pecurka
bool koPada[BROJ_TELA];
// koja je pozicija zauzeta
bool zauzetPozicija[BROJ_TANJIRA];

float padanjeTela[BROJ_TELA];

float pozicijaBombaVazduh;
float pozicijaParadajzVazduh;
float pozicijaSargarepaVazduh;
float pozicijaPecurkaVazduh;

// funkcije akcije tastature
// ovde prvo na klik 'j' i 'l' pomeramo kameru levo desno
// na 'a' i 'd' pomeramo loncic levo i desno
// na ESC dugme se prekida kod, a na 's' je start
void keyboardFunction(unsigned char key, int x, int y) {
    if(key == 'j' and flagStart) {
        ugao += 0.01;
    }
    if(key == 'l' and flagStart) {
        ugao -= 0.01;
    }
    if(key == 'a' and lonacTekuci > -8.0 and flagStart) {
        if(!flagAkcija) {
            gdeDolazimo = lonacTekuci - 4.0;
            flagAkcija = true;
            glutTimerFunc(MOTION_INTERVAL,onTimer,0);
        }
    }
    if(key == 'd' and lonacTekuci < 8.0 and flagStart) {
        if(!flagAkcija) {
            gdeDolazimo = lonacTekuci + 4.0;
            flagAkcija = true;
            glutTimerFunc(MOTION_INTERVAL,onTimer,0);
        }
    }
    if(key == 27) {
        cout << "Izasli ste iz igrice!" << endl;
        exit(0);
    }
    if(key == 's') {
        flagStart = true;
        glutTimerFunc(MOTION_INTERVAL,onTimerMain,1);
    }
}


// funkcija koja renderuje nasu sliku
void renderFunction() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glPushMatrix();

        // pogled nase kamere
        gluLookAt(15*cos(ugao),10,15*sin(ugao),
                    0, 10, 0,
                    0, 1, 0);

        /* Pozicija svetla (u pitanju je direkcionalno svetlo). */
        GLfloat light_position[] = { 0,5,3,1 };

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

        crtajPecurku();
        crtajParadajz();
        crtajTanjire();
        crtajSargarepu();
        crtajBombu();
        crtajLonac(lonacTekuci);
        crtajSto();

    glPopMatrix();

    glutSwapBuffers();
}

void inicijalizujGlut() {
    glClearColor(0.75,0.75,0.75,0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(90.0, 1920.0/2080.0, 0.1, 250.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc,argv);
    
    // inicijalizacija nizova
    for(int i = 0; i < BROJ_TELA; i++ ) {
        koPada[i] = false;
    }

    glutInitWindowSize(1920,1080);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("CATCH THEM ALL!!!");
    inicijalizujGlut();
    glutDisplayFunc(renderFunction);
    glutKeyboardFunc(keyboardFunction);
    glutMainLoop();
    return 0;

}