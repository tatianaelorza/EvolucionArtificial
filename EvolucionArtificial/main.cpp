#include <QApplication>
#include <iostream>
#include <string>
#include <graficador.h>
#include <mundo.h>
#include <constantes.h>
#include <Archivo.h>
#include <archivoBinario.h>
#include <archivoTexto.h>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Graficador graficador;
    graficador.resize(1000, 1000);
    graficador.show();

    a.exec();


    return a.exec();
}
/*
/////////////////////////////////////////////////////////////////////////////////////////////////////////
PRUEBA COMIDA
Comida comida;
comida.agregar(3,3,5);
cout<<comida.cantidad(3,3)<<endl;
comida.agregar(3,3,500);
cout<<comida.cantidad(3,3)<<endl;
comida.agregar(3,30,5);
cout<<comida.cantidad(3,30)<<endl;
int devuelve=comida.quitar(3,3,100);
cout<<comida.cantidad(3,3)<<endl;
cout<<"cantidad que devuelve "<<devuelve<<endl;
devuelve=comida.quitar(3,3,150);
cout<<comida.cantidad(3,3)<<endl;
cout<<"cantidad que devuelve "<<devuelve<<endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
PRUEBA SEMBRADOR

INDICAR POR PANTALLA LA POSICION DE 3 SEMBRADORES
Sembrador sembrador1, sembrador2, sembrador3;

cout<<"Posicion sembrador 1: "<<sembrador1.getFila()<<" "<<sembrador1.getColumna()<<endl;
cout<<"Posicion sembrador 2: "<<sembrador1.getFila()<<" "<<sembrador2.getColumna()<<endl;
cout<<"Posicion sembrador 3: "<<sembrador1.getFila()<<" "<<sembrador3.getColumna()<<endl;


SALIDA POR CONSOLA DE COORDENADAS EN 100 MOVIMIENTOS
for (int i=0 ; i<20 ; i++)
{
    sembrador1.mover();
    //sembrador2.mover();
    //sembrador3.mover();
    cout<<"Ubicacion del sembrador 1: "<<sembrador1.getFila()<<" "<<sembrador1.getColumna()<<endl;
    //cout<<"Ubicacion del sembrador 2: "<<sembrador2.getFila()<<" "<<sembrador2.getColumna()<<endl;
    //cout<<"Ubicacion del sembrador 3: "<<sembrador3.getFila()<<" "<<sembrador3.getColumna()<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
PRUEBA ARCHIVOS
    int respuesta;
    string nombre;
    cout<<"Desea guardar la informacion en un archivo de texto (1) a o binario(2)"<<endl;
    cin>>respuesta;
    cout<<"Nombre del archivo: "<<endl;
    if(respuesta==1)
    {
        cin>>nombre;
        nombre=nombre+".txt";
        cout<<nombre<<endl;
        ArchivoTexto archivotexto(nombre);
        archivotexto.grabar (mundo);
        cout<<archivotexto.leer();
        archivotexto.cerrar();
    }else
    {
        cin>>nombre;
        nombre=nombre+".dat";
        cout<<nombre<<endl;
        ArchivoBinario archivobinario(nombre);
        archivobinario.grabar(mundo);
        cout<<archivobinario.leer();
        archivobinario.cerrar();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////
PRUEBA VIVIR
PRUEBA MAS VIVIO MENOS VIVIO
Mundo mundo;
for(int i=0;i<30;i++)
    {
       cout<<"epoca "<<mundo.getEpoca()<<endl;
        mundo.vivir();
        mundo.salidaPorConsola();
    }
    cout<<"El MO con ID: "<<mundo.MOmasVivio()<<" fue el que MAS vivio, con un total de "<<mundo.getEdadMOs(mundo.MOmasVivio())<<" epocas"<<endl;
    cout<<"El MO con ID: "<<mundo.MOmenosVivio()<<" fue el que MENOS vivio, con un total de "<<mundo.getEdadMOs(mundo.MOmenosVivio())<<" epocas"<<endl;
*/
