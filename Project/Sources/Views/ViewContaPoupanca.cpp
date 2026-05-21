#include "ViewContaPoupanca.h"
#include "ViewUtils.h"
#include <iostream>

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
    controller.depositar(conta, valor);
    pausar();
}

void ViewContaPoupanca::opcaoConsultarSaldo(ContaPoupanca* conta) {
    // A propria ContaPoupanca sabe mostrar o saldo
    conta->consultarSaldo();
    pausar();
}
