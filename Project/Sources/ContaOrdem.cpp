#include "ContaOrdem.h"
#include <iomanip>
#include <sstream>

ContaOrdem::ContaOrdem(const std::string& numeroConta, const std::string& pin)
    : Conta(numeroConta, pin) {}

bool ContaOrdem::depositar(double valor) {
    if (valor <= 0) {
        return false;
    }
    setSaldo(getSaldo() + valor);
    registarTransacao(TipoTransacao::TipoOperacao::DEPOSITAR, valor, "Deposito");
    return true;
}

bool ContaOrdem::levantar(double valor) {
    if (valor <= 0) {

        return false;
    }
    if (valor > getSaldo()) {

        return false;
    }
    setSaldo(getSaldo() - valor);
    registarTransacao(TipoTransacao::TipoOperacao::LEVANTAR, -valor, "Levantamento");
    return true;
}

bool ContaOrdem::transferir(ContaOrdem& contaDestino, double valor) {
    if (valor <= 0) {
        return false;
    }
    if (contaDestino.getNumeroConta() == this->getNumeroConta()) {
        return false;
    }
    if (valor > getSaldo()) {

        return false;
    }

    setSaldo(getSaldo() - valor);
    contaDestino.setSaldo(contaDestino.getSaldo() + valor);

    std::ostringstream descSaida, descEntrada;
    descSaida   << "Transf. saida -> "   << contaDestino.getNumeroConta()
                << " - " << std::fixed << std::setprecision(2) << valor << "EUR";
    descEntrada << "Transf. entrada <- " << this->getNumeroConta()
                << " - " << std::fixed << std::setprecision(2) << valor << "EUR";

    registarTransacao(TipoTransacao::TipoOperacao::TRANSFERIR, -valor, descSaida.str());
    contaDestino.registarTransacao(TipoTransacao::TipoOperacao::TRANSFERIR, valor, descEntrada.str());


    return true;
}

void ContaOrdem::adicionarContaPoupanca(const std::string& pin) {
    std::string numPoupanca = gerarNumeroPoupanca();
    contasPoupanca.push_back(std::make_shared<ContaPoupanca>(numPoupanca, pin));

}


ContaPoupanca* ContaOrdem::getContaPoupanca(size_t indice) {
    if (indice < contasPoupanca.size())
        return contasPoupanca[indice].get();
    return nullptr;
}

size_t ContaOrdem::numContasPoupanca() const {
    return contasPoupanca.size();
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

void ContaOrdem::adicionarHistoricoCarregado(const std::string& data, const std::string& descricao, double valor) {
    Transacoes::Registo r;
    r.data      = data;
    r.descricao = descricao;
    r.valor     = valor;
    historicoExtra.push_back(r);
}

std::vector<Transacoes::Registo> ContaOrdem::getHistoricoCompleto() const {
    std::vector<Transacoes::Registo> resultado = historicoExtra;
    for (const auto& t : transacoes) {
        for (const auto& r : t.getRegistars()) {
            resultado.push_back(r);
        }
    }
    return resultado;
}



std::string ContaOrdem::mostrarInfo() const {
    std::ostringstream oss;
    oss<< " [Conta Ordem] Numero: " << getNumeroConta() << " | Saldo: " << std::fixed << std::setprecision(2) << getSaldo() << " EUR" << " | Contas Poupanca associadas: " << contasPoupanca.size() << " \n";
    return oss.str();
}

void ContaOrdem::registarTransacao(TipoTransacao::TipoOperacao op, double valor, const std::string& descricao) {
    transacoes.emplace_back(op, valor, descricao);
}

std::string ContaOrdem::gerarNumeroPoupanca() const {
    return "P" + getNumeroConta().substr(1) + std::to_string(contasPoupanca.size() + 1);
}
