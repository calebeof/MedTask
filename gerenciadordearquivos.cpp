#include "gerenciadordearquivos.h"


GerenciadorDeArquivos::GerenciadorDeArquivos()
{

}

bool GerenciadorDeArquivos::salvarArquivo(QString &arquivo, Medicos &lista_de_medicos, Pacientes &lista_de_pacientes)
{
    QFile file(arquivo);
    if(!file.open(QIODevice::WriteOnly))
        return false;
    QTextStream out(&file);
    for (int i=0; i<lista_de_medicos.size(); i++)
        out << lista_de_medicos[i].getNome() << ",Medico,"<<lista_de_medicos[i].getEspecialidade() << endl;
    for (int i=0; i<lista_de_pacientes.size(); i++)
        out << lista_de_pacientes[i].getNome() << ",Paciente," << lista_de_pacientes[i].getPrioridade() << "," <<lista_de_pacientes[i].getPatologia() << endl;
    file.close();
    return true;
}

bool GerenciadorDeArquivos::carregarArquivo(QString &arquivo, Medicos &lista_de_medicos, Pacientes &lista_de_pacientes)
{       qDebug() << "carregar\n";
        QFile file(arquivo);
        if(!file.open(QIODevice::ReadOnly))
            return false;
        QTextStream in(&file);
        QString line;
        while(in.readLineInto(&line)){
            QStringList data = line.split(",");
            if(data[1]=="Paciente"){
                Paciente aux;
                aux.setNome(data[0]);
                aux.setPrioridade(data[2].toInt());
                aux.setPatologia(data[3]);
                lista_de_pacientes.inserirPaciente(aux);
            }else{
                Medico aux;
                aux.setNome(data[0]);
                aux.setEspecialidade(data[2]);
                lista_de_medicos.inserirMedico(aux);
            }
        }
        file.close();
        return true;
}
