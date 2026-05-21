#include "view/ViewCliente.h"
#include "view/ViewUtils.h"
#include <iostream>

ViewCliente::ViewCliente(ClienteController& clienteController,
                         ContaOrdemController& contaOrdemController,
                         GerenciamentoController& gerenciamentoController,
                         ViewContaOrdem& viewContaOrdem)
    : clienteController(clienteController),
      contaOrdemController(contaOrdemController),
      gerenciamentoController(gerenciamentoController),
      viewContaOrdem(viewContaOrdem) {}

void ViewCliente::mostrarMenu(Cliente* cliente) {
    int opcao;
    do {
        cabecalho("Menu do cliente - " + cliente->getNome());
        std::cout << "  1. Criar Conta Corrente\n";
        std::cout << "  2. Aceder Conta Corrente\n";
        std::cout << "  3. Ver gerenciamento financeiro\n";
        std::cout << "  4. Listar todas as contas\n";
        std::cout << "  0. Terminar sessao\n";
        std::cout << "  Opcao: ";
        std::cin >> opcao;
        limparInput();

        switch (opcao) {
            case 1: opcaoCriarConta(cliente);    break;
            case 2: opcaoAcederConta(cliente);   break;
            case 3: opcaoGerenciamento(cliente); break;
            case 4: opcaoListarContas(cliente);  break;
            case 0: std::cout << "  Sessao terminada.\n"; break;
            default: std::cout << "  Opcao invalida.\n"; break;
        }
    } while (opcao != 0);
}

void ViewCliente::opcaoCriarConta(Cliente* cliente) {
    std::string pin;
    std::cout << "  Defina um PIN para a nova conta: ";
    std::getline(std::cin, pin);
    contaOrdemController.criarConta(cliente, pin);
    pausar();
}

void ViewCliente::opcaoAcederConta(Cliente* cliente) {
    if (cliente->numContasOrdem() == 0) {
        std::cout << "  Ainda nao tem contas correntes criadas.\n";
        pausar();
        return;
    }
    std::string numeroConta, pin;
    std::cout << "  Numero da conta: ";
    std::getline(std::cin, numeroConta);
    std::cout << "  PIN: ";
    std::getline(std::cin, pin);

    ContaOrdem* conta = contaOrdemController.acederConta(cliente, numeroConta, pin);
    if (conta != nullptr) {
        viewContaOrdem.mostrarMenu(conta);
    } else {
        pausar();
    }
}

void ViewCliente::opcaoGerenciamento(Cliente* cliente) {
    Gerenciamento* g = gerenciamentoController.obter(cliente);
    if (g != nullptr) {
        g->mostrarResumo();
    }
    pausar();
}

void ViewCliente::opcaoListarContas(Cliente* cliente) {
    cabecalho("Contas de " + cliente->getNome());
    cliente->listarContas();
    pausar();
}