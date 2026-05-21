#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

class ContaPoupanca : public Conta {

public:

    ContaPoupanca(const std::string& numConta, const std::string& pin);

    bool depositar(double valor);
    void consultarSaldo() const;

    void mostrarInfo() const;
};

#endif //CONTAPOUPANCA_H
