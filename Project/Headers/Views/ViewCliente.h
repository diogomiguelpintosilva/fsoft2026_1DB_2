#ifndef VIEWCLIENTE_H
#define VIEWCLIENTE_H

#include "ClienteController.h"
#include "ContaOrdemController.h"
#include "ContaPoupancaController.h"
#include "GerenciamentoController.h"
#include "ViewContaOrdem.h"

class ViewCliente {
public:
    ViewCliente(ClienteController& clienteController,
                ContaOrdemController& contaOrdemController,
                ContaPoupancaController& contaPoupancaController,
                GerenciamentoController& gerenciamentoController);

    void mostrarMenu(Cliente* cliente);

private:
    ClienteController& clienteController;
    ContaOrdemController& contaOrdemController;
    ContaPoupancaController& contaPoupancaController;
    GerenciamentoController& gerenciamentoController;

    void opcaoCriarConta(Cliente* cliente);
    void opcaoAcederConta(Cliente* cliente);
    void opcaoGerenciamento(Cliente* cliente);
    void opcaoListarContas(Cliente* cliente);
};

#endif // VIEWCLIENTE_H
