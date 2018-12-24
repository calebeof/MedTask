#include "medicos.h"
#include "paciente.h"
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

void Medicos::inserirMedicoIndisponivel(Medico a)
{
    indisponiveis.push_back(a);
}

void Medicos::ordenarPorNome()
{
    stable_sort(lista.begin(), lista.end(), comp);
}

Medico Medicos::maisPacientes()
{
    int max = -1;
    Medico aux;
    for(int i=0; i<lista.size();i++){
        if(lista[i].getAtendidos().size()>max){
            max = lista[i].getAtendidos().size();
            aux = lista[i];
        }
    }
    for(int i=0; i<indisponiveis.size(); i++){
        if(indisponiveis[i].getAtendidos().size()>max){
            max = indisponiveis[i].getAtendidos().size();
            aux = indisponiveis[i];
        }
    }
    return aux;
}

Medico Medicos::menosPacientes()
{
    int min = INT_MAX;
    Medico aux;
    for(int i=0; i<lista.size();i++){
        if(lista[i].getAtendidos().size()<min){
            min = lista[i].getAtendidos().size();
            aux = lista[i];
        }
    }
    for(int i=0; i<indisponiveis.size(); i++){
        if(indisponiveis[i].getAtendidos().size()<min){
            min = indisponiveis[i].getAtendidos().size();
            aux = indisponiveis[i];
        }
    }
    return aux;
}

double Medicos::mediaPacientes()
{
    int qtde_med = lista.size()+indisponiveis.size();
    int qtde_pacientes = 0;
    Medico aux;
    for(int i=0; i<lista.size();i++)
        qtde_pacientes+=lista[i].getAtendidos().size();
    for(int i=0; i<indisponiveis.size(); i++)
        qtde_pacientes+=indisponiveis[i].getAtendidos().size();
    if(qtde_med==0)
        return 0;
    return (double)qtde_pacientes/qtde_med;
}

int Medicos::size()
{
    return lista.size();
}

void Medicos::clear()
{
    lista.clear();
}

Medico Medicos::operator[](int i)
{
    return lista[i];
}

QVector<Medico> Medicos::getIndisponiveis()
{
    return indisponiveis;
}

void Medicos::editarNome(int index, QString value)
{
    lista[index].setNome(value);
}

void Medicos::editarEspecialidade(int index, QString value)
{
    lista[index].setEspecialidade(value);
}

int Medicos::find(QString nome){
    for(int i=0; i<lista.size(); i++){
        if(lista[i].getNome()==nome)
            return i;
    }
    return -1;
}

int Medicos::find(QString nome, QString especialidade)
{
    for(int i=0; i<lista.size(); i++){
        if(lista[i].getNome() == nome && lista[i].getEspecialidade() == especialidade)
            return i;
    }
    for(int i=0; i<indisponiveis.size(); i++){
        if(indisponiveis[i].getNome() == nome && indisponiveis[i].getEspecialidade() == especialidade)
            return i;
    }
    return -1;
}

Medico Medicos::findMedicoIndisponivel(QString nome)
{
    for(int i=0; i<indisponiveis.size(); i++){
        if(indisponiveis[i].getNome()==nome)
            return indisponiveis[i];
    }
}

void Medicos::erase(int index)
{
    lista.erase(lista.begin()+index);
}

void Medicos::eraseMedicoIndisponivel(int index)
{
    indisponiveis.erase(indisponiveis.begin()+index);
}
