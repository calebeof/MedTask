#include "disponibilizarwindow.h"
#include "ui_disponibilizarwindow.h"

DisponibilizarWindow::DisponibilizarWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisponibilizarWindow)
{

    ui->setupUi(this);
}

DisponibilizarWindow::~DisponibilizarWindow()
{
    delete ui;
}

Medicos DisponibilizarWindow::getLista_de_medicos_importados()
{
    return lista_de_medicos_importados;
}

void DisponibilizarWindow::setLista_de_medicos_importados(Medicos &value)
{
    lista_de_medicos_importados = value;
}

void DisponibilizarWindow::inserirMedicosNaTabela()
{
    QVector<Medico> aux = lista_de_medicos_importados.getIndisponiveis();
    for(int i=0; i<aux.size(); i++){
        ui->tbl_medicos->insertRow(i);
        ui->tbl_medicos->setItem(i,0,new QTableWidgetItem(aux[i].getNome()));
        ui->tbl_medicos->setItem(i,1,new QTableWidgetItem(aux[i].getEspecialidade()));
    }
}

void DisponibilizarWindow::on_tbl_medicos_cellDoubleClicked(int row, int column)
{
    lista_de_medicos_importados.inserirMedico(lista_de_medicos_importados.getIndisponiveis()[row]);
    lista_de_medicos_importados.eraseMedicoIndisponivel(row);
    ui->tbl_medicos->clearContents();
    ui->tbl_medicos->setRowCount(0);
    inserirMedicosNaTabela();
}
