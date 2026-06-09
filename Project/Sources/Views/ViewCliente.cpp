#include "ViewCliente.h"
#include "ViewUtils.h"
#include <iostream>

ViewCliente::ViewCliente(ClienteController& clienteController,
                         ContaOrdemController& contaOrdemController,
                         ContaPoupancaController& contaPoupancaController,
                         GerenciamentoController& gerenciamentoController)
    : clienteController(clienteController),
      contaOrdemController(contaOrdemController),
      contaPoupancaController(contaPoupancaController),
      gerenciamentoController(gerenciamentoController) {}

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
    ContaOrdem* conta = contaOrdemController.criarConta(cliente, pin);
    if (conta != nullptr) {
        std::cout << "  Conta criada com sucesso!\n";
        std::cout << "  Numero: " << conta->getNumeroConta() << "\n";
    } else {
        std::cout << "  [ERRO] Nao foi possivel criar a conta.\n";
    }
    pausar();
}

void ViewCliente::opcaoAcederConta(Cliente* cliente) {
    if (cliente->numContasOrdem() == 0) {
        std::cout << "  Nao tens contas criadas.\n";
        pausar();
        return;
    }

    cabecalho("Aceder Conta Corrente");
    for (size_t i = 0; i < cliente->numContasOrdem(); ++i) {
        ContaOrdem* co = cliente->getContaOrdemPorIndice(i);
        std::cout << "  [" << (i + 1) << "] " << co->mostrarInfo() << "\n";
    }

    std::string numeroConta, pin;
    std::cout << "\n  Numero da conta: ";
    std::getline(std::cin, numeroConta);
    std::cout << "  PIN: ";
    std::getline(std::cin, pin);

    ContaOrdem* conta = cliente->getContaOrdem(numeroConta, pin);
    if (conta == nullptr) {
        std::cout << "  [ERRO] Numero de conta ou PIN incorretos.\n";
        pausar();
        return;
    }

    ViewContaOrdem viewContaOrdem(contaOrdemController, contaPoupancaController);
    viewContaOrdem.mostrarMenu(conta);
}

void ViewCliente::opcaoGerenciamento(Cliente* cliente) {
    Gerenciamento* g = gerenciamentoController.obter(cliente);
    if (g != nullptr) {
        std::cout << g->mostrarResumo();
    }
    pausar();
}

void ViewCliente::opcaoListarContas(Cliente* cliente) {
    cabecalho("Contas de " + cliente->getNome());
    if (cliente->numContasOrdem() == 0) {
        std::cout << "  Sem contas criadas.\n";
    } else {
        for (size_t i = 0; i < cliente->numContasOrdem(); ++i) {
            ContaOrdem* co = cliente->getContaOrdemPorIndice(i);
            std::cout << "  [" << (i + 1) << "] " << co->mostrarInfo() << "\n";
        }
    }
    pausar();
}
