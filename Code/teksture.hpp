#ifndef TEKSTURE_H_
#define TEKSTURE_H_

#include<iostream>
#include<string>

extern unsigned int index1;
extern unsigned int index2;
extern unsigned int index3;
extern unsigned int index4;
extern unsigned int index5;
extern unsigned int index6;

// funkcija koju sam preuzeo od Mihajla Ilica
unsigned int ucitaj_sliku(const char* path);

// postavljamo vrata
void vrata();

// postavljamo vise "plocica" za patos
void pod();

// Remzi u start meniju
void Remzi();

// Remzi kada si pobedio igricu
void RemziSrecan();

// Remzi kada si izgubio part 1
void RemziLjut1();

// Remzi kada si izgubio part 2
void RemziLjut2();

#endif
