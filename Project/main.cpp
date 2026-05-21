#include "GestorSistemaBancario.h"

#include "ClienteService.h"
#include "service/ContaOrdemService.h"
#include "service/ContaPoupancaService.h"
#include "service/GerenciamentoService.h"

#include "controller/ClienteController.h"
#include "controller/ContaOrdemController.h"
#include "controller/ContaPoupancaController.h"
#include "controller/GerenciamentoController.h"

#include "view/ViewPrincipal.h"
#include "view/ViewCliente.h"
#include "view/ViewContaOrdem.h"
#include "view/ViewContaPoupanca.h"

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