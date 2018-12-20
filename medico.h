#ifndef MEDICO_H
#define MEDICO_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>

#include "paciente.h"

class Medico
{
private:
    QVector<Paciente> atendidos;
    QString nome;

public:
    Medico();
    void inserirPaciente(const Paciente a);
    float mediaDaTurma();
    float maiorNota();
    float menorNota();
    void ordenarPorPrioridade();
    void ordenarPorMedia();
    void ordenarPorNome();
    int size();

    Paciente operator[](int i);

    QString getNome() const;
    void setNome(const QString &value);

};

#endif // MEDICO_H
