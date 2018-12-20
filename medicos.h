#ifndef MEDICOS_H
#define MEDICOS_H

#include "medico.h"
#include <QVector>

class Medicos
{
private:
    QVector<Medico> lista;
public:
    Medicos();
    void inserirMedico(Medico a);
    void ordenarPorNome();
    int size();
    Medico operator[] (int i);
};

#endif // MEDICOS_H
