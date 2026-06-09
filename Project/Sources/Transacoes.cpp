#include "Transacoes.h"
#include <iomanip>
#include <sstream>
#include <ctime>

Transacoes::Transacoes() {}

void Transacoes::registar(const std::string& descricao, double valor) {
    Registo r;
    r.descricao = descricao;
    r.valor = valor;
    r.data = dataAtual();
    historico.push_back(r);
}

const std::vector<Transacoes::Registo>& Transacoes::getHistorico() const {
    return historico;
}

const std::vector<Transacoes::Registo>& Transacoes::getRegistars() const {
    return historico;
}

std::string Transacoes::mostrarHistorico() const {
    std::ostringstream oss;
    if (historico.empty()) {
        oss << "  Sem registos no historico.\n";
        return oss.str();
    }
    oss << std::left
        << std::setw(12) << "Data"
        << std::setw(25) << "Descricao"
        << std::setw(12) << "Valor (EUR)" << "\n";
    oss << std::string(49, '-') << "\n";
    for (const auto& r : historico) {
        oss << std::left
            << std::setw(12) << r.data
            << std::setw(25) << r.descricao
            << std::fixed << std::setprecision(2) << r.valor << "\n";
    }
    return oss.str();
}

std::string Transacoes::dataAtual() {
    std::time_t t = std::time(nullptr);
    std::tm* tm_info = std::localtime(&t);
    char buf[11];
    std::strftime(buf, sizeof(buf), "%d/%m/%Y", tm_info);
    return std::string(buf);
}
