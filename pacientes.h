#ifndef PACIENTES_H
#define PACIENTES_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>
#include "paciente.h"

class Pacientes
{
private:
    QVector<Paciente> lista;
public:
    explicit Pacientes();
    void inserirPaciente(Paciente a);
    void ordenarPorNome();
    void ordenarPorPrioridade();
    int size();
    void clear();
    int find(QString nome);
    void erase(int index);
    Paciente operator[] (int i);
    void editarNome(int index, QString value);
    void editarPatologia(int index, QString value);
    void editarPrioridade(int index, QString value);
};

#endif // PACIENTES_H
