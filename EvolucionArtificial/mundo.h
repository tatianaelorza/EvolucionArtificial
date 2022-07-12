#ifndef MUNDO_H
#define MUNDO_H
#include <vector>
#include <constantes.h>
#include <MO.h>
#include <sembrador.h>

using namespace std;

class Mundo{
private:
    vector <MO> MOs;
    vector <int> MOsTotalEdades;
    vector <Sembrador> sembradores;
    Comida comida;
    int epoca;

    void reproducir();
    void llegadadelInvierno();

public:
    Mundo();

    int sembradoresFila(int n);
    int sembradoresColumna(int n);
    int MOFila(int n);
    int MOColumna(int n);
    int getEnergiaMO(int n);
    int getEpoca();
    int getEdadMOs(int n);
    int getCantidadTotalComida();
    bool hayComida(int fila,int columna);
    int getcantidadComida(int fila,int columna);

    int cantidadTotalMOs();
    int cantidadMOsVivos();
    int getInteligenciaMOs();

    int MOmasVivio();
    int MOmenosVivio();

    void vivir();
    void salidaPorConsola();

};
#endif // MUNDO_H
