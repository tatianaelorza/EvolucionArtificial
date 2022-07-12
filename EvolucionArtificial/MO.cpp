#include <MO.h>
#include <cstdlib>
#include <ctime>
#include <constantes.h>
#include <iostream>

MO::MO()
{

    energia = energiaInicial;
    edadMO=0;
    fila = rand () % maximoFilas;
    columna = rand () % maximoColumnas;
    movimiento = rand () % 8;

}

void MO::hijo(MO Padre1,MO Padre2) //
{
    cromosoma.cruzar(Padre1.getCromosoma(),Padre2.getCromosoma());
    edadMO=0;
    energia= energiaInicial;
}

void MO::comer(Comida &comida_)
{
    int cantidad=0;

    if( energia+cantidadComeMO<=energiaMaximaMO)
    {
        cantidad=comida_.quitar(fila,columna,cantidadComeMO);
    }
    else
    {
        cantidad=comida_.quitar(fila,columna,(energiaMaximaMO-energia));
    }

    energia = energia+cantidad;
}
void MO::mover(Comida &comida_)
{
    if(estaVivo() and (energia-energiaMovimientoMO)>=0)
    {
        int fila_pruebaPatita , columna_pruebaPatita;
        bool buscarNuevaPosicion = true;
        int numeroPatita=0;

        while (buscarNuevaPosicion)
        {
            while (numeroPatita<8)
            {
                fila_pruebaPatita = fila + movimiento_relativo[numeroPatita].f;
                columna_pruebaPatita = columna + movimiento_relativo[numeroPatita].c;

                if (estaEnTerritorio(fila_pruebaPatita, columna_pruebaPatita) and
                        comida_.hayComida(fila_pruebaPatita , columna_pruebaPatita) and
                        estaEnTerritorio((fila+ movimiento_relativo[cromosoma.getGen(numeroPatita)].f ), (columna + movimiento_relativo[cromosoma.getGen(numeroPatita)].c )) )
                {
                    fila = fila + movimiento_relativo[cromosoma.getGen(numeroPatita)].f;
                    columna = columna + movimiento_relativo[cromosoma.getGen(numeroPatita)].c;
                    movimiento = cromosoma.getGen(numeroPatita);
                    buscarNuevaPosicion = false;
                }
                else
                {
                    numeroPatita++;
                }
            }

            if (numeroPatita == 8)
            {
                movimiento = rand () %8;

                int fila_pruebaMO = fila + movimiento_relativo[movimiento].f;
                int columna_pruebaMO = columna + movimiento_relativo[movimiento].c;

                while (!estaEnTerritorio(fila_pruebaMO, columna_pruebaMO))
                {
                    movimiento = rand () % 8;
                    fila_pruebaMO = fila + movimiento_relativo[movimiento].f;
                    columna_pruebaMO = columna + movimiento_relativo[movimiento].c;
                }

                fila= fila_pruebaMO;
                columna = columna_pruebaMO;
                buscarNuevaPosicion = false;
            }
        }
        energia = energia - energiaMovimientoMO;
        edadMO++;
    }
}

Cromosoma MO::getCromosoma()
{
    return cromosoma;
}

int MO::getEnergia()
{
    return energia;
}

int MO::getFila()
{
    return fila;
}

int MO::getColumna()
{
    return columna;
}

int MO::getEdadMO()
{
    return edadMO;
}
int MO::getInteligencia()
{
    return cromosoma.getInteligencia();
}
bool MO::estaVivo()
{
    return (energia>0);
}

bool MO::estaEnTerritorio(int _fila, int _columna)
{
    return (_fila<maximoFilas and _columna<maximoColumnas and _fila>=0 and _columna>=0);
}
