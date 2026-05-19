#include "controller/ContaOrdemController.h"

ContaOrdemController::ContaOrdemController(ContaOrdemService& contaOrdemService)
    : contaOrdemService(contaOrdemService) {}

ContaOrdem* ContaOrdemController::criarConta(Cliente* cliente,
                                             const std::string& pin) {
    return contaOrdemService.criarConta(cliente, pin);
}

ContaOrdem* ContaOrdemController::acederConta(Cliente* cliente,
                                              const std::string& numeroConta,
                                              const std::string& pin) {
    return contaOrdemService.acederConta(cliente, numeroConta, pin);
}

bool ContaOrdemController::depositar(ContaOrdem* conta, double valor) {
    return contaOrdemService.depositar(conta, valor);
}

bool ContaOrdemController::levantar(ContaOrdem* conta, double valor) {
    return contaOrdemService.levantar(conta, valor);
}

bool ContaOrdemController::transferir(ContaOrdem* contaOrigem,
                                      const std::string& nifDestino,
                                      const std::string& numeroContaDestino,
                                      double valor) {
    return contaOrdemService.transferir(contaOrigem, nifDestino,
                                       numeroContaDestino, valor);
}