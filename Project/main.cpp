#include "GestorSistemaBancario.h"

#include "ClienteService.h"
#include "ContaOrdemService.h"
#include "ContaPoupancaService.h"
#include "GerenciamentoService.h"

#include "ClienteController.h"
#include "ContaOrdemController.h"
#include "ContaPoupancaController.h"
#include "GerenciamentoController.h"

#include "ViewPrincipal.h"
#include "ViewCliente.h"
#include "ViewContaOrdem.h"
#include "ViewContaPoupanca.h"

int main() {
    GestorSistemaBancario gestor("Banco ISEP");

    ClienteService       clienteService(gestor);
    ContaOrdemService    contaOrdemService(gestor);
    ContaPoupancaService contaPoupancaService;
    GerenciamentoService gerenciamentoService;

    ClienteController       clienteController(clienteService);
    ContaOrdemController    contaOrdemController(contaOrdemService);
    ContaPoupancaController contaPoupancaController(contaPoupancaService);
    GerenciamentoController gerenciamentoController(gerenciamentoService);

    ViewContaPoupanca viewContaPoupanca(contaPoupancaController);
    ViewContaOrdem    viewContaOrdem(contaOrdemController, contaPoupancaController);
    ViewCliente       viewCliente(clienteController, contaOrdemController,
                                  gerenciamentoController, viewContaOrdem);
    ViewPrincipal     viewPrincipal(clienteController, viewCliente);

    viewPrincipal.iniciar(gestor.getNome());

    return 0;
}