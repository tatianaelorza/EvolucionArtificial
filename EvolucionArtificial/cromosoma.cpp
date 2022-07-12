#include <cromosoma.h>
#include <constantes.h>
#include <ctime>
#include <cstdlib>

Cromosoma::Cromosoma()
{
    genes.resize(8);
    for (unsigned i=0;i<genes.size();i++)
    {
        genes[i]= rand () % 8;
    }
}

int Cromosoma::getGen(int numeroGen)
{
    return genes[numeroGen];
}

int Cromosoma::getInteligencia()
{
    int suma=0;
    for (unsigned int i=0 ; i < genes.size() ; i++)
    {
        if (genes[i] == (int) i)
            suma++;
    }
    return suma;
}

void Cromosoma:: mutar()
{
    int auxiliarGen=rand () % 8;
    genes[auxiliarGen]=rand () % 8;
}

void Cromosoma::cruzar(Cromosoma cromosomaPadre1, Cromosoma cromosomaPadre2)
{
    int posicionCruza;
    posicionCruza=1+ rand () % 7;

    for(int i=0;i<posicionCruza;i++)
    {
        genes[i]=cromosomaPadre1.getGen(i);
    }
    for(int i=posicionCruza;i<8;i++)
    {
        genes[i]=cromosomaPadre2.getGen(i);
    }

    if ((float)rand () / RAND_MAX*100 < probabilidadMutacion)
        mutar();

}

