#include <iostream>
#include "ContaPoupanca.h"
#include <iomanip>

ContaPoupanca::ContaPoupanca(const std::string &numConta, const std::string &pin) : Conta(numConta, pin) {}

bool ContaPoupanca::depositar(double valor) {

    if (valor <= 0) {
        std::cout << "[ERRO] Valor invalido. Deve ser maior que zero! \n";
        return false;
    }

    setSaldo(getSaldo() + valor);
    std::cout << "Deposito de " << std::fixed << std::setprecision(2) << valor << << " EUR efetuado com sucesso. \n";

    std::cout << "Novo saldo: " << getSaldo() << " EUR \n";

    return true;
}


void ContaPoupanca::consultarSaldo() const{}
