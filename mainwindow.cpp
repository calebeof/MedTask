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
    Medico aux_mais = lista_de_medicos.maisPacientes(), aux_menos = lista_de_medicos.menosPacientes();
    double media = lista_de_medicos.mediaPacientes();
    ui->lbl_avg->setText(QString::number(media,'f',2));
    ui->lbl_highest->setText(aux_mais.getNome()+" (" + QString::number(aux_mais.getAtendidos().size(),'f',2)+")");
    ui->lbl_lowest->setText(aux_menos.getNome()+" ("+QString::number(aux_menos.getAtendidos().size(),'f',2)+")");

}

void MainWindow::inserirPacienteNaTabela(Paciente paciente, int row, int op)
{
    if(op==0){
        ui->tbl_paciente->setItem(row,0,new QTableWidgetItem(paciente.getNome()));
        switch(paciente.getPrioridade()){
            case 0: ui->tbl_paciente->setItem(row,1,new QTableWidgetItem("Alta"));
            break;
            case 1: ui->tbl_paciente->setItem(row,1,new QTableWidgetItem("Média"));
            break;
            case 2: ui->tbl_paciente->setItem(row,1,new QTableWidgetItem("Baixa"));
        }
        ui->tbl_paciente->setItem(row,2,new QTableWidgetItem(paciente.getPatologia()));
    }else{
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(paciente.getNome()));
        switch(paciente.getPrioridade()){
            case 0: ui->tableWidget->setItem(row,1,new QTableWidgetItem("Alta"));
            break;
            case 1: ui->tableWidget->setItem(row,1,new QTableWidgetItem("Média"));
            break;
            case 2: ui->tableWidget->setItem(row,1,new QTableWidgetItem("Baixa"));
        }
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(paciente.getPatologia()));
    }

}

void MainWindow::inserirMedicoNaTabela(Medico medico, int row, int op){
    ui->tbl_medico->setItem(row,0,new QTableWidgetItem(medico.getNome()));
    ui->tbl_medico->setItem(row,1,new QTableWidgetItem(medico.getEspecialidade()));
}
void MainWindow::carregar()
{
    qDebug() << "carregar\n";
    QString nome = QFileDialog::getOpenFileName(this, "Lista de Usuarios", "", "(*.txt)");

    if(arquivos.carregarArquivo(nome, lista_de_medicos, lista_de_pacientes)){
        for (int i=0; i<lista_de_medicos.size(); i++){
            int qnt_row = ui->tbl_medico->rowCount();
            ui->tbl_medico->insertRow(qnt_row);
            inserirMedicoNaTabela(lista_de_medicos[i], qnt_row++, 0);
            ui->comboMed->addItem(lista_de_medicos[i].getNome());
        }
        for(int i=0; i<lista_de_pacientes.size(); i++){
            int qnt_row = ui->tbl_paciente->rowCount();
            ui->tbl_paciente->insertRow(qnt_row);
            inserirPacienteNaTabela(lista_de_pacientes[i], qnt_row++, 0);
            ui->comboPac->addItem(lista_de_pacientes[i].getNome());
        }
    }else
        QMessageBox::information(this, "Carregar dados","Não foi possível carregar os dados, tente novamente.");
   atualizarEstatisticas();
}

void MainWindow::salvar()
{
    qDebug() << "salvar\n";
    QString nome = QFileDialog::getSaveFileName(this, "Lista de Usuarios", "", "(*.txt)");
    if(arquivos.salvarArquivo(nome, lista_de_medicos, lista_de_pacientes))
        QMessageBox::information(this, "Salvar dados","Dados salvos com sucesso!");
    else
        QMessageBox::information(this, "Salvar dados","Não foi possível salvar os dados, tente novamente.");
}

