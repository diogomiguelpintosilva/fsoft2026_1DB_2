#ifndef VIEWGESTOR_H
#define VIEWGESTOR_H

#include "GestorSistemaBancario.h"
#include <string>

class ViewGestor {
public:
    explicit ViewGestor(GestorSistemaBancario& gestor);

    void entrar();

private:
    GestorSistemaBancario& gestor;

    static const std::string PASSWORD_GESTOR;

    void mostrarMenu();
    void opcaoListarClientes();
    void opcaoVerContasCliente();
};

#endif // VIEWGESTOR_H
