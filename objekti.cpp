#include <GL/glut.h>
#include <iostream>
#include <time.h>
#include <GL/freeglut.h>

#include "objekti.hpp"

#define MOTION_INTERVAL 20
#define BROJ_TANJIRA 5
#define BROJ_TELA 4

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
    if(ugaoMain > 360.0) {
        ugaoMain = 0;
    }
    // sada krecemo da bacamo nase telo
    if(vremeZaPadanje == 100 + 0.1) {
        koPada[0] = true;
        vremeZaPadanje = 0;
    }
    ugaoMain += 1.0;
    
    glutPostRedisplay();
    if(flagStart) {
        glutTimerFunc(MOTION_INTERVAL,onTimerMain,TIMER_START_PROGRAM);
    }
}


void crtajLonac(float lonacTekuci) {
    prvaDrska(lonacTekuci);
    drugaDrska(lonacTekuci);
    crtajSupu();

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0.5, 0.5, 0.5, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.6, 0.6, 0.6, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    double clipPovrs[] = {0, -1, 0, 2.5};
    glPushMatrix();
        glClipPlane(GL_CLIP_PLANE0,clipPovrs);
        glEnable(GL_CLIP_PLANE0);
        glTranslatef(lonacTekuci,1.75f,0);
        glRotatef(ugaoMain,0,0,1);
        glutSolidSphere(1.5,40,40);
        glDisable(GL_CLIP_PLANE0);
    glPopMatrix();
    glDisable(GL_LIGHTING);
    
}

void prvaDrska(float lonacTekuci) {

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0.5, 0.4, 0.5, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.6, 0.6, 0.6, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
        glTranslatef(lonacTekuci, 0, 0);
        glRotatef(ugaoMain,0,1,0);
        glTranslatef(1.5f,1.75f,0);
        glRotatef(90,1,0,0);
        glutSolidTorus(0.05f,0.5f,40,40);
        glDisable(GL_CLIP_PLANE0);
    glPopMatrix();

    glDisable(GL_LIGHTING);
}

void drugaDrska(float lonacTekuci) {

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0.5, 0.4, 0.5, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.6, 0.6, 0.6, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
        glTranslatef(lonacTekuci, 0, 0);
        glRotatef(ugaoMain,0,1,0);
        glTranslatef(-1.5f,1.75f,0);
        glRotatef(90,1,0,0);
        glutSolidTorus(0.05f,0.5f,40,40);
        
    glPopMatrix();

    glDisable(GL_LIGHTING);
}

void crtajBombu(float x,float y) {

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0.1, 0.1, 0, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.6, 0.6, 0.6, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
        glTranslatef(x,y,0);
        glRotatef(ugaoMain,1,1,0); 
        crtajFitilj();
        crtajDrskuBombe();
        glEnable(GL_LIGHTING);       
        glutSolidSphere(1,40,40);
        glutPostRedisplay();
    glPopMatrix();

    glDisable(GL_LIGHTING);
}

void crtajDrskuBombe() {

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0, 0, 0, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.0, 0.0, 0.0, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
        glTranslatef(0, 0.8, -0.3);        
        glRotatef(235,1,0,0);
        glutSolidCylinder(0.2,0.4,40,40);
        glutPostRedisplay();
    glPopMatrix();

    glDisable(GL_LIGHTING);
}

void crtajFitilj() {

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0.5, 0, 0, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.6, 0.6, 0.6, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
        glTranslatef(0, 0.8, -0.3);        
        glRotatef(235,1,0,0);
        glutSolidCylinder(0.05,0.6,40,40);
        glutPostRedisplay();
    glPopMatrix();

    glDisable(GL_LIGHTING);
}


void crtajSupu() {

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 1, 0.6, 0.1, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.5, 0.5, 0.5, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
        glTranslatef(lonacTekuci,1.88,0);
        glRotatef(90,1,0,0);
        glutSolidCylinder(1.4,0.01,40,40);
        glutPostRedisplay();
    glPopMatrix();

    glDisable(GL_LIGHTING);
}



void crtajTanjire() {

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 1, 0.9, 0.6, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 1, 0.8, 0.6, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    for(int i=-8;i<=8;i=i+4) {
        glPushMatrix();
            float rastojanje =i;
            glTranslatef(rastojanje,0.2,0);
            glRotatef(90,1,0,0);
            glutSolidCylinder(1.5,0.2,40,40);            
        glPopMatrix();
    }

    glDisable(GL_LIGHTING);
}

void crtajSargarepu(float x,float y) {

    glEnable(GL_LIGHTING);

    glPushMatrix();
        glTranslatef(x,y,0);
        glRotatef(ugaoMain,0,1,1);
        crtajPeteljkaSargarepe();
        glEnable(GL_LIGHTING);

        /* Koeficijenti ambijentalne refleksije materijala. */
        GLfloat ambient_coeffs[] = { 1, 0.6, 0.1, 1 };

        /* Koeficijenti difuzne refleksije materijala. */
        GLfloat diffuse_coeffs[] = { 0.6, 0.6, 0.2, 1 };

        /* Koeficijenti spekularne refleksije materijala. */
        GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

        /* Koeficijent glatkosti materijala. */
        GLfloat shininess = 100;

        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess);


        glutSolidCone(0.3,2,40,40);
        glutPostRedisplay();
    glPopMatrix();

    glDisable(GL_LIGHTING);
}

