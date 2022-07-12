#include <archivoTexto.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <mundo.h>
#include <constantes.h>
#include <comida.h>

using namespace std;

ArchivoTexto::ArchivoTexto(string nombre)
{
    architexto.open(nombre, ios::in|ios::out|ios::trunc);
}

void ArchivoTexto::grabar(Mundo &mundo0)
{

    if (architexto.is_open())
    {
        architexto<<"epoca: "<<mundo0.getEpoca()<<endl;
        architexto<<"cantidad total de comida: "<<mundo0.getCantidadTotalComida()<<endl;

        for (int i=0; i<cantSembradores; i++)
        {
            architexto<<"ID Sembrador "<<i<<"   Ubicacion: "<<mundo0.sembradoresFila(i)<<" ";
            architexto<<mundo0.sembradoresColumna(i)<<"\n";
        }
    }
    else cout<<"El archivo de texto no pudo crearse";
}

string ArchivoTexto::leer()
{    
    string contenido;
    string aux;

    architexto.seekg(0,ios::beg);
    if(architexto.is_open())
    {
        while (getline (architexto, aux))
        {
            contenido += aux + "\n";
        }
    }
    else cout<<"El archivo de texto no pudo abrirse";

    return contenido;
}

void ArchivoTexto::cerrar()
{
    architexto.close();
}
