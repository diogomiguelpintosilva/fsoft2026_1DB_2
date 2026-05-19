#indef GERENCIAMENTOCONTROLLER_H
#define GERENCIAMENTOCONTROLLER_H

#include "service/GerenciamentoService.h"

class GerenciamentoController {
public:
    GerenciamentoController(GerenciamentoService& gerenciamentoService);

    Gerenciamento* obter(Cliente* cliente);

private:
    GerenciamentoService& gerenciamentoService;
};

#endif //GERENCIAMENTOCONTROLLER