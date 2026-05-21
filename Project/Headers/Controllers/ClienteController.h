#ifndef CLIENTECONTROLLER_H
#define CLIENTECONTROLLER_H

#include "service/ClienteService.h"
#include <string>

class ClienteController {
public:
    ClienteController(ClienteService& clienteService);

    bool registar(const std::string& nome, const std::string& nif, const std::string& password);

    Cliente* autenticar(const std::string& nif, const std::string& password);

    Cliente* buscarPorNif(const std::string& nif);

private:
    ClienteService& clienteService;
};

#endif // CLIENTECONTROLLER_H