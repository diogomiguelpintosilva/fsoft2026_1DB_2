#ifndef CLIENTE_H
#define CLIENTE_H

#include "ContaOrdem.h"
#include "Gerenciamento.h"
#include <string>
#include <vector>
#include <memory>

class Cliente {
public:
    Cliente(const std::string& nome, const std::string& nif, const std::string& password);

    const std::string& getNome() const;
    const std::string& getNif() const;
    const std::string& getPassword() const;

    bool verificarPassword(const std::string& password) const;

    ContaOrdem* criarContaOrdem(const std::string& pin);
    ContaOrdem* getContaOrdem(const std::string& numeroConta, const std::string& pin);
    ContaOrdem* getContaOrdemPorNumero(const std::string& numeroConta);
    ContaOrdem* getContaOrdemPorIndice(size_t i);
    size_t numContasOrdem() const;
    ContaOrdem* adicionarContaOrdemCarregada(const std::string&numero, const std::string& pin, double saldo);

    Gerenciamento& getGerenciamento();
    void atualizarGerenciamento();

    std::string mostrarInfo() const;


private:
    std::string nome;
    std::string nif;
    std::string password;

    std::vector<std::shared_ptr<ContaOrdem>> contasOrdem;

    Gerenciamento gerenciamento;

    std::string gerarNumeroConta() const;
};

#endif // CLIENTE_H
