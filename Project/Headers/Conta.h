#ifndef CONTA_H
#define CONTA_H

#include <string>

class Conta {
public:
    Conta(const std::string& numeroConta, const std::string& pin);
    virtual ~Conta() = default;

    const std::string& getNumeroConta() const;
    double getSaldo() const;

    bool verificarPin(const std::string& pinIntroduzi) const;

    void setSaldo(double novoSaldo);

    virtual void mostrarInfo() const = 0;

protected:
    std::string numeroConta;
    double saldo;
    std::string pin;
};

#endif // CONTA_H
