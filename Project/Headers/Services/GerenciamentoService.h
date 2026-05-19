#indef GERENCIAMENTOSERVICE_H
#define GERENCIAMENTOSERVICE_H

#include "Cliente.h"

class GerenciamentoService {
public:
    GerenciamentoService();

    void atualizar(Cliente*cliente);

    Gernciamento* obterGerenciamento(Cliente*cliente);
};

#endif //GERENCIAMENTOSERVICE_H
