#include "atenderwindow.h"
#include "ui_atenderwindow.h"

Medicos AtenderWindow::getLista_de_medicos_importados()
{
    return lista_de_medicos_importados;
}

void AtenderWindow::setLista_de_medicos_importados(Medicos &value)
{
    lista_de_medicos_importados = value;
}

Pacientes AtenderWindow::getLista_de_pacientes_importados()
{
    return lista_de_pacientes_importados;
}

void AtenderWindow::setLista_de_pacientes_importados(Pacientes &value)
{
    lista_de_pacientes_importados = value;
}

Paciente AtenderWindow::getPaciente_selecionado() const
{
    return paciente_selecionado;
}

void AtenderWindow::setPaciente_selecionado(const Paciente &value)
{
    paciente_selecionado = value;
}

Medico AtenderWindow::getMedico_selecionado() const
{
    return medico_selecionado;
}

void AtenderWindow::setMedico_selecionado(const Medico &value)
{
    medico_selecionado = value;
}

AtenderWindow::AtenderWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AtenderWindow)
{
    ui->setupUi(this);
}

AtenderWindow::~AtenderWindow()
{
    delete ui;
}


void AtenderWindow::inserirMedicosNaTabela()
{
    for(int i=0; i<lista_de_medicos_importados.size(); i++){
        ui->tbl_medico->insertRow(i);
        ui->tbl_medico->setItem(i,0,new QTableWidgetItem(lista_de_medicos_importados[i].getNome()));
        ui->tbl_medico->setItem(i,1,new QTableWidgetItem(lista_de_medicos_importados[i].getEspecialidade()));
    }
}

void AtenderWindow::inserirPacientesNaTabela()
{
    for(int i=0; i<lista_de_pacientes_importados.size(); i++){
        ui->tbl_paciente->insertRow(i);
        ui->tbl_paciente->setItem(i,0,new QTableWidgetItem(lista_de_pacientes_importados[i].getNome()));
        switch(lista_de_pacientes_importados[i].getPrioridade()){
            case 0: ui->tbl_paciente->setItem(i,1,new QTableWidgetItem("Alta"));
            break;
            case 1: ui->tbl_paciente->setItem(i,1,new QTableWidgetItem("Média"));
            break;
            case 2: ui->tbl_paciente->setItem(i,1,new QTableWidgetItem("Baixa"));
        }
        ui->tbl_paciente->setItem(i,2,new QTableWidgetItem(lista_de_pacientes_importados[i].getPatologia()));
    }
}

void AtenderWindow::on_tbl_paciente_cellDoubleClicked(int row, int column)
{
    setPaciente_selecionado(lista_de_pacientes_importados[row]);
    ui->lb_paciente->setText("Paciente selecionado: " +getPaciente_selecionado().getNome());
}


void AtenderWindow::on_tbl_medico_cellDoubleClicked(int row, int column)
{
    setMedico_selecionado(lista_de_medicos_importados[row]);
    ui->lb_medico->setText("Médico selecionado: " +getMedico_selecionado().getNome());
}

void AtenderWindow::on_bt_atender_clicked()
{
    if(getPaciente_selecionado().getNome().isEmpty() && getMedico_selecionado().getNome().isEmpty()){
        QMessageBox::warning(this, tr("AVISO"), tr("Selecione um paciente e um médico."));
        return;
    }
    else if(getPaciente_selecionado().getNome().isEmpty()){
        QMessageBox::warning(this, tr("AVISO"), tr("Selecione um paciente a ser atendido."));
        return;
    }
    else if(getMedico_selecionado().getNome().isEmpty()){
        QMessageBox::warning(this, tr("AVISO"), tr("Selecione um médico para atender o paciente."));
        return;
    }
    int index_med = lista_de_medicos_importados.find(getMedico_selecionado().getNome());
    int index_pac = lista_de_pacientes_importados.find(getPaciente_selecionado().getNome());
    medico_selecionado.inserirPacienteAtendido(getPaciente_selecionado());
    lista_de_medicos_importados.inserirMedicoIndisponivel(getMedico_selecionado());
    lista_de_medicos_importados.erase(index_med);
    lista_de_pacientes_importados.inserirPacienteAtendido(lista_de_pacientes_importados[index_pac]);
    lista_de_pacientes_importados.erase(index_pac);
    QMessageBox::information(this, tr("SUCESSO"), tr("Paciente sendo atendido!"));
    this->close();
}
