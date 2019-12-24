#include <GL/glut.h>
#include <iostream>
#include <time.h>
#include <GL/freeglut.h>
#include <string>

#include "interfejs.hpp"

using namespace std;

void interfejsStart() {

    glEnable(GL_LIGHTING_BIT);

    string txt = "CATCH THEM ALL - THE SOUP GAME";
    string txt1 = "Budite i vi vas personalni lonac i sakupljajte povrce koje padaju.";
    string txt2 = "Morate da sakupite odvojeno 20 sargarepa, pecuraka i paradajza.";
    string txt3 = "Ako vas pogodi bomba ili vam je palo 3 namirnica na sto, izgubili ste!!!";
    string txt4 = "UPUTSTVA ZA IGRU:";
    string txt5 = " ~ na strelice pokrecete kotlic levo desno";
    string txt6 = " ~ 'S' - pokrecete igru";
    string txt7 = " ~ 'R' - restartujete igru";
    string txt8 = " ~ 'ESC' - izlazite iz igre";
    glColor3f(1,0,1);
    glRasterPos3f(-5,20,4);
        for(auto it=txt.begin();it!=txt.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
            
        }
    glDisable(GL_LIGHTING_BIT);
    
    glEnable(GL_LIGHTING_BIT);
    glColor3f(0,1,1);
    glRasterPos3f(-10,17,4);
        for(auto it=txt1.begin();it!=txt1.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-10,16,4);
        for(auto it=txt2.begin();it!=txt2.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-10,15,4);
        for(auto it=txt3.begin();it!=txt3.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-10,14,4);
        for(auto it=txt4.begin();it!=txt4.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-9.5,13,4);
        for(auto it=txt5.begin();it!=txt5.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-9.5,12.5,4);
        for(auto it=txt6.begin();it!=txt6.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-9.5,12,4);
        for(auto it=txt7.begin();it!=txt7.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }

    glRasterPos3f(-9.5,11.5,4);
        for(auto it=txt8.begin();it!=txt8.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
    glDisable(GL_LIGHTING_BIT);
    
    glutPostRedisplay();
}

void prozorStart() {

    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 1, 0.2, 0.8, 1 };

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
        glTranslatef(0,5,3);
        glScalef(100,100,0.01);
        glutSolidCube(10);
    glPopMatrix();
    glutPostRedisplay();
    glDisable(GL_LIGHTING);
}

void interfejsIgra() {
    glEnable(GL_LIGHTING_BIT);
    string txt = to_string(20 - imamoPecurku);
    string txt1 = to_string(20 - imamoSargarepu);
    string txt2 = to_string(20 - imamoParadajz);
    
    glColor3f(1,1,0.5);
    glRasterPos3f(-9,18.6,4.1);
        for(auto it=txt.begin();it!=txt.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
    glDisable(GL_LIGHTING_BIT);

    glEnable(GL_LIGHTING_BIT);
    glColor3f(1,1,0);
    glRasterPos3f(-9,11.7,4.1);
        for(auto it=txt1.begin();it!=txt1.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
    glDisable(GL_LIGHTING_BIT);

    glEnable(GL_LIGHTING_BIT);
    glColor3f(1,0.3,0.1);
    glRasterPos3f(-9,15,4.1);
        for(auto it=txt2.begin();it!=txt2.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
    glDisable(GL_LIGHTING_BIT);  

    glEnable(GL_LIGHTING_BIT);
    glColor3f(1,0,0);
    glRasterPos3f(-9.5,11,4.1);
        for(int i = 0;i < 3 - propusetno;i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'<');
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'\n');
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'\n');
        }
    glDisable(GL_LIGHTING_BIT);    
}

void prozorIgra() {
    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 0.8, 0.8, 0.3, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 0.8, 0.8, 0.3, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    glPushMatrix();
        glTranslatef(-9,25,4);
        glScalef(0.3,3,0.001);
        glutSolidCube(10);
    glPopMatrix();
    glutPostRedisplay();
    glDisable(GL_LIGHTING);
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
    glColor3f(0,0,1);
    if(pobedioIgru) {
        glRasterPos3f(-2.5,12,3.4);
        for(auto it=text.begin();it!=text.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
    }
    else if(izgubioIgru) {
        glRasterPos3f(-2,12,5);
        for(auto it=text2.begin();it!=text2.end();it++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
        }
        if(pogodjenBombom) {
            glRasterPos3f(-4,10,3.4);
            for(auto it=text3.begin();it!=text3.end();it++) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
            }
        }
        else if(promasioPovrce) {
            glRasterPos3f(-4,10,3.4);
            for(auto it=text4.begin();it!=text4.end();it++) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
            }
        }
    }
    glRasterPos3f(-4,9,3.4);
    for(auto it=text5.begin();it!=text5.end();it++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
    }

    glRasterPos3f(-4,8,3.4);
    for(auto it=text6.begin();it!=text6.end();it++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*it);
    }
    glDisable(GL_LIGHTING_BIT);
}

void prozorEnd() {
    glDisable(GL_LIGHTING_BIT);
    glDisable(GL_LIGHTING);
    glEnable(GL_LIGHTING);

    /* Koeficijenti ambijentalne refleksije materijala. */
    GLfloat ambient_coeffs[] = { 1, 1, 0 , 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { 1, 1, 0, 1 };

    /* Koeficijenti spekularne refleksije materijala. */
    GLfloat specular_coeffs[] = { 0, 0, 0, 1 };

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 100;

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