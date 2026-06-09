#include "ViewContaPoupanca.h"
#include "ViewUtils.h"
#include <iostream>
#include <iomanip>

ViewContaPoupanca::ViewContaPoupanca(ContaPoupancaController& controller)
    : controller(controller) {}

void ViewContaPoupanca::mostrarMenu(ContaPoupanca* conta) {
    int opcao;
    do {
        cabecalho("Conta Poupanca - " + conta->getNumeroConta());
        std::cout << "  1. Depositar\n";
        std::cout << "  2. Consultar Saldo\n";
        std::cout << "  0. Voltar\n";
        std::cout << "  Opcao: ";
        std::cin >> opcao;
        limparInput();

        switch (opcao) {
            case 1:  opcaoDepositar(conta);      break;
            case 2:  opcaoConsultarSaldo(conta); break;
            case 0:  break;
            default: std::cout << "  Opcao invalida.\n"; break;
        }
    } while (opcao != 0);
}

void ViewContaPoupanca::opcaoDepositar(ContaPoupanca* conta) {
    double valor;
    std::cout << "  Valor a depositar: ";
    std::cin >> valor;
    limparInput();

    if (controller.depositar(conta, valor)) {
        std::cout << "  Deposito de " << std::fixed << std::setprecision(2) << valor << " EUR efetuado com sucesso.\n";
        std::cout << "  Novo saldo: " << std::fixed << std::setprecision(2) << conta->getSaldo() << " EUR\n";
    } else {
        std::cout << "  [ERRO] Valor invalido. Deve ser maior que zero!\n";
    }
    pausar();
}

void ViewContaPoupanca::opcaoConsultarSaldo(ContaPoupanca* conta) {
    std::cout << "\n  Saldo atual (" << conta->getNumeroConta() << "): "
              << std::fixed << std::setprecision(2) << conta->getSaldo() << " EUR\n";
    pausar();
}
