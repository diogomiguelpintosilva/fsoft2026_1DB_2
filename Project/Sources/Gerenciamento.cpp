#include "Gerenciamento.h"
#include "ContaOrdem.h"
#include <iostream>
#include <iomanip>

Gerenciamento::Gerenciamento()
    : despesas(0.0), ganhos(0.0), lucros(0.0) {}

void Gerenciamento::atualizar(const ContaOrdem& conta) {
    despesas = 0.0;
    ganhos   = 0.0;

    for (const auto& registo : conta.getRegistosHistorico()) {
        double valor = registo.second;
        if (valor > 0) {
            ganhos += valor;
        } else {
            despesas += (-valor);
        }
    }
    lucros = ganhos - despesas;
}

double Gerenciamento::getDespesas() const { return despesas; }
double Gerenciamento::getGanhos()   const { return ganhos; }
double Gerenciamento::getLucros()   const { return lucros; }

void Gerenciamento::mostrarResumo() const {
    std::cout << "\n - Gerenciamento Financeiro -\n";
    std::cout << "Ganhos :   " << std::fixed << std::setprecision(2) << ganhos   << " EUR\n";
    std::cout << "Despesas : " << std::fixed << std::setprecision(2) << despesas << " EUR\n";
    std::cout << "Lucros :   " << std::fixed << std::setprecision(2) << lucros   << " EUR\n";
}