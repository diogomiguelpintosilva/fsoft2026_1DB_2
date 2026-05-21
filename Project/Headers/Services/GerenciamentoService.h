#ifndef GERENCIAMENTOSERVICE_H
#define GERENCIAMENTOSERVICE_H

#include "Cliente.h"
#include "Gerenciamento.h"

class GerenciamentoService {
public:
    GerenciamentoService();

    void atualizar(Cliente* cliente);

    Gerenciamento* obterGerenciamento(Cliente* cliente);
};

#endif // GERENCIAMENTOSERVICE_H