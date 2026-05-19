#ifndef CONTAPOUPANCACONTROLLER_H
#define CONTAPOUPANCACONTROLLER_H

#include "service/ContaPoupancaService.h"
#include <string>

// O ContaPoupancaController recebe os dados da View
// e pede ao ContaPoupancaService para realizar as operacoes.

class ContaPoupancaController {
public:
    ContaPoupancaController(ContaPoupancaService& contaPoupancaService);

    // Cria uma nova Conta Poupanca dentro de uma Conta Ordem.
    ContaPoupanca* criarConta(ContaOrdem* contaOrdem, const std::string& pin);

    // Acede a uma Conta Poupanca pelo indice e PIN.
    ContaPoupanca* acederConta(ContaOrdem* contaOrdem,
                               int indice,
                               const std::string& pin);

    // Faz um deposito.
    bool depositar(ContaPoupanca* conta, double valor);

private:
    ContaPoupancaService& contaPoupancaService;
};

#endif // CONTAPOUPANCACONTROLLER_H