void crtajPeteljkaSargarepe() {

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0.1, 1, 0.1, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.6, 0.6, 0.2, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    glPushMatrix();
        glTranslatef(0,0,-0.5);
        glutSolidCylinder(0.1,1,40,40);
        glutPostRedisplay();
    glPopMatrix();

    glDisable(GL_LIGHTING);
}


void crtajSto() {

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0.7, 0.2, 0.2, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.2, 0.2, 0.2, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 0, 0, 0, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
        glTranslatef(0,-2,0);
        glScalef(1,0.1,0.9);
        glutSolidCube(40);
        glutPostRedisplay();
    glPopMatrix();

    glDisable(GL_LIGHTING);
}

void crtajParadajz(float x, float y) {

    glPushMatrix();
        glTranslatef(x,y,0);
        glRotatef(ugaoMain,1,0,0);


        crtajPeteljkaParadajz();

        glEnable(GL_LIGHTING);

        /* Koeficijenti ambijentalne refleksije materijala. */
        GLfloat ambient_coeffs[] = { 1, 0, 0, 1 };

        /* Koeficijenti difuzne refleksije materijala. */
        GLfloat diffuse_coeffs[] = { 1, 0.3, 0.3, 1 };

        /* Koeficijenti spekularne refleksije materijala. */
        GLfloat specular_coeffs[] = { 0, 0, 0, 1 };

        /* Koeficijent glatkosti materijala. */
        GLfloat shininess = 10;

        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess);

        glScalef(1,0.7,1);
        glutSolidSphere(1,40,40);
        glutPostRedisplay();
    glPopMatrix();
    glDisable(GL_LIGHTING);
}

void crtajPeteljkaParadajz() {

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0.1, 1, 0.1, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.6, 0.6, 0.2, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
        glTranslatef(0.8,0,0);
        glRotatef(90,0,1,0);
        glutSolidCylinder(0.1,0.5,40,40);
        glutPostRedisplay();
    glPopMatrix();
    glDisable(GL_LIGHTING);
}

void crtajPecurku(float x,float y) {

    glPushMatrix();
        glTranslatef(x,y,0);
        glRotatef(ugaoMain,0,1,1);
        crtajStabloPecurke();
        
        glEnable(GL_LIGHTING);

        /* Koeficijenti ambijentalne refleksije materijala. */
        GLfloat ambient_coeffs[] = { 1, 0.9, 0.3, 1 };

        /* Koeficijenti difuzne refleksije materijala. */
        GLfloat diffuse_coeffs[] = { 1, 0.8, 0.6, 1 };

        /* Koeficijenti spekularne refleksije materijala. */
        GLfloat specular_coeffs[] = { 1, 1, 1, 0 };

        /* Koeficijent glatkosti materijala. */
        GLfloat shininess = 100;

        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess);

        glScalef(0.8,0.7,1);
        glutSolidSphere(0.8,40,40);
        glutPostRedisplay();
    glPopMatrix();

    glDisable(GL_LIGHTING);
}

void crtajStabloPecurke() {
    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 1, 0.9, 0.3, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 1, 0.8, 0.6, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    glPushMatrix();
        glRotatef(90,0,1,0);
        glutSolidCylinder(0.4,0.8,40,40);
    glPopMatrix();
    glDisable(GL_LIGHTING);
}

void crtaj(niz_element &ne, float dodatakTezini){
    ne.y_pos -= 0.05 + dodatakTezini;
    // promena iscrtavamo paradajz ceo
    if(ne.tip == 0) {
        crtajBombu(ne.x_pos,ne.y_pos);
    }
    if(ne.tip==1){
		crtajParadajz(ne.x_pos,ne.y_pos);        
    }
    if(ne.tip==2){
        crtajSargarepu(ne.x_pos,ne.y_pos);
    }
    if(ne.tip==3){
        crtajPecurku(ne.x_pos,ne.y_pos);
    }
    if(ne.y_pos<=1.0){
        if(ne.tip != 0) {
            propusetno += 1;
            if(propusetno == 3) {
                cout << "IZGUBIO SI! PALO TI JE VISE OD 3 POVRCA" << endl;
                exit(0);
            }
        }
        ne.y_pos=30;
        ne.tip=-1;
        ne.zauzet = false;
        brojZauzetihMesta -= 1;
    }
    if((int)ne.x_pos == lonacTekuci && (ne.y_pos > 0  && ne.y_pos < 2)) {
        if(ne.tip == 0) {
            cout << "IZGUBIO SI! PALA JE BOMBA NA TEBE" << endl;
            exit(0);
        }
        else {
            if(ne.tip == 1) {
                if(imamoParadajz != 20) 
                    imamoParadajz += 1;
            }
            if(ne.tip == 2) {
                if(imamoSargarepu != 20)
                    imamoSargarepu += 1;
            }
            if(ne.tip == 3) {
                if(imamoPecurku != 20)
                    imamoPecurku += 1;
            }
        }
        if(imamoParadajz == 20 && imamoPecurku == 20 && imamoSargarepu == 20) {
            cout << "POBEDIO SI! SAKUPIO SI 20 KOMADA OD SVAKOG POVRCA" << endl;
            exit(1);
        }
        ne.y_pos=30;
        ne.tip=-1;
        ne.zauzet = false;
        brojZauzetihMesta -= 1;
    }
    glutPostRedisplay();
}
