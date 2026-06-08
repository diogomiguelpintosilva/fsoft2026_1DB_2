#include "ContaPoupancaService.h"


ContaPoupancaService::ContaPoupancaService() {}

ContaPoupanca* ContaPoupancaService::criarConta(ContaOrdem* contaOrdem, const std::string& pin) {
    if (contaOrdem == nullptr) {

        return nullptr;
    }
    contaOrdem->adicionarContaPoupanca(pin);
    return contaOrdem->getContaPoupanca(contaOrdem->numContasPoupanca() - 1);
}

ContaPoupanca* ContaPoupancaService::acederConta(ContaOrdem* contaOrdem, int indice, const std::string& pin) {
    if (contaOrdem == nullptr) {

        return nullptr;
    }
    ContaPoupanca* cp = contaOrdem->getContaPoupanca(indice);
    if (cp == nullptr) {

        return nullptr;
    }
    if (!cp->verificarPin(pin)) {

        return nullptr;
    }
    return cp;
}

bool ContaPoupancaService::depositar(ContaPoupanca* conta, double valor) {
    if (conta == nullptr) {

        return false;
    }
    return conta->depositar(valor);
}
