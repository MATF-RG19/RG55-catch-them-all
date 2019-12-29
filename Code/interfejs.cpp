#include <GL/glut.h>
#include <iostream>
#include <time.h>
#include <GL/freeglut.h>
#include <string>

#include "interfejs.hpp"
#include "teksture.hpp"
#include "objekti.hpp"

using namespace std;

// funkcija koja nam srca srca koliko nam je zivota ostalo
static void crtajSrce(){
    glEnable(GL_LIGHTING_BIT);
    glColor3f(0.8,0,0);
    glScalef(0.18, 0.18, 0.18);
    glPushMatrix();
        
        glutSolidSphere(0.8, 30, 30);

        glTranslatef(0.95, 0, 0);
        glutSolidSphere(0.8, 30, 30);

        glScalef(1.4, 1.4, 0.2);
        glTranslatef(-0.3, 0.35, 0);
        glRotatef(50, 0, 0, 1);
        glRotatef(-5, 0, 0, 1);
        glutSolidCube(1.1);
	glPopMatrix();
    glDisable(GL_LIGHTING_BIT);
}


void interfejsStart() {

    glEnable(GL_LIGHTING_BIT);

    string txt = "CATCH THEM ALL - THE SOUP GAME";
    string txt1 = "Budite i vi vas personalni lonac i sakupljajte povrce(pecurka included) koje pada.";
    string txt2 = "Morate da sakupite odvojeno 20 sargarepa, pecuraka i paradajza.";
    string txt3 = "Ako vas pogodi bomba ili vam je palo 3 namirnica na sto, izgubili ste!!!";
    string txt4 = "UPUTSTVA ZA IGRU:";
    string txt5 = " ~ na strelice pokrecete kotlic levo desno";
    string txt6 = " ~ 'S' - pokrecete igru";
    string txt7 = " ~ 'R' - restartujete igru";
    string txt8 = " ~ 'ESC' - izlazite iz igre";
    glColor3f(1,0,1);
    glRasterPos3f(-3,18,4.1);
        for(auto it=txt.begin();it!=txt.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
    glDisable(GL_LIGHTING_BIT);
    
    glEnable(GL_LIGHTING_BIT);
    glColor3f(0,1,1);
    glRasterPos3f(-4,14,4.1);
        for(auto it=txt1.begin();it!=txt1.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-4,12,4.1);
        for(auto it=txt2.begin();it!=txt2.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-4,10,4.1);
        for(auto it=txt3.begin();it!=txt3.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-4,8,4.1);
        for(auto it=txt4.begin();it!=txt4.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-3.5,7,4.1);
        for(auto it=txt5.begin();it!=txt5.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-3.5,6,4.1);
        for(auto it=txt6.begin();it!=txt6.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-3.5,5,4.1);
        for(auto it=txt7.begin();it!=txt7.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-3.5,4,4.1);
        for(auto it=txt8.begin();it!=txt8.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
    glDisable(GL_LIGHTING_BIT);
    
    glutPostRedisplay();
}

void prozorStart() {

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0.5, 0.5, 1, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.5, 0.5, 1, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 0, 0, 0, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 10;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    glPushMatrix();
        glTranslatef(0,5,4);
        glScalef(100,100,0.01);
        glutSolidCube(10);
    glPopMatrix();
    glutPostRedisplay();
    Remzi();
    glDisable(GL_LIGHTING);
}

void interfejsIgra() {
    glEnable(GL_LIGHTING_BIT);
    string txt = to_string(20 - imamoPecurku);
    string txt1 = to_string(20 - imamoSargarepu);
    string txt2 = to_string(20 - imamoParadajz);
    string txt3 = "zivoti";
    
    glColor3f(0.5,0.2,0);
    glRasterPos3f(-9,17.6,4.1);
        for(auto it=txt.begin();it!=txt.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
    glDisable(GL_LIGHTING_BIT);

    glEnable(GL_LIGHTING_BIT);
    glColor3f(0.3,0.1,0);
    glRasterPos3f(-9,10.7,4.1);
        for(auto it=txt1.begin();it!=txt1.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
    glDisable(GL_LIGHTING_BIT);

    glEnable(GL_LIGHTING_BIT);
    glColor3f(0.5,0.1,0.1);
    glRasterPos3f(-9,14,4.1);
        for(auto it=txt2.begin();it!=txt2.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
    glDisable(GL_LIGHTING_BIT);
    
    glEnable(GL_LIGHTING_BIT);
    glColor3f(0.6,0.1,0.1);
    glRasterPos3f(-9,9.2,4.1);
        for(auto it=txt3.begin();it!=txt3.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
    glDisable(GL_LIGHTING_BIT);

    for(int i=0;i<3-propusetno;i++) {
        glPushMatrix();
            glTranslatef(-8.7 + i*0.7, 8.8, 5);
            glRotatef(-180, 0, 1, 0);
            glRotatef(180, 1, 0, 0);
            crtajSrce();
        glPopMatrix();
    }   
}

void interfejsEnd() {
    glDisable(GL_LIGHTING_BIT);
    glDisable(GL_LIGHTING);
    glEnable(GL_LIGHTING_BIT);
    string text = "POBEDILI STE!!! JEEEEEEJ!";
    string text2 = "IZGUBILI STE";
    string text3 = "POGODILA VAS JE BOMBA";
    string text4 = "ISPALO VAM JE VISE OD 3 NAMIRNICA";
    string text5 = "Pritisnite 'R' da ponovo odigrate partiju";
    string text6 = "Pritisnite 'ESC' da izadjete iz igre";
    if(pobedioIgru) {
        glColor3f(0,1,1);
        glRasterPos3f(-2,16,3.4);
        for(auto it=text.begin();it!=text.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
        glDisable(GL_LIGHTING_BIT);
    }
    else if(izgubioIgru) {
        glColor3f(1,0,0);
        glRasterPos3f(-1,16,5);
        for(auto it=text2.begin();it!=text2.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
        if(pogodjenBombom) {
            glRasterPos3f(-2,15.5,3.4);
            for(auto it=text3.begin();it!=text3.end();it++) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
            }
        }
        else if(promasioPovrce) {
            glRasterPos3f(-3,15.5,3.4);
            for(auto it=text4.begin();it!=text4.end();it++) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
            }
        }
        glDisable(GL_LIGHTING_BIT);
    }
    glEnable(GL_LIGHTING_BIT);
    glColor3f(1,1,0.5);
    glRasterPos3f(-3,7,3.4);
    for(auto it=text5.begin();it!=text5.end();it++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
    }

    glRasterPos3f(-3,5,3.4);
    for(auto it=text6.begin();it!=text6.end();it++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
    }
    if(pobedioIgru) {
        RemziSrecan();
    }
    else {
        RemziLjut1();
        RemziLjut2(); 
    }
    glDisable(GL_LIGHTING_BIT);
}

void prozorEnd() {
    glDisable(GL_LIGHTING_BIT);
    glDisable(GL_LIGHTING);
    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0.2, 1, 0 , 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.2, 1, 0, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 0, 0, 0, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 1;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    glPushMatrix();
        glTranslatef(0,10,3);
        glScalef(1,2,0.001);
        glutSolidCube(10);
    glPopMatrix();
    glutPostRedisplay();
    glDisable(GL_LIGHTING);
}

