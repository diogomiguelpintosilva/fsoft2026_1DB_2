#include "ContaPoupanca.h"
#include <sstream>
#include <iomanip>

ContaPoupanca::ContaPoupanca(const std::string& numConta, const std::string& pin)
    : Conta(numConta, pin) {}

bool ContaPoupanca::depositar(double valor) {
    if (valor <= 0) return false;
    setSaldo(getSaldo() + valor);
    return true;
}

std::string ContaPoupanca::mostrarInfo() const {
    std::ostringstream oss;
    oss << "[Conta Poupanca] Numero: " << getNumeroConta()
        << " | Saldo: " << std::fixed << std::setprecision(2) << getSaldo() << " EUR";
    return oss.str();
}
