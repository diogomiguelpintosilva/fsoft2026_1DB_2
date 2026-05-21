#ifndef VIEWCONTAPOUPANCA_H
#define VIEWCONTAPOUPANCA_H

#include "controller/ContaPoupancaController.h"


class ViewContaPoupanca {
public:
    ViewContaPoupanca(ContaPoupancaController& controller);


    void mostrarMenu(ContaPoupanca* conta);

private:
    ContaPoupancaController& controller;

    void opcaoDepositar(ContaPoupanca* conta);
    void opcaoConsultarSaldo(ContaPoupanca* conta);
};

#endif // VIEWCONTAPOUPANCA_H