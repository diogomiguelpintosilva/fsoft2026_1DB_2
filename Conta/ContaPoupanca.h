#ifndef PROJETOFSOFT_CONTAPOUPANCA_H
#define PROJETOFSOFT_CONTAPOUPANCA_H

#include
#include "Conta.h"

class ContaPoupanca : public Conta {

public:

    ContaPoupanca(const std::string& numConta, const std::string& pin);

    bool depositar(double valor);
    void consultarSaldo() const;

    void mostrarInfo() const;
};

#endif //PROJETOFSOFT_CONTAPOUPANCA_H