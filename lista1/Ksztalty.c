#include<stdlib.h>
#include<math.h>
#include "Ksztalty.h"

#define PI 3.14159265

enum typfig {Trojkat, Kolo, Kwadrat};

struct Figura
{
    float x;
    float y;
    float size;
    typfig typ;

};


//Dodanie trapezu zmusza do utworzenia osobnej funkcji tworzenia obiektu trapezu
figura* nowy_kwadrat(float _x, float _y, float _size)
{
    if(_size <= 0)
    {
        printf("Kwadrat z ujemnym bokiem!");
        return NULL;
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
        printf("Trojkat o ujemnym boku!");
        return NULL;
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
        printf("Kolor z ujemnym promieniem!");
        return NULL;
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

float sumapol(figura* figs, int size)
{
    float p = 0;
    for(int i = 0; i < size; i++)
    {
        p += pole(&figs[i]);
    }
    return p;
}
