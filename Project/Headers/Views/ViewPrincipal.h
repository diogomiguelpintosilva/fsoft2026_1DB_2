#indef VIEWPRINCIPAL_H
#define VIEWPRINCIPAL_H

#include "controller/ClienteController.h"
#include "view/ViewCliente.h"

class ViewPrincipal {
public:
    ViewPrincipal(ClienteController& clienteController, ViewCliente& viewCliente);
private:
    ViewCliente& viewCliente;
    ClienteController& clienteController;

    void opcaoRegistar();
    void opcaoLogin();
};

#endif