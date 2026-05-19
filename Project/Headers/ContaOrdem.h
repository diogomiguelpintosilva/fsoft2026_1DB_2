#ifndef CONTAORDEM_H
#define CONTAORDEM_H

#include "Conta.h"
#include "ContaPoupanca.h"
#include "TipoTransacao.h"
#include <vector>
#include <memory>

class ContaOrdem: public Conta {

public:
    ContaOrdem(const std::string& numeroConta,const std::string& pin);

    bool depositar(double valor);
    bool levantar(double valor);
    bool transferir(ContaOrdem& contaDestino, double valor);
    void consultarSaldo () const;

    void adicionarContaPoupanca(const std::string& pin);
    ContaPoupanca* getContaPoupanca(size_t indice = 0);
    size_t numContasPoupanca() const;
    void listarContasPoupanca() const;

    void mostrarInfo() const;


private:

    std::vector< std::shared_ptr<ContaPoupanca> > ContasPoupanca;

    std::vector<TipoTransacao> transacoes;

    void registarTransacao(TipoTransacao::TipoOperacao op, double valor, const std::string& descricao);

    std::sting gerarNumeroPoupanca() const;
}

#endif //CONTAORDEM_H