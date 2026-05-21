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

    bool verificarPassword(const std::string& password) const;

    ContaOrdem* criarContaOrdem(const std::string& pin);
    ContaOrdem* getContaOrdem(const std::string& numeroConta, const std::string& pin);
    ContaOrdem* getContaOrdemPorNumero(const std::string& numeroConta);
    size_t numContasOrdem() const;
    void listarContas();

    Gerenciamento& getGerenciamento();
    void atualizarGerenciamento();

    void mostrarInfo() const;

private:
    std::string nome;
    std::string nif;
    std::string password;

    std::vector<std::shared_ptr<ContaOrdem>> contasOrdem;

    Gerenciamento gerenciamento;

    std::string gerarNumeroConta() const;
};

#endif // CLIENTE_H
