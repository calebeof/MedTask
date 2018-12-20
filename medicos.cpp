#include "medicos.h"
#include <algorithm>
using namespace std;

Medicos::Medicos()
{

}
bool comp(Medico a, Medico b){
    return a.getNome()<b.getNome();
}
void Medicos::inserirMedico(Medico a)
{
    lista.push_back(a);
}

void Medicos::ordenarPorNome()
{
    stable_sort(lista.begin(), lista.end(), comp);
}

int Medicos::size()
{
    return lista.size();
}

Medico Medicos::operator[](int i)
{
    return lista[i];
}
