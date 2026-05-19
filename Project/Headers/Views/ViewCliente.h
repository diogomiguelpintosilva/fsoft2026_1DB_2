#ifndef VIEWCLIENTE_H
#define VIEWCLIENTE_H

#include "controller/ClienteController.h"
#include "controller/ContaOrdemController.h"
#include"cotroller/GerenciamentoController.h"
#include"view/ViewContaOrdem.h"

class ViewCliente {
public:
    ViewCliente(ClienteController& clienteController, ContaOrdemController& contaOrdemController, GerenciamentoController& gerenciamentoController, ViewContaController& viewContaController);

private:
    ClienteController& clienteController;
    ContaOrdemController& contaOrdemController;
    GerenciamentoController& gerenciamentoController;
    ViewContaController& viewContaController;

    void opcaoCriarConta(Cliente* cliente);
    void opcaoAcederConta(Cliente* cliente);
    void opcaoGerenciamento(Cliente* cliente);
    void opcaoListarContas(Cliente* cliente);
};

#endif