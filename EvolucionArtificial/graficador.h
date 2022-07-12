#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include <mundo.h>


#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>
#include <stdlib.h>


class Graficador : public QOpenGLWidget , protected QOpenGLFunctions
{
private:

    QTimer *cronometro;
    Mundo mundo;

    void graficarLimites();
    void graficarCuadrado( int fila, int columna);
    void graficarComida (int fila, int columna);
    void graficarMundo();

protected:

    virtual void initializeGL();
    virtual void paintGL();

public:

    Graficador();

    Mundo *getMundo();


};
#endif // GRAFICADOR_H
