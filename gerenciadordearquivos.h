#ifndef GERENCIADORDEARQUIVOS_H
#define GERENCIADORDEARQUIVOS_H

#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>
#include <QFileDialog>

#include "medicos.h"
#include "pacientes.h"

class GerenciadorDeArquivos
{
public:
    GerenciadorDeArquivos();
    bool salvarArquivo(QString &arquivo, Medicos &lista_de_medicos, Pacientes &lista_de_pacientes);
    bool carregarArquivo(QString &arquivo, Medicos &lista_de_medicos, Pacientes &lista_de_pacientes);
};

#endif // GERENCIADORDEARQUIVOS_H
