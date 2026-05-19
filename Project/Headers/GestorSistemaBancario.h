#ifndef GESTORSISTEMABANCARIO_H
#define GESTORSISTEMABANCARIO_H

#include "Cliente.h"
#include <string>
#include <vector>
#include <memory>

// Entidade raiz do sistema
// Atributo: Nome
// Relacao "Contem 1 -> 1..*" com Cliente
class GestorSistemaBancario {
public:
    explicit GestorSistemaBancario(const std::string& nome);

    const std::string& getNome() const;

    // Gestao de clientes (relacao "Contem")
    Cliente* registarCliente(const std::string& nome, const std::string& nif, const std::string& password);
    Cliente* autenticarCliente(const std::string& nif, const std::string& password);
    Cliente* buscarClientePorNif(const std::string& nif);
    bool existeNif(const std::string& nif) const;

    void listarClientes() const;

private:
    std::string nome; // atributo Nome do diagrama

    // O gestor contem 1..* clientes
    std::vector<std::shared_ptr<Cliente>> clientes;
};

#endif // GESTORSISTEMABANCARIO_H