#include "paciente.h"

Paciente::Paciente()
{

}

QString Paciente::getNome() const
{
    return nome;
}

void Paciente::setNome(const QString &value)
{
    nome = value;
}

int Paciente::getPrioridade() const
{
    return prioridade;
}

void Paciente::setPrioridade(int value)
{
    prioridade = value;
}
