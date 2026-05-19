#include "GestorSistemaBancario.h"
#include <iostream>
#include <algorithm>

GestorSistemaBancario::GestorSistemaBancario(const std::string& nome)
    : nome(nome) {}

const std::string& GestorSistemaBancario::getNome() const {
    return nome;
}

Cliente* GestorSistemaBancario::registarCliente(const std::string& nome,
                                                const std::string& nif,
                                                const std::string& password) {
    if (existeNif(nif)) {
        std::cout << "  [ERRO] Ja existe um cliente com o NIF " << nif << ".\n";
        return nullptr;
    }
    clientes.push_back(std::make_shared<Cliente>(nome, nif, password));
    std::cout << "  Cliente registado com sucesso.\n";
    return clientes.back().get();
}

Cliente* GestorSistemaBancario::autenticarCliente(const std::string& nif,
                                                  const std::string& password) {
    for (auto& c : clientes) {
        if (c->getNif() == nif && c->verificarPassword(password))
            return c.get();
    }
    return nullptr;
}

Cliente* GestorSistemaBancario::buscarClientePorNif(const std::string& nif) {
    for (auto& c : clientes) {
        if (c->getNif() == nif)
            return c.get();
    }
    return nullptr;
}

bool GestorSistemaBancario::existeNif(const std::string& nif) const {
    for (const auto& c : clientes) {
        if (c->getNif() == nif)
            return true;
    }
    return false;
}

void GestorSistemaBancario::listarClientes() const {
    if (clientes.empty()) {
        std::cout << "  Sem clientes registados.\n";
        return;
    }
    for (const auto& c : clientes)
        c->mostrarInfo();
}