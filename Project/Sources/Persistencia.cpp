#include "Persistencia.h"
#include "Cliente.h"
#include "ContaOrdem.h"
#include "ContaPoupanca.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Persistencia::guardar(const GestorSistemaBancario& gestor, const std::string& ficheiro) {
    std::ofstream f(ficheiro);
    if (!f) {
        std::cerr << "  [AVISO] Nao foi possivel guardar os dados.\n";
        return;
    }

    for (const auto& c : gestor.getClientes()) {
        f << "CLIENTE|" << c->getNome() << "|" << c->getNif() << "|" << c->getPassword() << "\n";

        for (size_t i = 0; i < c->numContasOrdem(); ++i) {
            ContaOrdem* co = c->getContaOrdemPorIndice(i);
            f << "CONTA_ORDEM|" << co->getNumeroConta() << "|" << co->getPin() << "|" << co->getSaldo() << "\n";

            for (const auto& r : co->getHistoricoCompleto()) {
                f << "HISTORICO|" << r.data << "|" << r.descricao << "|" << r.valor << "\n";
            }

            for (size_t j = 0; j < co->numContasPoupanca(); ++j) {
                ContaPoupanca* cp = co->getContaPoupanca(j);
                f << "POUPANCA|" << cp->getNumeroConta() << "|" << cp->getPin() << "|" << cp->getSaldo() << "\n";
            }

            f << "FIM_CONTA_ORDEM\n";
        }

        f << "FIM_CLIENTE\n";
    }
}

void Persistencia::carregar(GestorSistemaBancario& gestor, const std::string& ficheiro) {
    std::ifstream f(ficheiro);
    if (!f) return; // primeira vez que corre, ficheiro ainda nao existe

    std::string linha;
    Cliente*    clienteAtual = nullptr;
    ContaOrdem* contaAtual   = nullptr;

    while (std::getline(f, linha)) {
        std::istringstream ss(linha);
        std::string tipo;
        std::getline(ss, tipo, '|');

        if (tipo == "CLIENTE") {
            std::string nome, nif, password;
            std::getline(ss, nome,     '|');
            std::getline(ss, nif,      '|');
            std::getline(ss, password, '|');
            clienteAtual = gestor.adicionarClienteCarregado(nome, nif, password);
            contaAtual   = nullptr;

        } else if (tipo == "CONTA_ORDEM" && clienteAtual) {
            std::string numero, pin, saldoStr;
            std::getline(ss, numero,   '|');
            std::getline(ss, pin,      '|');
            std::getline(ss, saldoStr, '|');
            contaAtual = clienteAtual->adicionarContaOrdemCarregada(numero, pin, std::stod(saldoStr));

        } else if (tipo == "HISTORICO" && contaAtual) {
            std::string data, descricao, valorStr;
            std::getline(ss, data,      '|');
            std::getline(ss, descricao, '|');
            std::getline(ss, valorStr,  '|');
            contaAtual->adicionarHistoricoCarregado(data, descricao, std::stod(valorStr));

        } else if (tipo == "POUPANCA" && contaAtual) {
            std::string numero, pin, saldoStr;
            std::getline(ss, numero,   '|');
            std::getline(ss, pin,      '|');
            std::getline(ss, saldoStr, '|');
            contaAtual->adicionarContaPoupancaCarregada(numero, pin, std::stod(saldoStr));

        } else if (tipo == "FIM_CONTA_ORDEM") {
            contaAtual = nullptr;
        } else if (tipo == "FIM_CLIENTE") {
            clienteAtual = nullptr;
        }
    }
}

