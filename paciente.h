#ifndef PACIENTE_H
#define PACIENTE_H

#include <QObject>

#define MEDIA 70

class Paciente
{

private:
    QString nome;
    int prioridade;
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

signals:

public slots:
};

#endif // PACIENTE_H
