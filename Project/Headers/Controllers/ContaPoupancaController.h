#ifndef CONTAPOUPANCACONTROLLER_H
#define CONTAPOUPANCACONTROLLER_H

#include "ContaPoupancaService.h"
#include <string>

class ContaPoupancaController {
public:
    ContaPoupancaController(ContaPoupancaService& contaPoupancaService);

    ContaPoupanca* criarConta(ContaOrdem* contaOrdem, const std::string& pin);


    ContaPoupanca* acederConta(ContaOrdem* contaOrdem,
                               int indice,
                               const std::string& pin);

    bool depositar(ContaPoupanca* conta, double valor);

private:
    ContaPoupancaService& contaPoupancaService;
};

#endif // CONTAPOUPANCACONTROLLER_H
