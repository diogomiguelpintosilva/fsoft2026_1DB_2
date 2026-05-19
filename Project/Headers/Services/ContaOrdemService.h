#ifndef CONTAORDEMSERVICE_H
#define CONTAORDEMSERVICE_H

#include "Cliente.h"
#include "GestorSistemaBancario.h"
#include <string>

// O ContaOrdemService trata de tudo o que tem a ver com Contas Ordem:
// criar conta, depositar, levantar, transferir, consultar saldo e historico.

class ContaOrdemService {
public:
    ContaOrdemService(GestorSistemaBancario& gestor);

    // Cria uma nova Conta Ordem para o cliente.
    // Devolve um ponteiro para a conta criada, ou nullptr se falhar.
    ContaOrdem* criarConta(Cliente* cliente, const std::string& pin);

    // Acede a uma conta com numero e PIN.
    // Devolve um ponteiro para a conta, ou nullptr se o PIN estiver errado.
    ContaOrdem* acederConta(Cliente* cliente,
                            const std::string& numeroConta,
                            const std::string& pin);

    // Faz um deposito na conta.
    // Devolve true se correu bem.
    bool depositar(ContaOrdem* conta, double valor);

    // Faz um levantamento da conta.
    // Devolve true se correu bem (false se saldo insuficiente).
    bool levantar(ContaOrdem* conta, double valor);

    // Faz uma transferencia da conta de origem para a conta de destino.
    // Precisa do NIF do dono da conta destino para a encontrar.
    // Devolve true se correu bem.
    bool transferir(ContaOrdem* contaOrigem,
                    const std::string& nifDestino,
                    const std::string& numeroContaDestino,
                    double valor);

private:
    GestorSistemaBancario& gestor;
};

#endif // CONTAORDEMSERVICE_H