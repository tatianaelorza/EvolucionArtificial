#ifndef MO_H
#define MO_H
#include <constantes.h>
#include <cromosoma.h>
#include <comida.h>

class MO{
private:

    int fila;
    int columna;
    int energia;
    Cromosoma cromosoma;
    int edadMO;
    int movimiento;
    bool estaEnTerritorio(int _fila, int _columna);

public:
    MO();

    void hijo(MO Padre1,MO Padre2);
    void comer(Comida &comida_);
    void mover(Comida &comida_);

    Cromosoma getCromosoma();
    int getEnergia();
    int getFila();
    int getColumna();
    int getEdadMO();
    int getInteligencia();
    bool estaVivo();






};

#endif // MO_H
