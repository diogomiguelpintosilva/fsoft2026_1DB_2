#include "Persistencia.h"
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
#include "ViewContaPoupanca.h"
#include "ViewGestor.h"

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

    ViewCliente   viewCliente(clienteController, contaOrdemController, contaPoupancaController, gerenciamentoController);
    ViewGestor    viewGestor(gestor);
    ViewPrincipal viewPrincipal(clienteController, viewCliente, viewGestor);

    // O caminho do ficheiro de dados e definido pelo CMake (BANCO_DATA_FILE),
    // apontando sempre para Project/banco.dat. Assim o ficheiro nao depende
    // de onde o programa corre e e partilhado no git entre todo o grupo.
#ifdef BANCO_DATA_FILE
    const std::string FICHEIRO = BANCO_DATA_FILE;
#else
    const std::string FICHEIRO = "banco.dat";
#endif
    Persistencia::carregar(gestor, FICHEIRO);

    viewPrincipal.iniciar(gestor.getNome());

    Persistencia::guardar(gestor, FICHEIRO);

    return 0;
}

