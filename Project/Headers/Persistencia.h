#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "GestorSistemaBancario.h"
#include <string>

class Persistencia {
public:
    static void guardar(const GestorSistemaBancario& gestor, const std::string& ficheiro);
    static void carregar(GestorSistemaBancario& gestor, const std::string& ficheiro);
};

#endif // PERSISTENCIA_H
