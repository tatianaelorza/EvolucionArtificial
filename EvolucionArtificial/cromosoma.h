#ifndef CROMOSOMAS_H
#define CROMOSOMAS_H

#include <vector>
using namespace std;

class Cromosoma{
private:

    vector <int> genes;
    void mutar();
public:
    Cromosoma();

    int getGen(int numeroGen);
    int getInteligencia();
    void cruzar(Cromosoma cromosomaPadre1, Cromosoma cromosomaPadre2);


};
#endif // CROMOSOMAS_H
