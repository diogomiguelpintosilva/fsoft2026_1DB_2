#ifndef TIPOTRANSACAO_H
#define TIPOTRANSACAO_H

#include "Transacoes.h"
#include <string>

class TipoTransacao : public Transacoes {
public:

    enum class TipoOperacao {
        DEPOSITAR,
        LEVANTAR,
        TRANSFERIR
    };

    TipoTransacao(TipoOperacao operacao, double valor, const std::string& descricao = "");

    TipoOperacao getOperacao() const;

    std::string getOperacaoString() const;

    void adicionarAoHistorico() override;

private:
    TipoOperacao operacao;
};

#endif // TIPOTRANSACAO_H
