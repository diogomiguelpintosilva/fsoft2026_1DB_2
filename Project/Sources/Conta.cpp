#include "Conta.h"
#include <iostream>
#include <iomanip>


Conta::Conta(const std::string& numeroConta, const std::string& pin)
    : numeroConta(numeroConta), pin(pin), saldo(0) {}

const std::string& Conta::getPin() const {return pin; }
const std::string& Conta::getNumeroConta() const {

    return numeroConta;
}


double Conta::getSaldo() const {

    return saldo;
}


bool Conta::verificarPin(const std::string& pinIntroduzi) const {

    return pin == pinIntroduzi;
}


void Conta::setSaldo(double novoSaldo) {

    saldo = novoSaldo;
}
