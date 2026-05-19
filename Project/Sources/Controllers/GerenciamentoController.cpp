#include "controller/GerenciamentoService.h"

GerenciamentoService::GerenciamentoService(GerenciamentoService&gerenciamentoService):gerenciamentoService() {}

GerenciamentoService* GerenciamentoService::obter (Cliente* cliente) {
    return gerenciamentoService.obterGerenciamento(cliente);
}