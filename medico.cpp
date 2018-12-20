#include "medico.h"

QString Medico::getNome() const
{
    return nome;
}

void Medico::setNome(const QString &value)
{
    nome = value;
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

Paciente Medico::operator[](int i)
{
    return atendidos[i];
}
