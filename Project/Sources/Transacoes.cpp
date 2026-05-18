#include "Transacoes.h"
#include <iostream>
#include <iomanip>
#include <ctime>

Transacoes::Transacoes() {}

void Transacoes::registar(const std::string& descricao, double valor) {

    Registo r;
    r.descricao = descricao;
    r.valor = valor;
    r.data = dataAtual();
    historico.push_back(r);

}


const std::vector<Transacoes::Registo>& Transacoes::getHistorico() const{

    return historico;
}


void Transacoes::mostrarHistorico() const {

    if (historico.empty()) {

        std::cout<< "Sem registos no histórico. \n";
        return;
    }

    std::cout << std::left
              << std::setw(12)<< "Data"
              << std::setw(25)<< "Descricao"
              << std::setw(12)<< "Valor (EUR)" << "\n";
    std::cout << std::string(49, '-')<< "\n";

    for (const auto& r : historico) {

        std::cout << std::left
                  << std::setw(12)<< r.data
                  << std::setw(25)<< r.descricao
                  << std::fixed<< std::setprecision(2)<< r.valor << "\n";
    }

}


std::string Transacoes::dataAtual() {

    std::time_t t = std::time(nullptr);
    std::tm* tm = std::localtime(&t);
    char buf[11];
    const struct ::tm * tm_info;
    std::strftime(buf, sizeof(buf), "%d/%m/%Y", tm_info);
    return std::string(buf);
}