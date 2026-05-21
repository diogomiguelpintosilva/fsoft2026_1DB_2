#include "service/ContaPoupancaService.h"
#include <iostream>

ContaPoupancaService::ContaPoupancaService() {}

ContaPoupanca* ContaPoupancaService::criarConta(ContaOrdem* contaOrdem, const std::string& pin) {
    if (contaOrdem == nullptr) {
        std::cout << "  [ERRO] Conta Ordem invalida.\n";
        return nullptr;
    }
    contaOrdem->adicionarContaPoupanca(pin);
    return contaOrdem->getContaPoupanca(contaOrdem->numContasPoupanca() - 1);
}

ContaPoupanca* ContaPoupancaService::acederConta(ContaOrdem* contaOrdem, int indice, const std::string& pin) {
    if (contaOrdem == nullptr) {
        std::cout << "  [ERRO] Conta Ordem invalida.\n";
        return nullptr;
    }
    ContaPoupanca* cp = contaOrdem->getContaPoupanca(indice);
    if (cp == nullptr) {
        std::cout << "  [ERRO] Conta Poupanca nao encontrada.\n";
        return nullptr;
    }
    if (!cp->verificarPin(pin)) {
        std::cout << "  [ERRO] PIN incorreto!\n";
        return nullptr;
    }
    return cp;
}

bool ContaPoupancaService::depositar(ContaPoupanca* conta, double valor) {
    if (conta == nullptr) {
        std::cout << "  [ERRO] Conta invalida.\n";
        return false;
    }
    return conta->depositar(valor);
}