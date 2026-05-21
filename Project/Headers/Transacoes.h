#ifndef TRANSACOES_H
#define TRANSACOES_H

#include <string>
#include <vector>
#include <ctime>

class Transacoes {

    public:

    struct Registo {

        std::string descricao;
        double valor;
        std::string data;
    };

    Transacoes();
    virtual ~Transacoes() = default;

    void registar(const std::string& descricao, double valor);

    const std::vector<Transacoes::Registo> &getHistorico() const;

    const std::vector<Registo>& getRegistars() const;
    void mostrarHistorico() const;

    virtual void adicionarAoHistorico() = 0;


protected:

    std::vector<Registo> historico;

    static std::string dataAtual();
};

#endif //TRANSACOES_H
