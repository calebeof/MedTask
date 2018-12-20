#include "atender.h"

Atender::Atender()
{

}

void Atender::inserirPaciente(Paciente a){
    lista.push_back(a);
}

void Atender::ordenarPorPrioridade(){
    ordenarPorNome();
    std::stable_sort(lista.begin(),lista.end(),[](Paciente a, Paciente b){return a.getPrioridade()<b.getPrioridade();});
}

void Atender::ordenarPorNome(){
    std::stable_sort(lista.begin(),lista.end(),[](Paciente a, Paciente b){return a.getNome()<b.getNome();});
}

int Atender::size(){
    return lista.size();
}

Paciente Atender::operator[](int i)
{
    return lista[i];
}
