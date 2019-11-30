#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>

using namespace std;

// ugao kamere
float ugao = 90;

// pozicije kotlica
float lonacX = 0;
float lonacTekuci = 0;

// funkcija timer koja osvezava prozor
void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
}

// funkcije akcije tastature
// ovde prvo na klik 'j' i 'l' pomeramo kameru levo desno
void keyboardFunction(unsigned char key, int x, int y) {
    if(key == 'j') {
        ugao += 0.01;
    }
    if(key == 'l') {
        ugao -= 0.01;
    }
    if(key == 'a' and lonacTekuci > -8.0) {
        lonacTekuci -= 4;
    }
    if(key == 'd' and lonacTekuci < 8.0) {
        lonacTekuci += 4;
    }
}

// prototip kotlica, koji ce imati i toruse na sebi, animaciju rotiranja, osencenje
void crtajLonac() {
    glColor3f(0.5,0.5,0.5);
    double clipPovrs[] = {0, -1, 0, 2.5};
    glPushMatrix();
        glTranslatef(lonacTekuci,1.75f,0);
        glutSolidSphere(1.5,40,40);
    glPopMatrix();
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
        gluLookAt(10*cos(ugao),2,10*sin(ugao),
                    0, 0, 0,
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
        crtajLonac();

    glPopMatrix();

    glutSwapBuffers();
}

void inicijalizujGlut() {
    glClearColor(0.75,0.75,0.75,0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(90.0, 1920.0/2080.0, 0.1, 250.0);
    glMatrixMode(GL_MODELVIEW);
    timer(60);
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