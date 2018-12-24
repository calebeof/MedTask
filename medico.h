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
    QString especialidade;
public:
    Medico();
    void inserirPaciente(const Paciente a);
    void ordenarPorPrioridade();
    void ordenarPorMedia();
    void ordenarPorNome();
    int size();
    void inserirPacienteAtendido(Paciente a);
    Paciente operator[](int i);
    QVector<Paciente> getAtendidos();
    QString getNome() const;
    void setNome(const QString &value);

    QString getEspecialidade() const;
    void setEspecialidade(QString &value);
};

#endif // MEDICO_H
