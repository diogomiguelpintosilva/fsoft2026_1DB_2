#include "ClienteService.h"

ClienteService::ClienteService(GestorSistemaBancario& gestor) : gestor(gestor) {}

bool ClienteService::registarCliente(const std::string& nome, const std::string& nif, const std::string& password) {
    if (gestor.existeNif(nif)) {
        return false;
    }
    gestor.registarCliente(nome, nif, password);
    return true;
}

Cliente* ClienteService::autenticarCliente(const std::string& nif, const std::string& password) {
    return gestor.autenticarCliente(nif, password);

}

Cliente* ClienteService::buscarPorNif(const std::string& nif) {
    return gestor.buscarClientePorNif(nif);
}
