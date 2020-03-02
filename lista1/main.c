#include "Ksztalty.h"
#include "ulamki.h"

#include<stdio.h>

void przykladulamki()
{
    Ulamek* ul1 = nowy_ulamek(3,-9);
    Ulamek* ul2 = nowy_ulamek(7,3);
    Ulamek* pomocnuczy;
    pomocnuczy = dodaj(ul1,ul2);
    wypisz(pomocnuczy);
    putchar('\n');
    pomocnuczy = odejmij(ul1,ul2);
    wypisz(pomocnuczy);
    putchar('\n');
    pomocnuczy = pomnoz(ul1,ul2);
    wypisz(pomocnuczy);
    putchar('\n');
    pomocnuczy = podziel(ul1,ul2);
    wypisz(pomocnuczy);
    putchar('\n');


    
}

void przykladKsztalty()
{
    
}

int main()
{
    
    return 0;
}