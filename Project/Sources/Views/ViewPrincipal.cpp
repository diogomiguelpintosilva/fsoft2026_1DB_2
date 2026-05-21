#include "ViewPrincipal.h"
#include "ViewUtils.h"
#include <iostream>

ViewPrincipal::ViewPrincipal(ClienteController& clienteController, ViewCliente& viewCliente, ViewGestor& viewGestor)
    : clienteController(clienteController), viewCliente(viewCliente), viewGestor(viewGestor) {}

void ViewPrincipal::iniciar(const std::string& nomeGestor) {
    cabecalho("Bem-vindo ao " + nomeGestor);

    int opcao;
    do {
        std::cout << "\n  1. Registar novo cliente\n";
        std::cout << "  2. Iniciar sessao\n";
        std::cout << "  3. Area do Gestor\n";
        std::cout << "  0. Sair\n";
        std::cout << "  Opcao: ";
        std::cin >> opcao;
        limparInput();

        switch (opcao) {
            case 1: opcaoRegistar(); break;
            case 2: opcaoLogin();    break;
            case 3: opcaoGestor();   break;
            case 0: std::cout << "\n  Ate breve!\n\n"; break;
            default: std::cout << "  Opcao invalida.\n"; break;
        }
    } while (opcao != 0);
}

void ViewPrincipal::opcaoRegistar() {
    std::string nome, nif, password;
    std::cout << "  Nome: ";
    std::getline(std::cin, nome);
    std::cout << "  NIF: ";
    std::getline(std::cin, nif);
    std::cout << "  Password: ";
    std::getline(std::cin, password);

    clienteController.registar(nome, nif, password);
    pausar();
}

void ViewPrincipal::opcaoGestor() {
    viewGestor.entrar();
}

void ViewPrincipal::opcaoLogin() {
    std::string nif, password;
    std::cout << "  NIF: ";
    std::getline(std::cin, nif);
    std::cout << "  Password: ";
    std::getline(std::cin, password);

    Cliente* cliente = clienteController.autenticar(nif, password);
    if (cliente != nullptr) {
        viewCliente.mostrarMenu(cliente);
    } else {
        pausar();
    }
}
