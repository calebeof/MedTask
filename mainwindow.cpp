#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionSalvar, SIGNAL(triggered()), this, SLOT(salvar()));
    connect(ui->actionCarregar, SIGNAL(triggered()), this, SLOT(carregar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualizarEstatisticas()
{
    //ui->lbl_highest->setText(QString::number(medico.maiorNota(),'f',2));
    //ui->lbl_lowest->setText(QString::number(medico.menorNota(),'f',2));

    //ui->lbl_avg->setStyleSheet("color: "+color);

}

void MainWindow::inserirPacienteNaTabela(Paciente paciente, int row)
{
    ui->tbl_data->setItem(row,0,new QTableWidgetItem(paciente.getNome()));
    switch(paciente.getPrioridade()){
        case 0: ui->tbl_data->setItem(row,1,new QTableWidgetItem("Alta"));
        break;
        case 1: ui->tbl_data->setItem(row,1,new QTableWidgetItem("Média"));
        break;
        case 2: ui->tbl_data->setItem(row,1,new QTableWidgetItem("Baixa"));
    }
    ui->tbl_data->setItem(row,2,new QTableWidgetItem("Paciente"));
}

void MainWindow::inserirMedicoNaTabela(Medico medico, int row){
    ui->tbl_data->setItem(row,0,new QTableWidgetItem(medico.getNome()));
    ui->tbl_data->setItem(row,1,new QTableWidgetItem("--"));
    ui->tbl_data->setItem(row,2,new QTableWidgetItem("Médico"));
}
bool MainWindow::carregar()
{
    qDebug() << "carregar\n";
    QString nome = QFileDialog::getOpenFileName(this, "Lista de Notas", "", "(*.txt)");
    QFile file(nome);
    if(!file.open(QIODevice::ReadOnly))
        return false;
    QTextStream in(&file);
    QString aux;
    int row = 0;
    while(in.readLineInto(&aux)){
        QString nome;
        Paciente auxiliar;
        int i=0;
        qDebug() << aux << "\n";
        while(aux[i]!=',')
            nome+=aux[i++];
        qDebug() << nome << "\n";
        auxiliar.setNome(nome);
        int qnt_row = ui->tbl_data->rowCount();
        ui->tbl_data->insertRow(qnt_row);
        inserirPacienteNaTabela(auxiliar, row++);
    }

    file.close();
    return true;
}

bool MainWindow::salvar()
{
    qDebug() << "salvar\n";
    QString nome = QFileDialog::getSaveFileName(this, "Lista de Notas", "", "(*.txt)");
    QFile file(nome);
    if(!file.open(QIODevice::WriteOnly))
        return false;
    QTextStream out(&file);
    for (int i=0; i<medico.size(); i++)
        out << medico[i].getNome()<< "\n";
    file.close();
    return true;
}

void MainWindow::on_btn_insert_clicked()
{

    if(ui->le_nameInput->text().size() != 0){
        QString aux_nome = ui->le_nameInput->text();
        QString aux_prioridade = ui->selection_bar2->currentText();
        int qnt_row = ui->tbl_data->rowCount();
        QString msg = ui->selection_bar->currentText();
        if(msg == "Paciente"){
            qDebug() << "Paciente selecionado!" << endl;
            Paciente paciente;
            paciente.setNome(aux_nome);
            if(aux_prioridade=="Selecione a prioridade..."){
                QMessageBox::warning(this, tr("AVISO"), tr("Insira uma prioridade."));
                return;
            }
            else if(aux_prioridade=="Prioridade alta")
                paciente.setPrioridade(0);
            else if (aux_prioridade=="Prioridade média")
                paciente.setPrioridade(1);
            else
                paciente.setPrioridade(2);
            ui->tbl_data->insertRow(qnt_row);
            ui->le_nameInput->clear();
            atender.inserirPaciente(paciente);
            ui->comboPac->addItem(paciente.getNome());
            inserirPacienteNaTabela(paciente, qnt_row);
        }
        else if (msg=="Médico"){
            qDebug() << "Médico selecionado!" << endl;
            Medico medico;
            medico.setNome(aux_nome);
            lista_de_medicos.inserirMedico(medico);
            ui->tbl_data->insertRow(qnt_row);
            ui->le_nameInput->clear();
            ui->comboMed->addItem(medico.getNome());
            inserirMedicoNaTabela(medico, qnt_row);
        }
        else{
            qDebug() << "Nenhum selecionado!" << endl;
        }
        atualizarEstatisticas();
    }
}

void MainWindow::on_btn_NameSort_clicked()
{
    ui->tbl_data->clearContents();

    lista_de_medicos.ordenarPorNome();
    atender.ordenarPorNome();
    for(int i = 0; i<lista_de_medicos.size(); i++){
        inserirMedicoNaTabela(lista_de_medicos[i], i);
    }
}

void MainWindow::on_btn_GradeSort_clicked()
{
    ui->tbl_data->clearContents();
    atender.ordenarPorPrioridade();
    for(int i = 0; i<atender.size();i++){
        inserirPacienteNaTabela(atender[i],i);
    }
}

void MainWindow::on_selection_bar_activated(const QString &arg1)
{
    qDebug() << arg1;
    if(arg1=="Paciente")
        ui->selection_bar2->setEnabled(1);
    else
        ui->selection_bar2->setEnabled(0);
}
