#include "TipoTransacao.h"
#include <iostream>

TipoTransacao::TipoTransacao(TipoOperacao operacao, double valor, const std::string& descricao)
    : operacao(operacao) {
    std::string desc = descricao.empty() ? getOperacaoString() : descricao;
    registar(desc, valor);
}

TipoTransacao::TipoOperacao TipoTransacao::getOperacao() const {
    return operacao;
}

std::string TipoTransacao::getOperacaoString() const {
    switch (operacao) {
        case TipoOperacao::DEPOSITAR:  return "Depositar";
        case TipoOperacao::LEVANTAR:   return "Levantar";
        case TipoOperacao::TRANSFERIR: return "Transferir";
        default:                       return "Desconhecido";
    }
}

void TipoTransacao::adicionarAoHistorico() {
    // implementado via registar() no construtor
}
