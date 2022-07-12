#include <mundo.h>
#include <sembrador.h>
#include <MO.h>
#include <comida.h>
#include <iostream>
#include <constantes.h>
#include <ctime>
#include <algorithm>

using namespace std;
Mundo::Mundo()
{
    epoca=0;
    sembradores.resize(cantSembradores);
    MOs.resize(cantidadMOs);
    MOsTotalEdades.resize(cantidadMOs);
    srand (time (NULL));

}

int Mundo::sembradoresFila(int n)
{
    return sembradores[n].getFila();
}

int Mundo::sembradoresColumna(int n)
{
    return sembradores[n].getColumna();
}

int Mundo::MOFila(int n)
{
    return MOs[n].getFila();
}

int Mundo::MOColumna(int n)
{
    return MOs[n].getColumna();
}
int Mundo::getEnergiaMO(int n)
{
    return MOs[n].getEnergia();
}

int Mundo::getEpoca()
{
    return epoca;
}
int Mundo::getEdadMOs(int n)
{
    return MOsTotalEdades[n];
}
int Mundo::getCantidadTotalComida()
{
    return comida.cantidadTotal();
}
bool Mundo::hayComida(int fila,int columna)
{
    return comida.hayComida(fila,columna);
}
int Mundo::getcantidadComida(int fila, int columna)
{
    return comida.getComida(fila,columna);
}

int Mundo::cantidadTotalMOs()
{
    return MOs.size();
}
int Mundo::cantidadMOsVivos()
{
    int contador=0;

    for(unsigned i=0;i<MOs.size();i++)
        if(MOs[i].estaVivo())
            contador++;

    return contador;
}

int Mundo::getInteligenciaMOs()
{
    int suma=0;

    for (unsigned i=0; i<MOs.size();i++)
        if (MOs[i].estaVivo())
            suma=suma + MOs[i].getInteligencia();

    return suma;
}
void Mundo::reproducir()
{
    int idPadre1;
    int idPadre2;
    if (cantidadMOsVivos()>=2)
    {
        for (unsigned int i=0;i<MOs.size();i++)
            if (!MOs[i].estaVivo())
            {
                idPadre1 = rand()% MOs.size();
                idPadre2 = rand()% MOs.size();
                while (!MOs[idPadre1].estaVivo() || !MOs[idPadre2].estaVivo()|| (idPadre1==idPadre2))
                {
                    idPadre1 = rand()% MOs.size();
                    idPadre2 = rand()% MOs.size();
                }

                MOsTotalEdades.push_back(MOs[i].getEdadMO());
                MOs[i].hijo(MOs[idPadre1],MOs[idPadre2]);
            }
    }
}
int Mundo::MOmasVivio()
{
    int ID;
    vector <int> :: iterator maximoVivido;

    maximoVivido= max_element(MOsTotalEdades.begin(), MOsTotalEdades.end());

    for (int unsigned i=0;i<MOsTotalEdades.size(); i++ )
        if (MOsTotalEdades[i] == *maximoVivido)
            ID = i;

    return ID;
}

int Mundo::MOmenosVivio()
{
    int ID;
    vector <int> :: iterator menosVivido;

    menosVivido= min_element(MOsTotalEdades.begin(), MOsTotalEdades.end());

    for (int unsigned i=0;i<MOsTotalEdades.size(); i++ )
        if (MOsTotalEdades[i] == *menosVivido)
            ID = i;

    return ID;
}
void Mundo::llegadadelInvierno()
{
    for(unsigned int i=0;i<maximoFilas;i++)
        for(unsigned int j=0;j<maximoColumnas;j++)
            comida.setComida(i,j,0);
}
void Mundo::vivir()
{
    for(unsigned i=0;i<sembradores.size();i++)
    {
        sembradores[i].sembrar(comida);
        sembradores[i].mover();
    }

    for(unsigned i=0;i<MOs.size();i++)
    {
        if(MOs[i].estaVivo())
        {
            MOs[i].mover(comida);
            MOs[i].comer(comida);
            MOsTotalEdades[i]=MOs[i].getEdadMO();
        }
    }

    if(epoca%invierno==0)
        llegadadelInvierno();

    if(epoca%movimientosParaReproducir==0)
        reproducir();

    epoca++;
}

void Mundo::salidaPorConsola()
{   for(unsigned i=0;i<sembradores.size();i++)
    {
        cout<<"Posicion del sembrador "<<i<<": "<<endl;
        cout<<"("<<sembradoresFila(i)<<","<<sembradoresColumna(i)<<")"<<endl;
    }
    cout<<endl<<endl;
    cout<<endl<<"Cantidad total de comida: "<<comida.cantidadTotal()<<endl<<endl<<endl<<endl;

    for(unsigned i=0;i<MOs.size();i++)
    {
        cout<<"Posicion del microorganismo "<<i<<": "<<endl;
        cout<<"("<<MOFila(i)<<","<<MOColumna(i)<<")"<<endl;
        cout<<"mos: "<<i<<endl<<"Cantidad de energia "<<MOs[i].getEnergia()<<endl;
    }
    cout<<"Inteligencia total de MOs: "<<getInteligenciaMOs()<<endl<<endl<<endl;

}

