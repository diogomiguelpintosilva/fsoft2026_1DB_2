#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"
#include <string>

class ContaPoupanca : public Conta {

public:

    ContaPoupanca(const std::string& numConta, const std::string& pin);

    bool depositar(double valor);
    std::string mostrarInfo() const;

};

#endif //CONTAPOUPANCA_H
