#ifndef COMIDA_H
#define COMIDA_H
#include <constantes.h>
#include <vector>
using namespace std;

class Comida{
private:

    vector <vector<int>> matrizComida;

    bool estaEnTerritorio(int _fila, int _columna);

public:
    Comida();


    void setComida(int fila, int columna,int cantidad);
    int getComida(int fila, int columna);
    int quitar(int fila, int columna, int cantidad);
    void agregar(int fila, int columna, int cantidad);
    bool hayComida(int fila, int columna);
    int cantidad(int fila, int columna);
    int cantidadTotal();
};
#endif // COMIDA_H

