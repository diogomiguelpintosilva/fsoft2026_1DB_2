#ifndef CONTAORDEMCONTROLLER_H
#define CONTAORDEMCONTROLLER_H

#include "ContaOrdemService.h"
#include <string>

class ContaOrdemController {
public:
    ContaOrdemController(ContaOrdemService& contaOrdemService);

    ContaOrdem* criarConta(Cliente* cliente, const std::string& pin);


    ContaOrdem* acederConta(Cliente* cliente,
                            const std::string& numeroConta,
                            const std::string& pin);


    bool depositar(ContaOrdem* conta, double valor);
    bool levantar(ContaOrdem* conta, double valor);
    bool transferir(ContaOrdem* contaOrigem,
                    const std::string& nifDestino,
                    const std::string& numeroContaDestino,
                    double valor);

private:
    ContaOrdemService& contaOrdemService;
};

#endif // CONTAORDEMCONTROLLER_H