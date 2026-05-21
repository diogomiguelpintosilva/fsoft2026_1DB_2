#ifndef CONTAORDEMSERVICE_H
#define CONTAORDEMSERVICE_H

#include "Cliente.h"
#include "GestorSistemaBancario.h"
#include <string>

class ContaOrdemService {
public:
    ContaOrdemService(GestorSistemaBancario& gestor);

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
    GestorSistemaBancario& gestor;
};

#endif // CONTAORDEMSERVICE_H