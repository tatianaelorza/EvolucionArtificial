#ifndef ARCHIVOTEXTO_H
#define ARCHIVOTEXTO_H

#include <mundo.h>
#include <string.h>
#include <fstream>

class ArchivoTexto{
private:
    fstream architexto;
public:
    ArchivoTexto(string nombre);


    void grabar (Mundo &mundo0);
    string leer();
    void cerrar();

};

#endif // ARCHIVOTEXTO_H