void MainWindow::on_btn_insert_clicked()
{

    if(ui->le_nameInput->text().size() != 0){
        QString aux_nome = ui->le_nameInput->text();
        QString aux_prioridade = ui->selection_bar2->currentText();
        QString aux_patologia = ui->le_pat->text();
        QString msg = ui->selection_bar->currentText();
        if(msg == "Paciente"){
            qDebug() << "Paciente selecionado!" << endl;
            Paciente paciente;
            paciente.setNome(aux_nome);
            int qnt_row = ui->tbl_paciente->rowCount();
            if(aux_prioridade=="Selecione a prioridade..."){
                QMessageBox::warning(this, tr("AVISO"), tr("Insira a prioridade do paciente."));
                return;
            }
            if(aux_patologia.isEmpty()){
                QMessageBox::warning(this, tr("AVISO"), tr("Insira a patologia do paciente."));
                return;
            }
            paciente.setPatologia(aux_patologia);
            if(aux_prioridade=="Prioridade alta")
                paciente.setPrioridade(0);
            else if (aux_prioridade=="Prioridade média")
                paciente.setPrioridade(1);
            else
                paciente.setPrioridade(2);
            ui->tbl_paciente->insertRow(qnt_row);
            ui->le_nameInput->clear();
            lista_de_pacientes.inserirPaciente(paciente);
            ui->comboPac->addItem(paciente.getNome());
            ui->le_pat->clear();
            inserirPacienteNaTabela(paciente, qnt_row, 0);
        }
        else if (msg=="Médico"){
            qDebug() << "Médico selecionado!" << endl;
            Medico medico;
            int qnt_row = ui->tbl_medico->rowCount();
            QString aux_esp = ui->le_esp->text();
            if(aux_esp.isEmpty()){
                QMessageBox::warning(this, tr("AVISO"), tr("Insira a especialização do médico."));
                return;
            }
            medico.setNome(aux_nome);
            medico.setEspecialidade(aux_esp);
            lista_de_medicos.inserirMedico(medico);
            ui->tbl_medico->insertRow(qnt_row);
            ui->le_nameInput->clear();
            ui->le_esp->clear();
            ui->comboMed->addItem(medico.getNome());
            inserirMedicoNaTabela(medico, qnt_row, 0);
        }
        else{
            QMessageBox::warning(this, tr("AVISO"), tr("Insira um tipo de usuário."));
            qDebug() << "Nenhum selecionado!" << endl;
        }
        atualizarEstatisticas();
    }
}

void MainWindow::on_btn_NameSort_clicked()
{
    ui->tbl_medico->clearContents();
    ui->tbl_paciente->clearContents();
    lista_de_medicos.ordenarPorNome();
    lista_de_pacientes.ordenarPorNome();
    for(int i = 0; i<lista_de_medicos.size(); i++)
        inserirMedicoNaTabela(lista_de_medicos[i], i, 0);
    for(int i = 0; i<lista_de_pacientes.size(); i++)
        inserirPacienteNaTabela(lista_de_pacientes[i], i, 0);
}

void MainWindow::on_btn_GradeSort_clicked()
{
    ui->tbl_paciente->clearContents();
    lista_de_pacientes.ordenarPorPrioridade();
    int k = 0;
    for(int i = 0; i<lista_de_pacientes.size(); i++)
        inserirPacienteNaTabela(lista_de_pacientes[i], k++, 0);
}

void MainWindow::on_selection_bar_activated(const QString &arg1)
{
    qDebug() << arg1;
    if(arg1=="Paciente"){
        ui->selection_bar2->setEnabled(1);
        ui->le_pat->setEnabled(1);
        ui->lb_pat->setEnabled(1);
        ui->le_esp->setEnabled(0);
        ui->lb_esp->setEnabled(0);
    }
    else{
        ui->selection_bar2->setEnabled(0);
        ui->le_pat->setEnabled(0);
        ui->lb_pat->setEnabled(0);
        ui->le_esp->setEnabled(1);
        ui->lb_esp->setEnabled(1);
    }
}

void MainWindow::on_clearButton_clicked()
{
    qDebug() << "limpei\n";
    ui->tbl_medico->setRowCount(0);
    ui->tbl_medico->clearContents();
    ui->tbl_paciente->setRowCount(0);
    ui->tbl_paciente->clearContents();
    lista_de_medicos.clear();
    lista_de_pacientes.clear();
}

