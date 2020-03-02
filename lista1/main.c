#include "Ksztalty.h"
#include <stdlib.h>
#include "ulamki.h"

#include<stdio.h>

void przykladulamki()
{
    Ulamek* ul1 = nowy_ulamek(3,-9);
    Ulamek* ul2 = nowy_ulamek(7,3);
    Ulamek* pomocnuczy;
    printf("Zwracanie wskaźnika\n");
    pomocnuczy = dodaj(ul1,ul2);
    wypisz(ul1);
    putchar(' ');
    wypisz(ul2);
    putchar('\n');
    printf("Dodawanie ");
    wypisz(pomocnuczy);
    putchar('\n');
    pomocnuczy = odejmij(ul1,ul2);
    printf("Odejmowanie ");
    wypisz(pomocnuczy);
    putchar('\n');
    pomocnuczy = pomnoz(ul1,ul2);
    printf("Mnożenie ");
    wypisz(pomocnuczy);
    putchar('\n');
    pomocnuczy = podziel(ul1,ul2);
    printf("Dzielenie ");
    wypisz(pomocnuczy);
    
    putchar('\n');
    putchar('\n');
    printf("Zmiana 2. argumentu\n");

    wypisz(ul1);
    putchar(' ');
    wypisz(ul2);
    putchar('\n');
    printf("Odejmowanie ");
    alt_odejmij(ul1,ul2);
    wypisz(ul1);
    putchar(' ');
    wypisz(ul2);
    putchar('\n');
    putchar('\n'); 
}

void przykladKsztalty()
{
    figura* figury = malloc(sizeof(figura) * 3);
    figury[0] = *(nowy_kwadrat(3.0,2.0,3.0));
    figury[1] = *(nowe_kolo(3.0,2.0,4.0));
    figury[2] = *(nowy_trojkat(3.0,2.0,5.0));
    printf("kwadrat: ");
    wypiszInfo(&figury[0]);
    printf("kolo: ");
    wypiszInfo(&figury[1]);
    printf("trojkat: ");
    wypiszInfo(&figury[2]);
    przesun(&figury[1], 3.0, 4.3);
    printf("Przesuniete kolo: ");
    wypiszInfo(&figury[1]);
    
    printf("Pole jednej figury: %.2f\n", pole(&figury[0]));
    printf("Pole wszystkich figur: %.2f\n", sumapol(figury,3));

    
}

int main()
{
    przykladulamki();
    przykladKsztalty();
    return 0;
}