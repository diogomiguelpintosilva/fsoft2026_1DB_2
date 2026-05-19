#include "controller/ContaPoupancaController.h"

ContaPoupancaController::ContaPoupancaController(ContaPoupancaService& contaPoupancaService)
    : contaPoupancaService(contaPoupancaService) {}

ContaPoupanca* ContaPoupancaController::criarConta(ContaOrdem* contaOrdem,
                                                   const std::string& pin) {
    return contaPoupancaService.criarConta(contaOrdem, pin);
}

ContaPoupanca* ContaPoupancaController::acederConta(ContaOrdem* contaOrdem,
                                                    int indice,
                                                    const std::string& pin) {
    return contaPoupancaService.acederConta(contaOrdem, indice, pin);
}

bool ContaPoupancaController::depositar(ContaPoupanca* conta, double valor) {
    return contaPoupancaService.depositar(conta, valor);
}