void MainWindow::on_tbl_paciente_cellDoubleClicked(int row, int column)
{
    if(column==0){
        bool ok;
        QString nome = QInputDialog::getText(this, "Editar nome", "Escreva o novo nome do médico", QLineEdit::Normal,"", &ok);
        if(ok && !nome.isEmpty())
            lista_de_pacientes.editarNome(row, nome);
    }
    else if(column==1){
        bool ok;
        QStringList itens;
        itens << "Média" << "Baixa" << "Alta";
        QString nome = QInputDialog::getItem(this, "Editar prioridade", "Escolha a nova prioridade do paciente", itens,0, true, &ok);
        if(ok && !nome.isEmpty())
            lista_de_pacientes.editarPrioridade(row, nome);
    }else{
        bool ok;
        QString patologia = QInputDialog::getText(this, "Editar patologia", "Escreva a nova patologia do paciente", QLineEdit::Normal,"", &ok);
        if(ok && !patologia.isEmpty())
            lista_de_pacientes.editarPatologia(row, patologia);
    }
    inserirPacienteNaTabela(lista_de_pacientes[row], row, 0);
}

void MainWindow::on_tbl_medico_cellDoubleClicked(int row, int column)
{
    if(column==0){
        bool ok;
        QString nome = QInputDialog::getText(this, "Editar nome", "Escreva o novo nome do médico", QLineEdit::Normal,"", &ok);
        if(ok && !nome.isEmpty())
            lista_de_medicos.editarNome(row, nome);
    }
    else{
        bool ok;
        QString nome = QInputDialog::getText(this, "Editar especialização", "Escolha a nova especialização do médico", QLineEdit::Normal, "", &ok);
        if(ok && !nome.isEmpty())
            lista_de_medicos.editarEspecialidade(row, nome);
    }
    inserirMedicoNaTabela(lista_de_medicos[row], row, 0);
}


void MainWindow::on_bt_atender_clicked()
{
    AtenderWindow atender;
    atender.setModal(true);
    atender.setLista_de_medicos_importados(lista_de_medicos);
    atender.setLista_de_pacientes_importados(lista_de_pacientes);
    atender.inserirMedicosNaTabela();
    atender.inserirPacientesNaTabela();
    atender.exec();
    lista_de_medicos = atender.getLista_de_medicos_importados();
    lista_de_pacientes = atender.getLista_de_pacientes_importados();
    ui->tbl_paciente->clearContents();
    ui->tbl_paciente->setRowCount(0);
    ui->tbl_medico->clearContents();
    ui->tbl_medico->setRowCount(0);
    for(int i=0; i<lista_de_pacientes.size(); i++){
        ui->tbl_paciente->insertRow(i);
        inserirPacienteNaTabela(lista_de_pacientes[i], i, 0);
    }
    for(int i=0; i<lista_de_medicos.size(); i++){
        ui->tbl_medico->insertRow(i);
        inserirMedicoNaTabela(lista_de_medicos[i], i, 0);
    }
    atualizarEstatisticas();
}

void MainWindow::on_bt_disponibilizar_clicked()
{
    DisponibilizarWindow disponibilizar;
    disponibilizar.setModal(true);
    disponibilizar.setLista_de_medicos_importados(lista_de_medicos);
    disponibilizar.inserirMedicosNaTabela();
    disponibilizar.exec();
    lista_de_medicos = disponibilizar.getLista_de_medicos_importados();
    ui->tbl_medico->clearContents();
    ui->tbl_medico->setRowCount(0);
    for(int i=0; i<lista_de_medicos.size(); i++){
        ui->tbl_medico->insertRow(i);
        inserirMedicoNaTabela(lista_de_medicos[i], i, 0);
    }
    atualizarEstatisticas();
}

void MainWindow::on_comboMed_activated(const QString &arg1)
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    if(arg1!="Selecione um médico..."){
        Medico aux_med;
        QVector<Paciente> aux;
        if(lista_de_medicos.find(arg1)!=-1){
            aux_med = lista_de_medicos[lista_de_medicos.find(arg1)];
            aux =  aux_med.getAtendidos();
        }else{
            aux_med = lista_de_medicos.findMedicoIndisponivel(arg1);
            aux = aux_med.getAtendidos();
        }
        for(int i=0; i<aux.size(); i++){
            ui->tableWidget->insertRow(i);
            inserirPacienteNaTabela(aux[i], i, 1);
        }
    }
}

