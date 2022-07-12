#ifndef SEMBRADOR_H
#define SEMBRADOR_H
#include <comida.h>


class Sembrador{
private:
    int fila;
    int columna;
    int movimiento;

    bool estaEnTerritorio (int _fila , int _columna);
public:
    Sembrador();

    int getFila();
    int getColumna();
    int getMovimiento();
    void sembrar(Comida &);
    void mover();

};

#endif // SEMBRADOR_H
