#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include"objekti.hpp"

#define MOTION_INTERVAL 20

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

float ugaoLonca = 0.0;

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

// pozicije na kojim ce se kretati nas lonac
// i gde ce objekti da padaju! Ima ih 5
void crtajPozicije() {
    glColor3f(0,0,1);
    for(int i = -8;i<=8;i+=4) {
        glPushMatrix();
            float rastojanje =i;
            glTranslatef(rastojanje,0,0);
            glutSolidCube(0.3f);
        glPopMatrix();
    }
}

// funkcija koja crta kordinatne ose
void crtajOse() {
    glBegin(GL_LINES);

        // koordinata z
        glColor3f(0.3,0.7,0.5);
        glVertex3f(0,0,-500);
        glVertex3f(0,0,500);

        // koordinata x
        glColor3f(0.4,0.3,0.5);
        glVertex3f(500,0,0);
        glVertex3f(-500,0,0);

        // koordinata y
        glColor3f(0.4,0.4,0.2);
        glVertex3f(0,500,0);
        glVertex3f(0,-500,0);

    glEnd();
}

// funkcija koja renderuje nasu sliku
void renderFunction() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

        // pogled nase kamere
        gluLookAt(15*cos(ugao),10,15*sin(ugao),
                    0, 10, 0,
                    0, 1, 0);
        
        // postavljanje nase platforme za igricu
        glColor3f(0.2,3,0.2);
        glBegin(GL_QUADS);
            glVertex3f(-500,0,-500);
            glVertex3f(500,0,-500);
            glVertex3f(500,0,500);
            glVertex3f(-500,0,500);
        glEnd();

        crtajOse();
        crtajPozicije();
        crtajLonac(lonacTekuci);

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
    glutInitWindowSize(1920,1080);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("CATCH THEM ALL!!!");
    inicijalizujGlut();
    glutDisplayFunc(renderFunction);
    glutKeyboardFunc(keyboardFunction);
    glutMainLoop();
    return 0;

}