#ifndef VIEWPRINCIPAL_H
#define VIEWPRINCIPAL_H

#include "controller/ClienteController.h"
#include "view/ViewCliente.h"

class ViewPrincipal {
public:
    ViewPrincipal(ClienteController& clienteController, ViewCliente& viewCliente);

    void iniciar(const std::string& nomeGestor);

private:
    ClienteController& clienteController;
    ViewCliente& viewCliente;

    void opcaoRegistar();
    void opcaoLogin();
};

#endif // VIEWPRINCIPAL_H