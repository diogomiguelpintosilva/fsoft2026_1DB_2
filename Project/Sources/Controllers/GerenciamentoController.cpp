#include "controller/GerenciamentoController.h"

GerenciamentoController::GerenciamentoController(GerenciamentoService& gerenciamentoService)
    : gerenciamentoService(gerenciamentoService) {}

Gerenciamento* GerenciamentoController::obter(Cliente* cliente) {
    return gerenciamentoService.obterGerenciamento(cliente);
}