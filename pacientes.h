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
    QVector<Paciente> atendidos;
public:
    explicit Pacientes();
    void inserirPaciente(Paciente a);
    void inserirPacienteAtendido(Paciente a);
    void ordenarPorNome();
    void ordenarPorPrioridade();
    int size();
    void clear();
    int find(QString nome);
    int find(QString nome, QString patologia);
    void erase(int index);
    Paciente operator[] (int i);
    void editarNome(int index, QString value);
    void editarPatologia(int index, QString value);
    void editarPrioridade(int index, QString value);
};

#endif // PACIENTES_H
