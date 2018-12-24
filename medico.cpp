#include "medico.h"



QString Medico::getNome() const
{
    return nome;
}

void Medico::setNome(const QString &value)
{
    nome = value;
}


QString Medico::getEspecialidade() const
{
    return especialidade;
}

void Medico::setEspecialidade(QString &value)
{
    value[0] = value[0].toUpper();
    for(int i=1; i<value.size(); i++){
        if(value[i].isUpper())
            value[i] = value[i].toLower();
    }
    especialidade = value;
}


Medico::Medico()
{

}

void Medico::inserirPaciente(const Paciente a)
{
    atendidos.push_back(a);
}


void Medico::ordenarPorNome()
{
    std::sort(atendidos.begin(), atendidos.end(), [](Paciente a, Paciente b){return a.getNome()<b.getNome();});
}

void Medico::ordenarPorPrioridade()
{
    ordenarPorNome();
    std::stable_sort(atendidos.begin(),atendidos.end(),[](Paciente a, Paciente b){return a.getPrioridade()<b.getPrioridade();});
}

int Medico::size()
{
    return atendidos.size();
}

void Medico::inserirPacienteAtendido(Paciente a)
{
    atendidos.push_back(a);
}

Paciente Medico::operator[](int i)
{
    return atendidos[i];
}

QVector<Paciente> Medico::getAtendidos()
{
    return atendidos;
}
