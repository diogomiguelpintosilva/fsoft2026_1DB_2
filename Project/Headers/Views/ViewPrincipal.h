#ifndef VIEWPRINCIPAL_H
#define VIEWPRINCIPAL_H

#include "ClienteController.h"
#include "ViewCliente.h"
#include "ViewGestor.h"

class ViewPrincipal {
public:
    ViewPrincipal(ClienteController& clienteController, ViewCliente& viewCliente, ViewGestor& viewGestor);

    void iniciar(const std::string& nomeGestor);

private:
    ClienteController& clienteController;
    ViewCliente& viewCliente;
    ViewGestor& viewGestor;

    void opcaoRegistar();
    void opcaoLogin();
    void opcaoGestor();
};

#endif // VIEWPRINCIPAL_H
