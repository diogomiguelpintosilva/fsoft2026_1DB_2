#ifndef PROJETOFSOFT_CONTA_H
#define PROJETOFSOFT_CONTA_H

#include <string>

class Conta {

    public:

    Conta(const std::string& numeroConta, const std::string& pin);
    virtual ~Conta() = default;

    const std::string&getNumeroConta() const;
    double getSaldo() const;

    bool verificarPin(const std::string &pinIntroduzi) const;

    void setSaldo(double novoSaldo);

    bool verificaPin(const std::string& pin) const;
    virtual void mostrarInfo() const = 0;

protected:

    std::string numeroConta;
    double saldo;
    std::string pin;

    void getSaldo(double novoSaldo);
};

#endif //PROJETOFSOFT_CONTA_H