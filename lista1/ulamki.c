#include<stdio.h>
#include<stdlib.h>
#include"ulamki.h"



int nwd(int a, int b)
{
    int c;
    a = (a<0) ? -a : a;
    b = (b<0) ? -b : b;
    if(b<a)
    {
        c = b;
        b = a;
        a = c;
    }
    while(b!=0)
    {
        c = b;
        b = a%b;
        a = c;
    }
    
    return a;
}

Ulamek* skroc_ulamek(Ulamek* ul)
{
    int ul_nwd = nwd(ul->licznik, ul->mianownik);
    (ul->licznik) /= ul_nwd;
    (ul->mianownik) /= ul_nwd;
    if(ul->mianownik < 0)
    {
        (ul->licznik) *= -1;
        (ul->mianownik) *= -1;
    }
    return ul;
}

Ulamek* nowy_ulamek(int l, int m)
{
    Ulamek* nowy = malloc(sizeof(Ulamek));
    nowy->licznik = l;
    nowy->mianownik = m;
    //nowy = skroc_ulamek(nowy);
    return nowy;
}

Ulamek* dodaj(Ulamek* u1, Ulamek* u2)
{
    Ulamek* nowy = malloc(sizeof(Ulamek));
    int l1,l2;
    int a = u1->mianownik;
    int b = u2->mianownik;
    int nww = (a*b)/nwd(a,b);
    l1 = u1->licznik * nww/u1->mianownik;
    l2 = u2->licznik * nww/u2->mianownik;
    nowy->licznik = l1 + l2;
    nowy->mianownik = nww;
    nowy = skroc_ulamek(nowy);
    return nowy;
}

Ulamek* pomnoz(Ulamek* u1, Ulamek* u2)
{
    Ulamek* nowy = malloc(sizeof(Ulamek));
    nowy->licznik = u1->licznik * u2->licznik;
    nowy->mianownik = u1->mianownik * u2->mianownik;
    nowy = skroc_ulamek(nowy);
    return nowy;
}

Ulamek* odejmij(Ulamek* u1, Ulamek* u2)
{
    Ulamek* nowy;
    u2->licznik *= -1;
    nowy = dodaj(u1,u2);
    return nowy;
}

Ulamek* podziel(Ulamek* u1, Ulamek* u2)
{
    Ulamek* nowy;
    int temp = u2->licznik;
    u2->licznik = u2->mianownik;
    u2->mianownik = temp;
    nowy = pomnoz(u1,u2);
    return nowy;
}

void alt_dodaj(Ulamek* u1, Ulamek* u2)
{
    int l1,l2;
    int a = u1->mianownik;
    int b = u2->mianownik;
    int nww = (a*b)/nwd(a,b);
    l1 = u1->licznik * nww/u1->mianownik;
    l2 = u2->licznik * nww/u2->mianownik;
    u2->licznik = l1 + l2;
    u2->mianownik = nww;
    u2 = skroc_ulamek(u2);
}

void alt_pomnoz(Ulamek* u1, Ulamek* u2)
{
    u2->licznik = u1->licznik * u2->licznik;
    u2->mianownik = u1->mianownik * u2->mianownik;
    u2 = skroc_ulamek(u2);
}

void alt_odejmij(Ulamek* u1, Ulamek* u2)
{
    u2->licznik *= -1;
    alt_dodaj(u1,u2);
}

void alt_podziel(Ulamek* u1, Ulamek* u2)
{
    int temp = u2->licznik;
    u2->licznik = u2->mianownik;
    u2->mianownik = temp;
    alt_pomnoz(u1,u2);
}

void wypisz(Ulamek* ul)
{
    printf("%d/%d", ul->licznik, ul->mianownik);
}