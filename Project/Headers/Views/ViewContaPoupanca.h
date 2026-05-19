#ifndef VIEWCONTAPOUPANCA_H
#define VIEWCONTAPOUPANCA_H

#include "controller/ContaPoupancaController.h"

// A ViewContaPoupanca so trata de mostrar o menu da Conta Poupanca
// e de ler o que o utilizador escolhe.
// Depois passa os dados ao ContaPoupancaController.

class ViewContaPoupanca {
public:
    ViewContaPoupanca(ContaPoupancaController& controller);

    // Mostra o menu da Conta Poupanca e fica em ciclo ate o utilizador sair.
    void mostrarMenu(ContaPoupanca* conta);

private:
    ContaPoupancaController& controller;

    // Cada funcao le os dados do utilizador e chama o controller
    void opcaoDepositar(ContaPoupanca* conta);
    void opcaoConsultarSaldo(ContaPoupanca* conta);
};

#endif // VIEWCONTAPOUPANCA_H