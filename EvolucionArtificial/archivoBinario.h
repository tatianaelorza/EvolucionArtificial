#ifndef ARCHIVOBINARIO_H
#define ARCHIVOBINARIO_H

#include <mundo.h>
#include <string.h>
#include <fstream>

class ArchivoBinario{
private:
    fstream archibin;
public:
    ArchivoBinario(string nombre);


    void grabar(Mundo &mundo0);
    string leer();
    void cerrar();

};

#endif // ARCHIVOBINARIO_H
