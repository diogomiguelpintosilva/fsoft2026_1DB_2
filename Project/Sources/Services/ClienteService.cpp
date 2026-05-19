#include "service/ClienteService.h"
#include <iostream>

ClienteService::ClienteService(GestorSistemaBancario& gestor)
    : gestor(gestor) {}

bool ClienteService::registarCliente(const std::string& nome,
                                     const std::string& nif,
                                     const std::string& password) {
    // Verifica se ja existe um cliente com este NIF
    if (gestor.existeNif(nif)) {
        std::cout << "  [ERRO] Ja existe um cliente com o NIF " << nif << ".\n";
        return false;
    }
    gestor.registarCliente(nome, nif, password);
    return true;
}

Cliente* ClienteService::autenticarCliente(const std::string& nif,
                                           const std::string& password) {
    // Tenta autenticar — o gestor devolve nullptr se as credenciais estiverem erradas
    Cliente* cliente = gestor.autenticarCliente(nif, password);
    if (cliente == nullptr) {
        std::cout << "  [ERRO] NIF ou password incorretos.\n";
    }
    return cliente;
}

Cliente* ClienteService::buscarPorNif(const std::string& nif) {
    return gestor.buscarClientePorNif(nif);
}