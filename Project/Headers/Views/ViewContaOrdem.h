#ifndef VIEWCONTAORDEM_H
#define VIEWCONTAORDEM_H

#include "controller/ContaOrdemController.h"
#include "controller/ContaPoupancaController.h"
#include "view/ViewContaPoupanca.h"

// A ViewContaOrdem trata de mostrar o menu da Conta Ordem
// e de passar os dados ao ContaOrdemController.

class ViewContaOrdem {
public:
    ViewContaOrdem(ContaOrdemController& contaOrdemController,
                   ContaPoupancaController& contaPoupancaController);

    // Mostra o menu da Conta Ordem e fica em ciclo ate o utilizador sair.
    void mostrarMenu(ContaOrdem* conta);

private:
    ContaOrdemController& contaOrdemController;
    ContaPoupancaController& contaPoupancaController;

    // Cada funcao le os dados e chama o controller
    void opcaoDepositar(ContaOrdem* conta);
    void opcaoLevantar(ContaOrdem* conta);
    void opcaoTransferir(ContaOrdem* conta);
    void opcaoConsultarSaldo(ContaOrdem* conta);
    void opcaoVerHistorico(ContaOrdem* conta);
    void opcaoContasPoupanca(ContaOrdem* conta);
};

#endif // VIEWCONTAORDEM_H