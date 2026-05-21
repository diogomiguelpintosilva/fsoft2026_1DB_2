#include "ContaOrdemService.h"
#include <iostream>

ContaOrdemService::ContaOrdemService(GestorSistemaBancario& gestor)
    : gestor(gestor) {}

ContaOrdem* ContaOrdemService::criarConta(Cliente* cliente, const std::string& pin) {
    if (cliente == nullptr) {
        std::cout << "  [ERRO] Cliente invalido.\n";
        return nullptr;
    }
    return cliente->criarContaOrdem(pin);
}

ContaOrdem* ContaOrdemService::acederConta(Cliente* cliente,
                                           const std::string& numeroConta,
                                           const std::string& pin) {
    if (cliente == nullptr) {
        std::cout << "  [ERRO] Cliente invalido.\n";
        return nullptr;
    }
    ContaOrdem* conta = cliente->getContaOrdem(numeroConta, pin);
    if (conta == nullptr) {
        std::cout << "  [ERRO] Conta nao encontrada ou PIN incorreto.\n";
    }
    return conta;
}

bool ContaOrdemService::depositar(ContaOrdem* conta, double valor) {
    if (conta == nullptr) {
        std::cout << "  [ERRO] Conta invalida.\n";
        return false;
    }
    return conta->depositar(valor);
}

bool ContaOrdemService::levantar(ContaOrdem* conta, double valor) {
    if (conta == nullptr) {
        std::cout << "  [ERRO] Conta invalida.\n";
        return false;
    }
    return conta->levantar(valor);
}

bool ContaOrdemService::transferir(ContaOrdem* contaOrigem,
                                   const std::string& nifDestino,
                                   const std::string& numeroContaDestino,
                                   double valor) {
    if (contaOrigem == nullptr) {
        std::cout << "  [ERRO] Conta de origem invalida.\n";
        return false;
    }

    // Procura o cliente de destino pelo NIF
    Cliente* clienteDestino = gestor.buscarClientePorNif(nifDestino);
    if (clienteDestino == nullptr) {
        std::cout << "  [ERRO] Nao existe cliente com o NIF " << nifDestino << ".\n";
        return false;
    }

    // Procura a conta destino (so pelo numero, sem PIN — e uma transferencia)
    ContaOrdem* contaDestino = clienteDestino->getContaOrdemPorNumero(numeroContaDestino);
    if (contaDestino == nullptr) {
        std::cout << "  [ERRO] Conta de destino " << numeroContaDestino << " nao encontrada.\n";
        return false;
    }

    return contaOrigem->transferir(*contaDestino, valor);
}