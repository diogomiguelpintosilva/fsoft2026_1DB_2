#include "ViewContaOrdem.h"
#include "ViewUtils.h"
#include <iostream>
#include <iomanip>

ViewContaOrdem::ViewContaOrdem(ContaOrdemController& contaOrdemController, ContaPoupancaController& contaPoupancaController)
    : contaOrdemController(contaOrdemController), contaPoupancaController(contaPoupancaController) {}

void ViewContaOrdem::mostrarMenu(ContaOrdem* conta) {
    int opcao;
    do {
        cabecalho("Conta Ordem - " + conta->getNumeroConta());
        std::cout << "  1. Depositar\n";
        std::cout << "  2. Levantar\n";
        std::cout << "  3. Transferir\n";
        std::cout << "  4. Consultar Saldo\n";
        std::cout << "  5. Ver Historico\n";
        std::cout << "  6. Gerir Contas Poupanca\n";
        std::cout << "  0. Voltar\n";
        std::cout << "  Opcao: ";
        std::cin >> opcao;
        limparInput();

        switch (opcao) {
            case 1: opcaoDepositar(conta);      break;
            case 2: opcaoLevantar(conta);       break;
            case 3: opcaoTransferir(conta);     break;
            case 4: opcaoConsultarSaldo(conta); break;
            case 5: opcaoVerHistorico(conta);   break;
            case 6: opcaoContasPoupanca(conta); break;
            case 0: break;
            default: std::cout << "  Opcao invalida.\n"; break;
        }
    } while (opcao != 0);
}

void ViewContaOrdem::opcaoDepositar(ContaOrdem* conta) {
    double valor;
    std::cout << "  Valor a depositar: ";
    std::cin >> valor;
    limparInput();

    if (contaOrdemController.depositar(conta, valor)) {
        std::cout << "  Deposito de " << std::fixed << std::setprecision(2) << valor << " EUR efetuado com sucesso.\n";
        std::cout << "  Novo saldo: " << std::fixed << std::setprecision(2) << conta->getSaldo() << " EUR\n";
    } else {
        if (valor <= 0)
            std::cout << "  [ERRO] Valor invalido. Deve ser maior que zero!\n";
        else
            std::cout << "  [ERRO] Nao foi possivel efetuar o deposito.\n";
    }
    pausar();
}

void ViewContaOrdem::opcaoLevantar(ContaOrdem* conta) {
    double valor;
    std::cout << "  Valor a levantar: ";
    std::cin >> valor;
    limparInput();

    if (contaOrdemController.levantar(conta, valor)) {
        std::cout << "  Levantamento de " << std::fixed << std::setprecision(2) << valor << " EUR efetuado com sucesso.\n";
        std::cout << "  Novo saldo: " << std::fixed << std::setprecision(2) << conta->getSaldo() << " EUR\n";
    } else {
        if (valor <= 0)
            std::cout << "  [ERRO] Valor invalido. Deve ser maior que zero!\n";
        else
            std::cout << "  [ERRO] Saldo insuficiente! Saldo disponivel: " << std::fixed << std::setprecision(2) << conta->getSaldo() << " EUR\n";
    }
    pausar();
}

void ViewContaOrdem::opcaoTransferir(ContaOrdem* conta) {
    std::string nifDestino, numeroContaDestino;
    double valor;

    std::cout << "  NIF do titular da conta destino: ";
    std::getline(std::cin, nifDestino);
    std::cout << "  Numero da conta destino: ";
    std::getline(std::cin, numeroContaDestino);
    std::cout << "  Valor a transferir: ";
    std::cin >> valor;
    limparInput();

    if (contaOrdemController.transferir(conta, nifDestino, numeroContaDestino, valor)) {
        std::cout << "  Transferencia de " << std::fixed << std::setprecision(2) << valor << " EUR efetuada com sucesso.\n";
        std::cout << "  Novo saldo: " << std::fixed << std::setprecision(2) << conta->getSaldo() << " EUR\n";
    } else {
        std::cout << "  [ERRO] Nao foi possivel efetuar a transferencia.\n";
        std::cout << "  Verifique o NIF, numero de conta e saldo disponivel.\n";
    }
    pausar();
}

void ViewContaOrdem::opcaoConsultarSaldo(ContaOrdem* conta) {
    std::cout << "\n  Saldo atual (" << conta->getNumeroConta() << "): "
              << std::fixed << std::setprecision(2) << conta->getSaldo() << " EUR\n";
    pausar();
}

void ViewContaOrdem::opcaoVerHistorico(ContaOrdem* conta) {
    std::cout << "\n --- Historico de Transacoes (" << conta->getNumeroConta() << ") ---\n";
    auto historico = conta->getHistoricoCompleto();
    if (historico.empty()) {
        std::cout << "  Sem transacoes registadas.\n";
    } else {
        std::cout << std::left
                  << std::setw(12) << "Data"
                  << std::setw(45) << "Descricao"
                  << "Valor (EUR)\n";
        std::cout << std::string(68, '-') << "\n";
        for (const auto& r : historico) {
            std::cout << std::left
                      << std::setw(12) << r.data
                      << std::setw(45) << r.descricao
                      << std::fixed << std::setprecision(2) << r.valor << "\n";
        }
    }
    pausar();
}

void ViewContaOrdem::opcaoContasPoupanca(ContaOrdem* conta) {
    ViewContaPoupanca viewCP(contaPoupancaController);

    int opcao;
    do {
        cabecalho("Contas Poupanca");

        if (conta->numContasPoupanca() == 0) {
            std::cout << "  Sem contas poupanca associadas.\n";
        } else {
            for (size_t i = 0; i < conta->numContasPoupanca(); ++i) {
                ContaPoupanca* cp = conta->getContaPoupanca(i);
                std::cout << "  [" << (i + 1) << "] " << cp->mostrarInfo() << "\n";
            }
        }

        std::cout << "\n  1. Criar nova Conta Poupanca\n";
        std::cout << "  2. Aceder a uma Conta Poupanca\n";
        std::cout << "  0. Voltar\n";
        std::cout << "  Opcao: ";
        std::cin >> opcao;
        limparInput();

        if (opcao == 1) {
            std::string pin;
            std::cout << "  Defina um PIN para a conta poupanca: ";
            std::getline(std::cin, pin);
            ContaPoupanca* cp = contaPoupancaController.criarConta(conta, pin);
            if (cp != nullptr) {
                std::cout << "  Conta Poupanca criada com sucesso!\n";
                std::cout << "  Numero: " << cp->getNumeroConta() << "\n";
            } else {
                std::cout << "  [ERRO] Nao foi possivel criar a conta.\n";
            }
            pausar();

        } else if (opcao == 2) {
            if (conta->numContasPoupanca() == 0) {
                std::cout << "  Nao tens contas poupanca criadas.\n";
                pausar();
            } else {
                int indice;
                std::cout << "  Numero de conta (1-" << conta->numContasPoupanca() << "): ";
                std::cin >> indice;
                limparInput();
                std::string pin;
                std::cout << "  PIN: ";
                std::getline(std::cin, pin);

                ContaPoupanca* cp = contaPoupancaController.acederConta(conta, indice - 1, pin);
                if (cp != nullptr) {
                    viewCP.mostrarMenu(cp);
                } else {
                    std::cout << "  [ERRO] Indice ou PIN incorretos.\n";
                    pausar();
                }
            }
        }
    } while (opcao != 0);
}
