#ifndef CONSTANTES_H
#define CONSTANTES_H
#include <vector>
using namespace std;

//Propuesta de contantes:

// Mundo
const int maximoFilas = 100;
const int maximoColumnas = 100;
const int invierno=100;

// MOs
const int cantidadMOs = 80; // cantidad inicial de MO.
const int energiaInicial = 50; // energía con que nace cada MO.
const int energiaMaximaMO = 200; // máximo de energía en cada MO.
const int cantidadComeMO = 20; // comida que comen los MO.
const int energiaMovimientoMO = 1; // energía que consumen en cada


// Sembradores
const int cantSembradores = 40; // 40= cantidad inicial de Sembradores.
const int cantidadSembrada = 50; // comida que siembran los Sembradores.
struct Posicion {int f , c; };
const vector <Posicion> movimiento_relativo = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

// Evolución
const int movimientosParaReproducir = 10; // movimientos antes de

// reproducir MO
const int probabilidadMutacion = 2; // probabilidad de mutaciones

// nuevo MO.
// Movimiento
const int probabCambioDirSembrador = 5; // probabilidad cambio

// dirección sembrador.
// Comida
const int maximoEnComida = 200; // máximo de energía en cada celda.

#endif // CONSTANTES_H
