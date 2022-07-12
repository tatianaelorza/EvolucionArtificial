#include <graficador.h>

Graficador::Graficador()
{
    cronometro= new QTimer(this);
    cronometro->start(100);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(update()));
}

void Graficador::graficarLimites()
{
    glColor3f (0.0 , 0.0 , 0.0);
    glBegin(GL_QUADS);
    glVertex2f(maximoColumnas+0.5 , maximoFilas+0.5 );
    glVertex2f(-0.5, maximoFilas+0.5);
    glVertex2f(-0.5 , -0.5);
    glVertex2f(maximoColumnas+0.5 ,-0.5);
    glEnd();

    glLineWidth(2);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(maximoColumnas+0.5, maximoFilas+0.5);
    glVertex2f(-0.5, maximoFilas+0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(maximoColumnas+0.5, -0.5);
    glEnd();
}

void Graficador::graficarCuadrado(int fila, int columna)
{

    glPushMatrix();
    {
        glTranslatef (fila, columna, 0);
        glBegin(GL_QUADS);
        glVertex2f(0.0, 0.0);
        glVertex2f(1.0, 0.0);
        glVertex2f(1.0, 1.0);
        glVertex2f(0.0, 1.0);

        glEnd();
    }
    glPopMatrix();
}

void Graficador::graficarComida (int fila, int columna)
{
    {
        glPushMatrix();
        {
            glTranslatef(0.25, 0.25, 0.0);
            glScalef(1.0/3.0, 1.0/3.0, 0.0);
            glColor3f(0.0,(float)mundo.getcantidadComida(fila,columna)/maximoEnComida, 1.0);
            fila= fila*3;
            columna= columna*3;
            graficarCuadrado(fila,columna);
        }
        glPopMatrix();
    }
}

void Graficador::graficarMundo()
{
    glPushMatrix();
    {
        glTranslatef((float)maximoFilas/6.0, (float)maximoColumnas/6.0, 0.0);
        glScalef(2.f/3.f, 2.f/3.f, 1.0);

        graficarLimites();

        for(unsigned int i=0;i<maximoFilas;i++)
            for(unsigned int j=0;j<maximoColumnas;j++)
                if(mundo.hayComida(i,j))
                    graficarComida(i,j);

        for(unsigned int m=0;m<cantidadMOs;m++)
        {
            glColor3f((float)mundo.getEnergiaMO(m)/energiaMaximaMO, 0.0, 0.0);
            graficarCuadrado(mundo.MOFila(m),mundo.MOColumna(m));
        }
        glColor3f(1.0,0.0, 1.0);
        for(unsigned int n=0;n<cantSembradores;n++)
        {

            graficarCuadrado(mundo.sembradoresFila(n),mundo.sembradoresColumna(n));
        }

    }
    glPopMatrix();
    mundo.vivir();
}

void Graficador::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0,0.0,0.0,0.0);
}

void Graficador::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0,0,width(),height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (maximoFilas>maximoColumnas)
    {
        glOrtho(0.0,maximoFilas,0.0,maximoFilas,-1.0,1.0);
    }
    else
    {
        glOrtho(0.0,maximoColumnas,0.0,maximoColumnas,-1.0,1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    graficarMundo();
}

Mundo *Graficador::getMundo()
{
    Mundo *puntero_mundo= &mundo;

    return puntero_mundo;
}
