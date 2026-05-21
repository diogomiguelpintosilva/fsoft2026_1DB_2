#ifndef GERENCIAMENTOCONTROLLER_H
#define GERENCIAMENTOCONTROLLER_H

#include "GerenciamentoService.h"
#include "Gerenciamento.h"

class GerenciamentoController {
public:
    GerenciamentoController(GerenciamentoService& gerenciamentoService);

    Gerenciamento* obter(Cliente* cliente);

private:
    GerenciamentoService& gerenciamentoService;
};

#endif // GERENCIAMENTOCONTROLLER_H