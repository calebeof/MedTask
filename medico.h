#ifndef MEDICO_H
#define MEDICO_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>

#include "paciente.h"

class Medico : public QObject
{
    Q_OBJECT
private:
    QVector<Paciente> atendidos;
    QString nome;

public:
    explicit Medico(QObject *parent = nullptr);
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

signals:

public slots:
};

#endif // MEDICO_H
