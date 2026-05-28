#include "ContaOrdem.h"
#include <iostream>
#include <iomanip>
#include <sstream>

ContaOrdem::ContaOrdem(const std::string& numeroConta, const std::string& pin)
    : Conta(numeroConta, pin) {}

bool ContaOrdem::depositar(double valor) {
    if (valor <= 0) {
        std::cout << "[ERRO] Valor invalido. Deve ser maior que zero! \n";
        return false;
    }
    setSaldo(getSaldo() + valor);
    registarTransacao(TipoTransacao::TipoOperacao::DEPOSITAR, valor, "Deposito");
    std::cout << "Deposito de " << std::fixed << std::setprecision(2) << valor << " EUR efetuado com sucesso. \n";
    std::cout << "Novo saldo: " << getSaldo() << " EUR \n";
    return true;
}

bool ContaOrdem::levantar(double valor) {
    if (valor <= 0) {
        std::cout << "[ERRO] Valor invalido. Deve ser maior que zero! \n";
        return false;
    }
    if (valor > getSaldo()) {
        std::cout << "[ERRO] Saldo insuficiente! Saldo disponivel: " << std::fixed << std::setprecision(2) << getSaldo() << " EUR \n";
        return false;
    }
    setSaldo(getSaldo() - valor);
    registarTransacao(TipoTransacao::TipoOperacao::LEVANTAR, -valor, "Levantamento");
    std::cout << "Levantamento de " << std::fixed << std::setprecision(2) << valor << " EUR efetuado com sucesso. \n";
    std::cout << "Novo saldo: " << getSaldo() << " EUR \n";
    return true;
}

bool ContaOrdem::transferir(ContaOrdem& contaDestino, double valor) {
    if (valor <= 0) {
        std::cout << "[ERRO] Valor invalido. Deve ser maior que zero! \n";
        return false;
    }
    if (contaDestino.getNumeroConta() == this->getNumeroConta()) {
        std::cout << "[ERRO] Nao e possivel transferir para a propria conta! \n";
        return false;
    }
    if (valor > getSaldo()) {
        std::cout << "[ERRO] Saldo insuficiente! Saldo disponivel: " << std::fixed << std::setprecision(2) << getSaldo() << " EUR \n";
        return false;
    }

    setSaldo(getSaldo() - valor);
    contaDestino.setSaldo(contaDestino.getSaldo() + valor);

    registarTransacao(TipoTransacao::TipoOperacao::TRANSFERIR, -valor, "Transf. saida -> " + contaDestino.getNumeroConta());
    contaDestino.registarTransacao(TipoTransacao::TipoOperacao::TRANSFERIR, valor, "Transf. entrada <- " + this->getNumeroConta());

    std::cout << " Transferencia de " << std::fixed << std::setprecision(2) << valor << " EUR para conta " << contaDestino.getNumeroConta() << " efetuada com sucesso. \n";
    std::cout << "Novo saldo: " << getSaldo() << " EUR \n";
    return true;
}

void ContaOrdem::consultarSaldo() const {
    std::cout << "Saldo atual (Ordem " << getNumeroConta() << "): " << std::fixed << std::setprecision(2) << getSaldo() << " EUR \n";
}

void ContaOrdem::adicionarContaPoupanca(const std::string& pin) {
    std::string numPoupanca = gerarNumeroPoupanca();
    contasPoupanca.push_back(std::make_shared<ContaPoupanca>(numPoupanca, pin));
    std::cout << " Conta Poupanca criada com sucesso. \n";
    std::cout << " Numero Conta: " << numPoupanca << " \n";
}

void ContaOrdem::adicionarContaPoupancaCarregada(const std::string& numero, const std::string& pin, double saldo) {
	auto cp = std::make_shared<ContaPoupanca>(numero, pin);
	cp->setSaldo(saldo);
	contasPoupanca.push_back(cp);
}

ContaPoupanca* ContaOrdem::getContaPoupanca(size_t indice) {
    if (indice < contasPoupanca.size())
        return contasPoupanca[indice].get();
    return nullptr;
}

size_t ContaOrdem::numContasPoupanca() const {
    return contasPoupanca.size();
}

void ContaOrdem::listarContasPoupanca() const {
    if (contasPoupanca.empty()) {
        std::cout << " Sem contas poupanca associadas.\n";
        return;
    }
    for (size_t i = 0; i < contasPoupanca.size(); i++) {
        std::cout << " [" << i + 1 << "] ";
        contasPoupanca[i]->mostrarInfo();
    }
}

const std::vector<std::pair<std::string, double>> ContaOrdem::getRegistosHistorico() const {
    std::vector<std::pair<std::string, double>> resultado;
    for (const auto& t : transacoes) {
        for (const auto& r : t.getRegistars()) {
            resultado.emplace_back(r.descricao, r.valor);
        }
    }
    return resultado;
}

void ContaOrdem::mostrarHistorico() const {
    std::cout << "\n --- Historico de Transacoes (" << getNumeroConta() << ") ---\n";
    if (transacoes.empty()) {
        std::cout << "Sem transacoes registadas.\n";
        return;
    }
    for (const auto& t : transacoes) {
        t.mostrarHistorico();
    }
}

void ContaOrdem::mostrarInfo() const {
    std::cout << " [Conta Ordem] Numero: " << getNumeroConta() << " | Saldo: " << std::fixed << std::setprecision(2) << getSaldo() << " EUR" << " | Contas Poupanca associadas: " << contasPoupanca.size() << " \n";
}

void ContaOrdem::registarTransacao(TipoTransacao::TipoOperacao op, double valor, const std::string& descricao) {
    transacoes.emplace_back(op, valor, descricao);
}

std::string ContaOrdem::gerarNumeroPoupanca() const {
    return "P" + getNumeroConta().substr(1) + std::to_string(contasPoupanca.size() + 1);
}
