#include "ContaOrdemService.h"

ContaOrdemService::ContaOrdemService(GestorSistemaBancario& gestor)
    : gestor(gestor) {}

ContaOrdem* ContaOrdemService::criarConta(Cliente* cliente, const std::string& pin) {
    if (cliente == nullptr) {
        return nullptr;
    }
    return cliente->criarContaOrdem(pin);
}

ContaOrdem* ContaOrdemService::acederConta(Cliente* cliente, const std::string& numeroConta, const std::string& pin) {
    if (cliente == nullptr) {
        return nullptr;
    }
    return cliente -> getContaOrdem(numeroConta, pin);
}

bool ContaOrdemService::depositar(ContaOrdem* conta, double valor) {
    if (conta == nullptr) {
       return false;
    }
    return conta -> depositar(valor);
}

bool ContaOrdemService::levantar(ContaOrdem* conta, double valor) {
    if (conta == nullptr) {
        return false;
    }
    return conta -> levantar(valor);
}

bool ContaOrdemService::transferir(ContaOrdem* contaOrigem, const std::string& nifDestino, const std::string& numeroContaDestino, double valor) {
    if (contaOrigem == nullptr) {
        return false;
    }

    Cliente* clienteDestino = gestor.buscarClientePorNif(nifDestino);
    if (clienteDestino == nullptr) {

        return false;
    }


    ContaOrdem* contaDestino = clienteDestino->getContaOrdemPorNumero(numeroContaDestino);
    if (contaDestino == nullptr) {

        return false;
    }

    return contaOrigem -> transferir(*contaDestino, valor);
}
