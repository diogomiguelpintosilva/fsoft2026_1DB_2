#include "GerenciamentoService.h"
#include <iostream>

GerenciamentoService::GerenciamentoService() {}

void GerenciamentoService::atualizar(Cliente* cliente) {
	if (cliente == nullptr) {
		std::cout << "  [ERRO] Cliente invalido.\n";
		return;
	}
	cliente->atualizarGerenciamento();
}

Gerenciamento* GerenciamentoService::obterGerenciamento(Cliente* cliente) {
	if (cliente == nullptr) {
		std::cout << "  [ERRO] Cliente invalido.\n";
		return nullptr;
	}
	atualizar(cliente);
	return &cliente->getGerenciamento();
}
