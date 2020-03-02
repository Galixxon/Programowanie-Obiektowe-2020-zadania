#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "Ksztalty.h"

#define PI 3.14159265

void wypiszInfo(figura* fig)
{
    printf("x: %.2f, y: %.2f, size: %.2f\n", fig->x,fig->y, fig->size);
}
//Dodanie trapezu zmusza do utworzenia osobnej funkcji tworzenia obiektu trapezu
figura* nowy_kwadrat(float _x, float _y, float _size)
{
    if(_size <= 0)
    {
        printf("Kwadrat z ujemnym bokiem! Ustawiono wielkość na domyślną: 1\n");
        _size = 1;
    }
    figura* new = malloc(sizeof(figura));
    new->size = _size;
    new->x = _x;
    new->y = _y;
    new->typ = Kwadrat;
    return new;
}

figura* nowy_trojkat(float _x, float _y, float _size)
{
    if(_size <= 0)
    {
        printf("Trojkat o ujemnym boku!  Ustawiono wielkość na domyślną: 1\n");
        _size = 1;
    }
    figura* new = malloc(sizeof(figura));
    new->size = _size;
    new->x = _x;
    new->y = _y;
    new->typ = Trojkat;
    return new;
}

figura* nowe_kolo(float _x, float _y, float _size)
{
    if(_size <= 0)
    {
        printf("Kolor z ujemnym promieniem!  Ustawiono wielkość na domyślną: 1\n");
        _size = 1;
    }
    figura* new = malloc(sizeof(figura));
    new->size = _size;
    new->x = _x;
    new->y = _y;
    new->typ = Kolo;
    return new;
}

float pole(figura* fig) //Dodanie trapezu zmusza do dodania tutaj 1 przypadku
{
    float pole;
    float a = fig->size;
    switch (fig->typ)
    {
    case Kwadrat:
        pole = a * a;
        break;
    case Trojkat:
        pole = (a*a) * sqrt(3)/4;
    case Kolo:
        pole = a*a*PI;
    default:
        break;
    }
    return pole;
}

void przesun(figura* fig, float x, float y)
{
    fig->x += x;
    fig->y += y;
}

float sumapol(figura* figs, int size)
{
    float p = 0;
    for(int i = 0; i < size; i++)
    {
        p += pole(&figs[i]);
    }
    return p;
}
