#include<iostream>
#include<string>
#include<GL/glut.h>

#include"teksture.hpp"

using namespace std;

unsigned int ucitaj_sliku(const char* path) {
    FILE *file=fopen(path,"rb");
    if(file==NULL){
        return 10000;
    }
    unsigned int sirina;
    unsigned int visina;
    unsigned short bit_c;
    unsigned int djubre;

  fread(&djubre, 2, 1, file);
  fread(&djubre, 4, 1, file);
  fread(&djubre, 2, 1, file);
  fread(&djubre, 2, 1, file);
  fread(&djubre, 4, 1, file);

  /* Ocitavaju se podaci drugog zaglavlja. */
  fread(&djubre, 4, 1, file);
  fread(&sirina, 4, 1, file);
  fread(&visina, 4, 1, file);
  fread(&djubre, 2, 1, file);
  fread(&bit_c, 2, 1, file);
  fread(&djubre, 4, 1, file);
  fread(&djubre, 4, 1, file);
  fread(&djubre, 4, 1, file);
  fread(&djubre, 4, 1, file);
  fread(&djubre, 4, 1, file);
  fread(&djubre, 4, 1, file);

  char *pixeli;
  unsigned char r,g,b,a;
  if(bit_c==24)
    pixeli=(char *)malloc(3*sirina*visina*sizeof(char));
else if(bit_c==32)
    pixeli=(char *)malloc(4*sirina*visina*sizeof(char));
else 
    return 10001;
    if(bit_c==24)
    for (int i = 0; i < sirina * visina; i++) {
      fread(&b, sizeof(char), 1, file);
      fread(&g, sizeof(char), 1, file);
      fread(&r, sizeof(char), 1, file);

      pixeli[3 * i] =r;
      pixeli[3 * i + 1] = g;
      pixeli[3 * i + 2] = b;
    }
    if(bit_c==32)
    for (int i = 0; i < sirina * visina; i++) {
      fread(&b, sizeof(char), 1, file);
      fread(&g, sizeof(char), 1, file);
      fread(&r, sizeof(char), 1, file);
      fread(&a, sizeof(char), 1, file);

      pixeli[4 * i] = g;
      pixeli[4 * i + 1] = b;
      pixeli[4 * i + 2] = r;
      pixeli[4 * i + 3] = a;
    }
    unsigned int id;
    glGenTextures(1,&id);
    glBindTexture(GL_TEXTURE_2D,id);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 sirina, visina, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, pixeli);
    free(pixeli);
    fclose(file);
    glBindTexture(GL_TEXTURE_2D,0);
  return id;
}

void vrata() {
    glDisable(GL_LIGHTING); 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, index1);

    glEnable(GL_LIGHTING_BIT);

    glColor3f(1,1,0.6);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-20, -10, -40);

        glTexCoord2f(1, 0);
        glVertex3f(-10, -10, -40);

        glTexCoord2f(1, 1);
        glVertex3f(-10, 30, -40);

        glTexCoord2f(0, 1);
        glVertex3f(-20, 30, -40);
    glEnd();

    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Nova slika se salje na ekran. */
    glDisable(GL_TEXTURE_2D);
    
    
    // glutSwapBuffers();
    glDisable(GL_LIGHTING_BIT);    
    glEnable(GL_LIGHTING);
}

void pod() {
    glDisable(GL_LIGHTING); 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, index2);

    glEnable(GL_LIGHTING_BIT);

    glColor3f(1,0.4,0.1);

    for(int i=0;i<16;i++) {
        for(int j=0;j<16;j++) {
            glBegin(GL_QUADS);
                glNormal3f(0, 1, 0);

                glTexCoord2f(0, 0);
                glVertex3f(-40 + i*5, -10, -40 + j*5);

                glTexCoord2f(1, 0);
                glVertex3f(-30 + i*5, -10, -40 + j*5);

                glTexCoord2f(1, 1);
                glVertex3f(-30 + i*5, -10, -30 + j*5);

                glTexCoord2f(0, 1);
                glVertex3f(-40 + i*5, -10, -30 + j*5);
            glEnd();
        }
    }

    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Nova slika se salje na ekran. */
    glDisable(GL_TEXTURE_2D);
    
    
    // glutSwapBuffers();
    glDisable(GL_LIGHTING_BIT);    
    glEnable(GL_LIGHTING);    
}

void Remzi() {
    glDisable(GL_LIGHTING); 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, index3);
    
    glEnable(GL_LIGHTING_BIT);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0.1, 0);
        glVertex3f(5, 5 , 4.1);

        glTexCoord2f(1, 0);
        glVertex3f(10, 5, 4.1);

        glTexCoord2f(1, 1);
        glVertex3f(10, 15, 4.1);

        glTexCoord2f(0.1, 1);
        glVertex3f(5, 15, 4.1);
    glEnd();
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0.1, 0);
        glVertex3f(-10, 5 , 4.1);

        glTexCoord2f(1, 0);
        glVertex3f(-5, 5, 4.1);

        glTexCoord2f(1, 1);
        glVertex3f(-5, 15, 4.1);

        glTexCoord2f(0.1, 1);
        glVertex3f(-10, 15, 4.1);
    glEnd();
    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Nova slika se salje na ekran. */
    glDisable(GL_TEXTURE_2D);
    
    glDisable(GL_LIGHTING_BIT);    
    // glutSwapBuffers();   
    glEnable(GL_LIGHTING);
}

void RemziSrecan() {
    glDisable(GL_LIGHTING); 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, index4);

    glEnable(GL_LIGHTING_BIT);

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0.1, 0);
        glVertex3f(-3, 8 , 3.1);

        glTexCoord2f(1, 0);
        glVertex3f(3, 8, 3.1);

        glTexCoord2f(1, 1);
        glVertex3f(3, 15, 3.1);

        glTexCoord2f(0.1, 1);
        glVertex3f(-3, 15, 3.1);
    glEnd();
    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Nova slika se salje na ekran. */
    glDisable(GL_TEXTURE_2D);
    
    glDisable(GL_LIGHTING_BIT);
    // glutSwapBuffers();   
    glEnable(GL_LIGHTING);
}

void RemziLjut1() {
    glDisable(GL_LIGHTING); 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, index5);

    glEnable(GL_LIGHTING_BIT);

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0.1, 0);
        glVertex3f(-4.5, 8 , 3.1);

        glTexCoord2f(1, 0);
        glVertex3f(-0, 8, 3.1);

        glTexCoord2f(1, 1);
        glVertex3f(-0, 15, 3.1);

        glTexCoord2f(0.1, 1);
        glVertex3f(-4.5, 15, 3.1);
    glEnd();
    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Nova slika se salje na ekran. */
    glDisable(GL_TEXTURE_2D);
    
    glDisable(GL_LIGHTING);
    // glutSwapBuffers();   
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHTING_BIT);   
}

void RemziLjut2() {
    glDisable(GL_LIGHTING); 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, index6);

    glEnable(GL_LIGHTING_BIT);

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0.1, 0);
        glVertex3f(-0, 8 , 3.1);

        glTexCoord2f(1, 0);
        glVertex3f(4.5, 8, 3.1);

        glTexCoord2f(1, 1);
        glVertex3f(4.5, 15, 3.1);

        glTexCoord2f(0.1, 1);
        glVertex3f(-0, 15, 3.1);
    glEnd();
    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Nova slika se salje na ekran. */
    glDisable(GL_TEXTURE_2D);
    
    glDisable(GL_LIGHTING_BIT);
    // glutSwapBuffers();   
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHTING_BIT);   
}