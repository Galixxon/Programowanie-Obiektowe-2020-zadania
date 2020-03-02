#ifndef KSZTALTY_H_
#define KSZTALTY_H_

typedef enum typfig {Trojkat, Kolo, Kwadrat} typfig;

typedef struct Figura
{
    float x;
    float y;
    float size;
    typfig typ;

} figura;

figura* nowy_kwadrat(float _x, float _y, float _size);
figura* nowy_trojkat(float _x, float _y, float _size);
figura* nowe_kolo(float _x, float _y, float _size);
float pole(figura* fig);
float sumapol(figura* figs, int size);
#endif