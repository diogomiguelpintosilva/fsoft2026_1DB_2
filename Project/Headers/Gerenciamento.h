#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

#include <string>

class ContaOrdem;

class Gerenciamento {
public:
    Gerenciamento();

    void atualizar(const ContaOrdem& conta);

    double getDespesas() const;
    double getGanhos() const;
    double getLucros() const;

    void mostrarResumo() const;

private:
    double despesas;
    double ganhos;
    double lucros;
};

#endif // GERENCIAMENTO_H