#ifndef PACIENTE_H
#define PACIENTE_H

#include <QObject>
#include <QVector>
#include <QString>
class Paciente
{

private:
    QString nome;
    int prioridade;
    QString patologia;
    //prioridade 0 -> baixa
    //prioridade 1 -> média
    //prioridade 2 -> alta
public:
    explicit Paciente();

    QString getNome() const;
    void setNome(const QString &value);

    QString getStatus() const;

    int getPrioridade() const;
    void setPrioridade(int value);

    //void inserirMedicoAtendido(Medico a);
    //QVector <Medico> getFoiAtendido();

    QString getPatologia() const;
    void setPatologia(QString &value);
signals:

public slots:
};

#endif // PACIENTE_H
