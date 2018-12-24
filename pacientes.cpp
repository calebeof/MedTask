#include "pacientes.h"

Pacientes::Pacientes()
{

}

void Pacientes::inserirPaciente(Paciente a){
    lista.push_back(a);
}

void Pacientes::ordenarPorPrioridade(){
    ordenarPorNome();
    std::stable_sort(lista.begin(),lista.end(),[](Paciente a, Paciente b){return a.getPrioridade()<b.getPrioridade();});
}

void Pacientes::ordenarPorNome(){
    std::stable_sort(lista.begin(),lista.end(),[](Paciente a, Paciente b){return a.getNome()<b.getNome();});
}

int Pacientes::size(){
    return lista.size();
}

void Pacientes::clear()
{
    lista.clear();
}

int Pacientes::find(QString nome)
{
    for(int i=0; i<lista.size(); i++)
        if(lista[i].getNome() == nome)
            return i;
    return -1;
}

void Pacientes::erase(int index)
{
    lista.erase(lista.begin()+index);
}

Paciente Pacientes::operator[](int i)
{
    return lista[i];
}

void Pacientes::editarNome(int index, QString value)
{
    lista[index].setNome(value);
}

void Pacientes::editarPatologia(int index, QString value)
{
    lista[index].setPatologia(value);
}

void Pacientes::editarPrioridade(int index, QString value)
{
    if(value=="Alta")
        lista[index].setPrioridade(0);
    else if (value=="Média")
        lista[index].setPrioridade(1);
    else
        lista[index].setPrioridade(2);
}
