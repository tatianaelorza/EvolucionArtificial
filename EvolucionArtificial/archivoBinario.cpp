#include <iostream>
#include <fstream>
#include <archivoBinario.h>
#include <string.h>
#include <mundo.h>
#include <sstream>
using namespace std;

ArchivoBinario::ArchivoBinario(string nombre)
{
    archibin.open(nombre, ios::in|ios::out|ios::trunc|ios::binary);
}

void ArchivoBinario::grabar(Mundo &mundo0)
{
    if(!archibin.is_open())
    {
        cout<<"El archivo que desea leer no se puede abrir"<<endl;
    }
    else {
        int aux= mundo0.getEpoca();
        archibin.write((char*)&aux, sizeof(aux));

        aux= mundo0.getCantidadTotalComida();
        archibin.write((char*)&aux, sizeof(aux));

        for (int i=0; i<cantSembradores; i++)
        {
            int numeroSemb= i;
            archibin.write((char*)&numeroSemb, sizeof(i));

            int fila= mundo0.sembradoresFila(i);
            archibin.write((char*)&fila, sizeof(fila));

            int columna=mundo0.sembradoresColumna(i);
            archibin.write((char*)&columna, sizeof(columna));
        }
    }
}
string ArchivoBinario::leer()
{
    string contenido;

    archibin.seekg(0,ios::beg);

    if(!archibin.is_open())
    {
        contenido = "El archivo que desea leer no se puede abrir";
    }
    else {
        int epoca,comidaTotal,ID,fila,columna;
        ostringstream auxOstring;

        archibin.read((char*)&epoca, sizeof(int));
        auxOstring<<epoca;
        contenido= contenido+"Epoca: "+auxOstring.str()+"\n";
        auxOstring.str(" ");

        archibin.read((char*)&comidaTotal, sizeof(int));
        auxOstring<<comidaTotal;
        contenido= contenido+"Cantidad total de comida en el mundo: "+auxOstring.str()+"\n";
        auxOstring.str(" ");

        for (int i=0; i<cantSembradores; i++)
        {
            archibin.read((char*)&ID, sizeof(i));
            auxOstring<<ID;
            contenido= contenido+"ID: "+auxOstring.str();
            auxOstring.str(" ");
            archibin.read((char*)&fila, sizeof(fila));
            auxOstring<<fila;
            contenido= contenido+" Posicion: ("+auxOstring.str();
            auxOstring.str(" ");
            archibin.read((char*)&columna, sizeof(columna));
            auxOstring<<columna;
            contenido= contenido+","+auxOstring.str()+")"+"\n";
            auxOstring.str(" ");
        }
    }
    return contenido;
}
void ArchivoBinario::cerrar()
{
    archibin.close();
}

