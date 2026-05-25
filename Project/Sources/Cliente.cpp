#include "Cliente.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

Cliente::Cliente(const std::string& nome, const std::string& nif, const std::string& password)
    : nome(nome), nif(nif), password(password) {}

const std::string& Cliente::getNome() const { return nome; }
const std::string& Cliente::getNif()  const { return nif; }
const std::string& Cliente::getPin()  const { return pin; }

bool Cliente::verificarPassword(const std::string& pw) const {
    return password == pw;
}

ContaOrdem* Cliente::criarContaOrdem(const std::string& pin) {
    std::string numero = gerarNumeroConta();
    contasOrdem.push_back(std::make_shared<ContaOrdem>(numero, pin));
    std::cout << "  Conta corrente criada com sucesso.\n";
    std::cout << "  Numero da conta: " << numero << "\n";
    return contasOrdem.back().get();
}

ContaOrdem* Cliente::getContaOrdem(const std::string& numeroConta, const std::string& pin) {
    for (auto& c : contasOrdem) {
        if (c->getNumeroConta() == numeroConta && c->verificarPin(pin))
            return c.get();
    }
    return nullptr;
}

ContaOrdem* Cliente::getContaOrdemPorNumero(const std::string& numeroConta) {
    for (auto& c : contasOrdem) {
        if (c->getNumeroConta() == numeroConta)
            return c.get();
    }
    return nullptr;
}

ContaOrdem* Cliente::getContaOrdemPorIndice(size_t i){
	if( i < contasOrdem.size() )
		return contasOrdem[i].get();
	return nullptr;
}

ContaOrdem* Cliente::adicionarContaOrdemCarregada(const std::string& numero, const std::string& pin, double saldo) {
	auto co = std::make_shared<ContaOrdem>(numero, pin);
	co->setSaldo(saldo);
	contasOrdem.push_back(co);
	return contasOrdem.back().get();
}

size_t Cliente::numContasOrdem() const {
    return contasOrdem.size();
}

void Cliente::listarContas() {
    if (contasOrdem.empty()) {
        std::cout << "  Sem contas registadas.\n";
        return;
    }
    for (size_t i = 0; i < contasOrdem.size(); ++i) {
        std::cout << "  [" << i + 1 << "] ";
        contasOrdem[i]->mostrarInfo();
    }
}

Gerenciamento& Cliente::getGerenciamento() {
    return gerenciamento;
}

void Cliente::atualizarGerenciamento() {
    for (auto& c : contasOrdem) {
        gerenciamento.atualizar(*c);
    }
}

void Cliente::mostrarInfo() const {
    std::cout << "  Cliente: " << nome << " | NIF: " << nif << "\n";
    std::cout << "  Contas registadas: " << contasOrdem.size() << "\n";
}

std::string Cliente::gerarNumeroConta() const {
    std::ostringstream oss;
    oss << "C" << nif.substr(0, 4) << std::setfill('0') << std::setw(3) << (contasOrdem.size() + 1);
    return oss.str();
}
