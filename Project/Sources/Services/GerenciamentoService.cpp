#include "GerenciamentoService.h"


GerenciamentoService::GerenciamentoService() {}

void GerenciamentoService::atualizar(Cliente* cliente) {
	if (cliente == nullptr) {
		return;
	}
	cliente->atualizarGerenciamento();
}

Gerenciamento* GerenciamentoService::obterGerenciamento(Cliente* cliente) {
	if (cliente == nullptr) {

		return nullptr;
	}
	atualizar(cliente);
	return &cliente->getGerenciamento();
}
