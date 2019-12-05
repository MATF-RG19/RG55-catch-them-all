#include <GL/glut.h>
#include <iostream>
#include <time.h>

#include "objekti.hpp"

#define MOTION_INTERVAL 20

// timer za transliranje lonca
#define TIMER_TRANSLIRANJA_LONCA 0
// timer za pokretanje programa
#define TIMER_START_PROGRAM 1

// pozicije lonca oko koje rotiramo toruse
float dx;
float dy;
float dz;

using namespace std;

void onTimer(int val) {
    if(val != TIMER_TRANSLIRANJA_LONCA) {
        return;
    }
    if(gdeDolazimo < lonacTekuci) {
        // idemo u levo
        if(lonacTekuci - 0.8 < gdeDolazimo) {
            lonacTekuci = gdeDolazimo;
            flagAkcija = false;
            return;
        }
        else {
            lonacTekuci -= 0.8;
            glutPostRedisplay();
            if(flagAkcija) {
                glutTimerFunc(MOTION_INTERVAL,onTimer,TIMER_TRANSLIRANJA_LONCA);
            }
        }
    }
    else {
        // idemo u desno 
        if(lonacTekuci + 0.8 > gdeDolazimo) {
            lonacTekuci = gdeDolazimo;
            flagAkcija = false;
            return;
        }
        else {
            lonacTekuci += 0.8;
            glutPostRedisplay();
            if(flagAkcija) {
                glutTimerFunc(MOTION_INTERVAL,onTimer,TIMER_TRANSLIRANJA_LONCA);
            }
        }
    }
}

void onTimerMain(int val) {
    if(val != TIMER_START_PROGRAM) {
        return;
    }
    if(ugaoLonca > 360.0) {
        ugaoLonca = 0;
    }
    ugaoLonca += 1.0;
    glutPostRedisplay();
    if(flagStart) {
        glutTimerFunc(MOTION_INTERVAL,onTimerMain,TIMER_START_PROGRAM);
    }
}

void crtajLonac(float lonacTekuci) {
    dx = lonacTekuci;
    dy = 1.75f;
    dz = 0;
    prvaDrska(lonacTekuci);
    drugaDrska(lonacTekuci);
    glColor3f(0.5,0.5,0.5);
    double clipPovrs[] = {0, -1, 0, 2.5};
    glPushMatrix();
        glClipPlane(GL_CLIP_PLANE0,clipPovrs);
        glTranslatef(lonacTekuci,1.75f,0);
        glRotatef(ugaoLonca,0,0,1);
        glutWireSphere(1.5,40,40);
        glEnable(GL_CLIP_PLANE0);
        glutPostRedisplay();
    glPopMatrix();
}

void prvaDrska(float lonacTekuci) {
    glColor3f(0.6,0.6,0.7);
    glPushMatrix();
        glTranslatef(lonacTekuci, 0, 0);
        glRotatef(ugaoLonca,0,1,0);
        glTranslatef(1.5f,1.75f,0);
        glRotatef(90,1,0,0);
        glutSolidTorus(0.05f,0.5f,40,40);
        glutPostRedisplay();
    glPopMatrix();
}

void drugaDrska(float lonacTekuci) {
    glColor3f(0.6,0.6,0.7);
    glPushMatrix();
        glTranslatef(lonacTekuci, 0, 0);
        glRotatef(ugaoLonca,0,1,0);
        glTranslatef(-1.5f,1.75f,0);
        glRotatef(90,1,0,0);
        glutSolidTorus(0.05f,0.5f,40,40);
        glutPostRedisplay();
    glPopMatrix();
}
