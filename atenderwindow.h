#ifndef ATENDERWINDOW_H
#define ATENDERWINDOW_H

#include <QDialog>
#include "medicos.h"
#include "pacientes.h"

#include <QMessageBox>

namespace Ui {
class AtenderWindow;
}

class AtenderWindow : public QDialog
{
    Q_OBJECT
    Medicos lista_de_medicos_importados;
    Pacientes lista_de_pacientes_importados;
    Paciente paciente_selecionado;
    Medico medico_selecionado;

public:
    explicit AtenderWindow(QWidget *parent = nullptr);
    ~AtenderWindow();
    void inserirMedicosNaTabela();
    void inserirPacientesNaTabela();

    Medicos getLista_de_medicos_importados() ;
    void setLista_de_medicos_importados(Medicos &value);

    Pacientes getLista_de_pacientes_importados() ;
    void setLista_de_pacientes_importados(Pacientes &value);

    Paciente getPaciente_selecionado() const;
    void setPaciente_selecionado(const Paciente &value);

    Medico getMedico_selecionado() const;
    void setMedico_selecionado(const Medico &value);

private slots:
    void on_tbl_paciente_cellDoubleClicked(int row, int column);

    void on_tbl_medico_cellDoubleClicked(int row, int column);

    void on_bt_atender_clicked();

private:
    Ui::AtenderWindow *ui;

};

#endif // ATENDERWINDOW_H
