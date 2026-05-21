#ifndef GESTORSISTEMABANCARIO_H
#define GESTORSISTEMABANCARIO_H

#include "Cliente.h"
#include <string>
#include <vector>
#include <memory>


class GestorSistemaBancario {
public:
    explicit GestorSistemaBancario(const std::string& nome);

    const std::string& getNome() const;

    Cliente* registarCliente(const std::string& nome, const std::string& nif, const std::string& password);
    Cliente* autenticarCliente(const std::string& nif, const std::string& password);
    Cliente* buscarClientePorNif(const std::string& nif);
    bool existeNif(const std::string& nif) const;

    void listarClientes() const;

private:
    std::string nome;


    std::vector<std::shared_ptr<Cliente>> clientes;
};

#endif // GESTORSISTEMABANCARIO_H
