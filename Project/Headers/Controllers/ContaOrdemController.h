#ifndef CONTAORDEMCONTROLLER_H
#define CONTAORDEMCONTROLLER_H

#include "service/ContaOrdemService.h"
#include <string>

// O ContaOrdemController recebe os dados da View
// e pede ao ContaOrdemService para realizar as operacoes.

class ContaOrdemController {
public:
    ContaOrdemController(ContaOrdemService& contaOrdemService);

    // Cria uma nova Conta Ordem para o cliente.
    ContaOrdem* criarConta(Cliente* cliente, const std::string& pin);

    // Acede a uma Conta Ordem existente.
    ContaOrdem* acederConta(Cliente* cliente,
                            const std::string& numeroConta,
                            const std::string& pin);

    // Operacoes sobre a conta
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