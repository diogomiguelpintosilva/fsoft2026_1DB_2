#ifndef TRABALHO_DE_SISTEMA_BANCÁRIO_CONTAPOUPANCASERVICE_H
#define TRABALHO_DE_SISTEMA_BANCÁRIO_CONTAPOUPANCASERVICE_H

#include "ContaOrdem.h"
#include <string>

class ContaPoupancaService {

    public:
    ContaPoupancaService();

    ContaPoupanca* criarConta(ContaOrdem* contaOrdem, const std::string& pin);

    ContaPoupanca* acederConta(ContaOrdem* contaOrdem, int indice, const std::string& pin);

    bool depositar(ContaPoupanca* conta, double valor);
};

#endif //TRABALHO_DE_SISTEMA_BANCÁRIO_CONTAPOUPANCASERVICE_H