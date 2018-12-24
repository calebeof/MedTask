#ifndef DISPONIBILIZARWINDOW_H
#define DISPONIBILIZARWINDOW_H

#include <QDialog>

#include "medicos.h"

namespace Ui {
class DisponibilizarWindow;
}

class DisponibilizarWindow : public QDialog
{
    Q_OBJECT
    Medicos lista_de_medicos_importados;
public:
    explicit DisponibilizarWindow(QWidget *parent = nullptr);
    ~DisponibilizarWindow();
    Medicos getLista_de_medicos_importados();
    void setLista_de_medicos_importados(Medicos &value);
    void inserirMedicosNaTabela();
private slots:
    void on_tbl_medicos_cellDoubleClicked(int row, int column);

private:
    Ui::DisponibilizarWindow *ui;

};

#endif // DISPONIBILIZARWINDOW_H
