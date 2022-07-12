#include <sembrador.h>
#include <ctime>
#include <cstdlib>
#include <constantes.h>

Sembrador::Sembrador()
{
    fila = rand () % maximoFilas;
    columna = rand () % maximoColumnas;
    movimiento = rand () % 8;

}

int Sembrador::getFila()
{
    return fila;
}

int Sembrador::getColumna()
{
    return columna;
}

int Sembrador::getMovimiento()
{
    return movimiento;
}

void Sembrador::sembrar(Comida &comida)
{
    comida.agregar(fila , columna , cantidadSembrada );
}

void Sembrador::mover()
{
    int fila_prueba , columna_prueba;
    bool buscarNuevaPosicion = true;


    while (buscarNuevaPosicion)
    {
        if ((float)rand () / RAND_MAX*100 < probabCambioDirSembrador)
            movimiento = rand () %8 ;

        fila_prueba = fila + movimiento_relativo[movimiento].f;
        columna_prueba = columna + movimiento_relativo[movimiento].c;


        if (estaEnTerritorio (fila_prueba , columna_prueba))
        {
            fila = fila_prueba;
            columna = columna_prueba;
            buscarNuevaPosicion = false;
        }
        else
            movimiento = rand () %8 ;
    }
}

bool Sembrador::estaEnTerritorio(int _fila, int _columna)
{
    return (_fila<maximoFilas and _columna<maximoColumnas and _fila>=0 and _columna>=0);
}
