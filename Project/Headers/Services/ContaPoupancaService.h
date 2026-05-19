#ifndef CONTAPOUPANCASERVICE_H
#define CONTAPOUPANCASERVICE_H

#include "ContaOrdem.h"
#include <string>

class ContaPoupancaService {

    public:
    ContaPoupancaService();

    ContaPoupanca* criarConta(ContaOrdem* contaOrdem, const std::string& pin);

    ContaPoupanca* acederConta(ContaOrdem* contaOrdem, int indice, const std::string& pin);

    bool depositar(ContaPoupanca* conta, double valor);
};

#endif //CONTAPOUPANCASERVICE_H