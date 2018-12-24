#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include<QFileDialog>
#include <QInputDialog>
#include <QComboBox>
#include "paciente.h"
#include "medico.h"
#include "pacientes.h"
#include "medicos.h"
#include "gerenciadordearquivos.h"
#include "atenderwindow.h"
#include "disponibilizarwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Medico medico;
    Pacientes lista_de_pacientes;
    Medicos lista_de_medicos;
    GerenciadorDeArquivos arquivos;
    bool selecionado = false;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void atualizarEstatisticas();

private slots:
    void on_btn_insert_clicked();

    void on_btn_NameSort_clicked();

    void on_btn_GradeSort_clicked();

    void carregar();

    void salvar();

    void on_selection_bar_activated(const QString &arg1);

    void on_clearButton_clicked();
    void on_comboMed_activated(const QString &arg1);

    void on_tbl_paciente_cellDoubleClicked(int row, int column);

    void on_tbl_medico_cellDoubleClicked(int row, int column);

    void on_bt_atender_clicked();

    void on_bt_disponibilizar_clicked();

private:
    Ui::MainWindow *ui;
    void inserirPacienteNaTabela(Paciente Paciente, int row, int op);
    void inserirMedicoNaTabela(Medico medico, int row, int op);
};

#endif // MAINWINDOW_H
