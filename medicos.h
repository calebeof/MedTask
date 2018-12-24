#ifndef MEDICOS_H
#define MEDICOS_H

#include "medico.h"
#include <QVector>

class Medicos
{
private:
    QVector<Medico> lista;
    QVector<Medico> indisponiveis;
public:
    Medicos();
    void inserirMedico(Medico a);
    void inserirMedicoIndisponivel(Medico a);
    void ordenarPorNome();
    Medico maisPacientes();
    Medico menosPacientes();
    double mediaPacientes();
    int size();
    void clear();
    int find(QString nome);
    Medico findMedicoIndisponivel(QString nome);
    void erase(int index);
    void eraseMedicoIndisponivel(int index);
    Medico operator[] (int i);
    QVector<Medico> getIndisponiveis();
    void editarNome(int index, QString value);
    void editarEspecialidade(int index, QString value);
    void editarDisponibilidade(int index, bool value);
};

#endif // MEDICOS_H
