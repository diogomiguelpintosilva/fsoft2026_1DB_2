#ifndef CLIENTESERVICE_H
#define CLIENTESERVICE_H

#include "GestorSistemaBancario.h"
#include <string>

class ClienteService {
public:

    ClienteService(GestorSistemaBancario& gestor);

    bool registarCliente(const std::string& nome,
                         const std::string& nif,
                         const std::string& password);

    Cliente* autenticarCliente(const std::string& nif,
                               const std::string& password);


    Cliente* buscarPorNif(const std::string& nif);

private:

    GestorSistemaBancario& gestor;
};

#endif // CLIENTESERVICE_H