#include <comida.h>

Comida::Comida()
{
    matrizComida.resize(maximoFilas);

    for (int i=0 ; i<maximoFilas ; i++)
    {
        matrizComida[i].resize((maximoColumnas) , int (0) );
    }
}

void Comida::setComida(int fila, int columna,int cantidad)
{
    matrizComida[fila][columna]=cantidad;
}

int Comida::getComida(int fila, int columna)
{
    return matrizComida[fila][columna];
}

void Comida::agregar (int fila, int columna, int cantidad)
{
    if  (estaEnTerritorio(fila,columna))
    {
        if (matrizComida[fila][columna] + cantidad <= maximoEnComida)
        {
            matrizComida[fila][columna] += cantidad;
        }
        else //si lo sobrepasa
            matrizComida[fila][columna] = maximoEnComida;
    }
}

int Comida::quitar (int fila, int columna, int cantidad)
{
    int comidaQuitada=0;

    if (estaEnTerritorio(fila,columna))
    {
        if(cantidad<matrizComida[fila][columna]){
            matrizComida[fila][columna] -= cantidad;
            comidaQuitada=cantidad;
        }
        else
        {
            comidaQuitada = matrizComida[fila][columna];
            matrizComida[fila][columna] = 0;
        }
    }
    return comidaQuitada;
}

bool Comida::hayComida(int fila, int columna)
{
    bool hayComida = false;

    if(estaEnTerritorio(fila,columna))
    {
        if (matrizComida[fila][columna] >0)
            hayComida = true;
    }

    return hayComida;
}

int Comida::cantidad(int fila, int columna)
{
    int cantidadEnPosicion=0;
    if(estaEnTerritorio(fila,columna))
        cantidadEnPosicion = matrizComida[fila][columna];
    return cantidadEnPosicion;
}

int Comida::cantidadTotal()
{
    int aux=0;
    for(int i=0;i<maximoFilas;i++){
        for(int j=0;j<maximoColumnas;j++){
            aux+=cantidad(i,j);
        }
    }
    return aux;
}

bool Comida::estaEnTerritorio(int _fila, int _columna)
{
    return (_fila<maximoFilas and _columna<maximoColumnas and _fila>=0 and _columna>=0);
}
