#include "view/ViewPrincipal.h"
#include "view/ViewUtils.h"
#include <iostream>

ViewPrincipal::ViewPrincipal(ClienteController& clienteController, ViewCliente& viewCliente: clienteController(clienteController), viewCliente(viewCliente)){}

void ViewPrincipal::iniciar(const std::string& nomeGestor) {
    cabecalho("Bem-vindo ao" +nomeGestor);

    int opcao;
    do {
        std cout<< "\n 1. Registar novo cliente\n";
        std cout<< "\n 2. Iniciar sessão\n";
        std cout<< "\n 0. Sair\n";
        std cout<< "\n Opcao: ";
        std::cin>>opcao;
        limparInput();

        switch (opcao) {
            case 1: opçaoRegistar(); break;
            case 2: opcaoLogin(); break;
            case 0: std::cout<<"\n Até breve!\n\n";break;
            default: std::cout<<"Opcao invalida.\n";break;
        }
    }while(opcao!=0);
}

void ViewPrincipal::opcaoRegistar() {
    std::string nome, nif, password;
    std::cout<<"Nome: ";
    std::getline(std::cin,nome);
    std::cout<<"Nif: ";
    std::getline(std::cin,nif);
    std::cout<<"Password: ";
    std::getline(std::cin,password);

    clienteController.registar(nome, nif, password);
    pausar();
}

void ViewPrincipal::opcaoLogin() {
    std::string nif,password;
    std::cout<<"NIF: ";
    std::getline(std::cin,nif);
    std::cout<<"Password: ";
    std::getline(std::cin,password);

    Cliente* cliente = clienteController.autenticar(nif, password);
    if (cliente != nullptr) {
        viewCliente.mostrarMenu(cliente);
    } else {
        pausar();
    }
}