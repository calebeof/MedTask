#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include<QFileDialog>
#include <QComboBox>
#include "paciente.h"
#include "medico.h"
#include "atender.h"
#include "medicos.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Medico medico;
    Atender atender;
    Medicos lista_de_medicos;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void atualizarEstatisticas();

private slots:
    void on_btn_insert_clicked();

    void on_btn_NameSort_clicked();

    void on_btn_GradeSort_clicked();

    bool carregar();

    bool salvar();

    void on_selection_bar_activated(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void inserirPacienteNaTabela(Paciente Paciente, int row);
    void inserirMedicoNaTabela(Medico medico, int row);
};

#endif // MAINWINDOW_H
