#include "paciente.h"

QString Paciente::getPatologia() const
{
    return patologia;
}

void Paciente::setPatologia(QString &value)
{
    value[0] = value[0].toUpper();
    for(int i=1; i<value.size(); i++){
        if(value[i].isUpper())
            value[i] = value[i].toLower();
    }
    patologia = value;
}

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
