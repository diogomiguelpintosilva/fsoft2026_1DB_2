#ifndef CLIENTESERVICE_H
#define CLIENTESERVICE_H

#include "GestorSistemaBancario.h"
#include <string>

// O ClienteService trata de tudo o que tem a ver com clientes:
// registar, autenticar e procurar clientes.
// Recebe o GestorSistemaBancario porque e la que os clientes ficam guardados.

class ClienteService {
public:
    // O construtor recebe o gestor para poder trabalhar com ele
    ClienteService(GestorSistemaBancario& gestor);

    // Tenta registar um novo cliente.
    // Devolve true se correu bem, false se o NIF ja existe.
    bool registarCliente(const std::string& nome,
                         const std::string& nif,
                         const std::string& password);

    // Tenta autenticar um cliente com NIF e password.
    // Devolve um ponteiro para o Cliente se as credenciais estiverem certas,
    // ou nullptr se estiverem erradas.
    Cliente* autenticarCliente(const std::string& nif,
                               const std::string& password);

    // Procura um cliente pelo NIF (sem verificar password).
    // Util para transferencias entre contas.
    Cliente* buscarPorNif(const std::string& nif);

private:
    // Referencia ao gestor onde os clientes estao guardados
    GestorSistemaBancario& gestor;
};

#endif // CLIENTESERVICE_H