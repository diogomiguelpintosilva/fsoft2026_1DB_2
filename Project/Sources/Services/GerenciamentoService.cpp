#include "service/GerenciamentoService.h"
#include "iostream"

GerenciamentoService::GerenciamentoService(){}

void GerenciamentoService::atualizar(Cliente* cliente){
	if (cliente==nullptr){
		std::cout<< "[Erro] Cliente inválido.\n";
		return;
	}
	cliente->atualizarGerencianto();
}

Gerenciamento*GerenciamentoService::obeterGerenciamento(Cliente* cliente){
	if (cliente==nullptr){
		stdd::cout << "[Erro] Cliente inválido.\n";
		return nullptr;
	}
	atualizar(cliente);
	return &cliente->getGerenciamento();
}
