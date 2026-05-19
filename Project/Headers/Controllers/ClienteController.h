#include "service/ClienteService.h"
#include <string>

class ClienteController {
public:
    ClienteController(ClinteService* clinteService);

    bool registar(const std::string& nome, const std::string& nif, const std::string& password);

    Cliente* autenticar(const std::string& nif, const std::string& password);

    Cliente* buscarPorNIF(const std::string& nif);

private:
    ClienteService* clienteService;
}

#endif