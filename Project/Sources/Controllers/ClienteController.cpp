#include "ClienteController.h"

ClienteController::ClienteController(ClienteService& clienteService)
    : clienteService(clienteService) {}

bool ClienteController::registar(const std::string& nome, const std::string& nif, const std::string& password) {
    return clienteService.registarCliente(nome, nif, password);
}

Cliente* ClienteController::autenticar(const std::string& nif,
                                        const std::string& password) {
    return clienteService.autenticarCliente(nif, password);
}

Cliente* ClienteController::buscarPorNif(const std::string& nif) {
    return clienteService.buscarPorNif(nif);
}
