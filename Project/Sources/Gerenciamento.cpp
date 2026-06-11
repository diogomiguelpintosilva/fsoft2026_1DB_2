#include "Gerenciamento.h"
#include "ContaOrdem.h"
#include <sstream>
#include <iomanip>

Gerenciamento::Gerenciamento() : despesas(0.0), ganhos(0.0), lucros(0.0) {}

void Gerenciamento::atualizar(const ContaOrdem& conta) {
    despesas = 0.0;
    ganhos   = 0.0;

    for (const auto& registo : conta.getHistoricoCompleto()) {
        if (registo.valor > 0) {
            ganhos += registo.valor;
        } else {
            despesas += (-registo.valor);
        }
    }
    lucros = ganhos - despesas;
}

double Gerenciamento::getDespesas() const { return despesas; }
double Gerenciamento::getGanhos()   const { return ganhos; }
double Gerenciamento::getLucros()   const { return lucros; }

std::string Gerenciamento::mostrarResumo() const {
    std::ostringstream oss;
    oss << "\n ----- Gerenciamento Financeiro -----\n";
    oss << "Ganhos :   " << std::fixed << std::setprecision(2) << ganhos   << " EUR\n";
    oss << "Despesas : " << std::fixed << std::setprecision(2) << despesas << " EUR\n";
    oss << "Lucros :   " << std::fixed << std::setprecision(2) << lucros   << " EUR\n";
    return oss.str();
}
