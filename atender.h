#ifndef ATENDER_H
#define ATENDER_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>
#include "paciente.h"

class Atender
{
private:
    QVector<Paciente> lista;
public:
    explicit Atender();
    void inserirPaciente(Paciente a);
    void ordenarPorNome();
    void ordenarPorPrioridade();
    int size();
};

#endif // ATENDER_H
