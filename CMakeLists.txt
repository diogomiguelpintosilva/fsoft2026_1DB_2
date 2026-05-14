cmake_minimum_required(VERSION 4.1)
project(ProjetoFSOFT)

set(CMAKE_CXX_STANDARD 26)

add_executable(ProjetoFSOFT main.cpp
        Transacoes/Transacoes.h
        "Conta/Tipos de Conta/ContaPoupanca.h"
        "Conta/ContaOrdem.h"
        Conta/Conta.h
        Gerenciamento/Gerenciamento.h
        GestorSistemaBancario.h
        Transacoes/Transacoes.cpp
        Conta/Conta.cpp
        "Conta/Tipos de Conta/ContaPoupanca.cpp"
        "Conta/ContaOrdem.cpp"
        Gerenciamento/Gerenciamento.cpp
        GestorSistemaBancario.cpp
        Transacoes/TipoTransacao.h
        Transacoes/TipoTransacao.cpp)
