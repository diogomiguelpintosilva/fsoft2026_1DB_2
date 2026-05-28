#include "ViewContaOrdem.h"
#include "ViewUtils.h"
#include <iostream>

ViewContaOrdem::ViewContaOrdem(ContaOrdemController& contaOrdemController, ContaPoupancaController& contaPoupancaController):contaOrdemController(contaOrdemController), contaPoupancaController(contaPoupancaController) {}

void ViewContaOrdem::mostrarMenu(ContaOrdem* conta) {
    int opcao;
    do {
        cabecalho ("Conta Ordem- "+ conta->getNumeroConta());
        std::cout << "1. Depositar\n";
        std::cout << "2. Levantar\n";
        std::cout << "3. Transferir\n";
        std::cout << "4. Consultar Saldo\n";
        std::cout << "5. Ver Histórico\n";
        std::cout << "6. Gerir Contas Poupança\n";
        std::cout << "0. Voltar\n";
        std::cout << "Opcao: ";
        std::cin >> opcao;
        limparInput();

        switch (opcao) {
            case 1: opcaoDepositar(conta); break;
            case 2: opcaoLevantar(conta); break;
                case 3: opcaoTransferir(conta); break;
                case 4: opcaoConsultarSaldo(conta); break;
                case 5: opcaoVerHistorico(conta); break;
                case 6: opcaoContasPoupanca(conta); break;
                case 0: break;
                default: std::cout << "Opcao Inválida.\n"; break;

        }

    }while (opcao != 0);

}

void ViewContaOrdem::opcaoDepositar(ContaOrdem*conta) {
    double valor;
    std::cout << "Valor a depositar: ";
    std::cin >> valor;
    limparInput();
    contaOrdemController.depositar(conta, valor);
    pausar();

}

void ViewContaOrdem::opcaoLevantar(ContaOrdem*conta) {
    double valor;
    std::cout << "Valor a levantar: ";
    std::cin >> valor;
    limparInput();
    contaOrdemController.levantar(conta, valor);
    pausar();

}

void ViewContaOrdem::opcaoTransferir(ContaOrdem*conta) {
    std::string nifDestino, numeroContaDestino;
    double valor;

    std::cout << "NIF do titular da conta destino:";
    std::getline(std::cin, nifDestino);
    std::cout << "Numero da conta destino: ";
    std::getline(std::cin, numeroContaDestino);
    std::cout <<"\n Valor a transferir: ";
    std::cin>>valor;
    limparInput();

    contaOrdemController.transferir(conta, nifDestino, numeroContaDestino, valor);

    pausar();

}

void ViewContaOrdem::opcaoConsultarSaldo(ContaOrdem* conta) {
    conta->consultarSaldo();
    pausar();
}

void ViewContaOrdem::opcaoVerHistorico(ContaOrdem* conta) {
    conta->mostrarHistorico();
    pausar();

}

void ViewContaOrdem::opcaoContasPoupanca(ContaOrdem* conta) {
    ViewContaPoupanca viewCP(contaPoupancaController);

    int opcao;
    do {
        cabecalho ("Contas Poupanca");
        conta->listarContasPoupanca();

        std::cout << "\n 1. Criar nova Conta Poupanca.\n";
        std::cout << " 2. Aceder a uma Conta Poupanca.\n";
        std::cout << " 0. Voltar\n";
        std::cout << "Opcao: ";
        std::cin >> opcao;
        limparInput();

        if(opcao == 1) {
            std::string pin;
            std::cout << "Defina um PIN para a conta poupanca: ";
            std::getline(std::cin, pin);
            contaPoupancaController.criarConta(conta, pin);
            pausar();

        }else if(opcao == 2) {
            if (conta -> numContasPoupanca() == 0) {
                std::cout << "Nao tens contas criadas.\n";
                pausar();

            }else {
                int indice;
                std::cout << " Numero de conta (1-" << conta -> numContasPoupanca() << "): ";
                std::cin >> indice;
                limparInput();

                std::string pin;
                std::cout << "PIN: ";
                std::getline(std::cin, pin);

                ContaPoupanca* cp = contaPoupancaController.acederConta(conta, indice - 1, pin);

                if (cp != nullptr) {
                    viewCP.mostrarMenu(cp);

                }
            }
        }
    }while (opcao != 0);
}

