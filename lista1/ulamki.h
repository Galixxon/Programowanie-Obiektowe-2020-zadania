#ifndef ULAMKI_H_
#define ULAMKI_H_

typedef struct Ulamek
{
    int licznik;
    int mianownik;
}Ulamek;

int nwd(int a, int b);
Ulamek* skroc_ulamek(Ulamek* ul);
Ulamek* nowy_ulamek(int l, int m);
Ulamek* dodaj(Ulamek* u1, Ulamek* u2);
Ulamek* pomnoz(Ulamek* u1, Ulamek* u2);
Ulamek* odejmij(Ulamek* u1, Ulamek* u2);
Ulamek* podziel(Ulamek* u1, Ulamek* u2);

void alt_dodaj(Ulamek* u1, Ulamek* u2);
void alt_pomnoz(Ulamek* u1, Ulamek* u2);
void alt_odejmij(Ulamek* u1, Ulamek* u2);
void alt_podziel(Ulamek* u1, Ulamek* u2);

void wypisz(Ulamek* ul);

#endif