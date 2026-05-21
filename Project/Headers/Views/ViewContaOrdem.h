#ifndef VIEWCONTAORDEM_H
#define VIEWCONTAORDEM_H

#include "controller/ContaOrdemController.h"
#include "controller/ContaPoupancaController.h"
#include "view/ViewContaPoupanca.h"

class ViewContaOrdem {
public:
    ViewContaOrdem(ContaOrdemController& contaOrdemController,ContaPoupancaController& contaPoupancaController);


    void mostrarMenu(ContaOrdem* conta);

private:
    ContaOrdemController& contaOrdemController;
    ContaPoupancaController& contaPoupancaController;


    void opcaoDepositar(ContaOrdem* conta);
    void opcaoLevantar(ContaOrdem* conta);
    void opcaoTransferir(ContaOrdem* conta);
    void opcaoConsultarSaldo(ContaOrdem* conta);
    void opcaoVerHistorico(ContaOrdem* conta);
    void opcaoContasPoupanca(ContaOrdem* conta);
};

#endif // VIEWCONTAORDEM_H