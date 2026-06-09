#include "ViewGestor.h"
#include "ViewUtils.h"
#include <iostream>

const std::string ViewGestor::PASSWORD_GESTOR = "admin123";

ViewGestor::ViewGestor(GestorSistemaBancario& gestor) : gestor(gestor) {}

void ViewGestor::entrar() {
    std::string password;
    std::cout << "  Password do Gestor: ";
    std::getline(std::cin, password);

    if (password != PASSWORD_GESTOR) {
        std::cout << "  [ERRO] Password incorreta.\n";
        pausar();
        return;
    }

    mostrarMenu();
}

void ViewGestor::mostrarMenu() {
    int opcao;
    do {
        cabecalho("Area do Gestor");
        std::cout << "  1. Listar todos os clientes\n";
        std::cout << "  2. Ver contas de um cliente\n";
        std::cout << "  0. Sair\n";
        std::cout << "  Opcao: ";
        std::cin >> opcao;
        limparInput();

        switch (opcao) {
            case 1: opcaoListarClientes();   break;
            case 2: opcaoVerContasCliente(); break;
            case 0: std::cout << "  Saindo da area do gestor.\n"; break;
            default: std::cout << "  Opcao invalida.\n"; break;
        }
    } while (opcao != 0);
}

void ViewGestor::opcaoListarClientes() {
    cabecalho("Todos os Clientes");
    const auto& clientes = gestor.getClientes();
    if (clientes.empty()) {
        std::cout << "  Nenhum cliente registado.\n";
    } else {
        for (size_t i = 0; i < clientes.size(); ++i) {
            std::cout << "  [" << (i + 1) << "] "
                      << clientes[i]->getNome()
                      << " | NIF: " << clientes[i]->getNif()
                      << " | Contas: " << clientes[i]->numContasOrdem() << "\n";
        }
    }
    pausar();
}

void ViewGestor::opcaoVerContasCliente() {
    std::string nif;
    std::cout << "  NIF do cliente: ";
    std::getline(std::cin, nif);

    Cliente* cliente = gestor.buscarClientePorNif(nif);
    if (cliente == nullptr) {
        std::cout << "  [ERRO] Cliente nao encontrado.\n";
        pausar();
        return;
    }

    cabecalho("Contas de " + cliente->getNome());
    if (cliente->numContasOrdem() == 0) {
        std::cout << "  Sem contas criadas.\n";
    } else {
        for (size_t i = 0; i < cliente->numContasOrdem(); ++i) {
            ContaOrdem* co = cliente->getContaOrdemPorIndice(i);
            std::cout << "  [" << (i + 1) << "] " << co->mostrarInfo() << "\n";
        }
    }
    pausar();
}
