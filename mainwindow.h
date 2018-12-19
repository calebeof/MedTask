#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include<QFileDialog>
#include "paciente.h"
#include "medico.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Medico medico;

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

private:
    Ui::MainWindow *ui;
    void inserirPacienteNaTabela(Paciente Paciente, int row);

};

#endif // MAINWINDOW_H
