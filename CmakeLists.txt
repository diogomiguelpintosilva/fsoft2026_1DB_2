cmake_minimum_required(VERSION 4.1)
project(fsoft2026_1DB_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Documentation)
include_directories(Project)
include_directories(ProjectTester)
include_directories(ProjetoFSOFT)
include_directories(ProjetoFSOFT/Conta)
include_directories(ProjetoFSOFT/Gerenciamento)
include_directories(ProjetoFSOFT/Transacoes)

add_executable(fsoft2026_1DB_2
        Documentation/Iteration01/Análise_requerimentos.pdf
        "Documentation/Iteration01/Diagramas de sequência.pdf"
        "Documentation/Iteration01/Domain Diagram_FSOFT.pdf"
        "Documentation/Iteration01/Relatório Técnico para a incrementação do Sistema Bancário.pdf"
        Documentation/Iteration02/iteration02
        "Documentation/Iteration02/Novo Diagrama de Domínio.pdf"
        Documentation/Iteration03/iteration03
        "Project/project code"
        "ProjectTester/project tester code"
        ProjetoFSOFT/cmake-build-debug/Testing/Temporary/LastTest.log
        ProjetoFSOFT/cmake-build-debug/build.ninja
        ProjetoFSOFT/cmake-build-debug/cmake_install.cmake
        ProjetoFSOFT/cmake-build-debug/CMakeCache.txt
        ProjetoFSOFT/cmake-build-debug/compile_commands.json
        ProjetoFSOFT/Conta/Conta.cpp
        ProjetoFSOFT/Conta/Conta.h
        ProjetoFSOFT/Conta/ContaOrdem.cpp
        ProjetoFSOFT/Conta/ContaOrdem.h
        ProjetoFSOFT/Conta/ContaPoupanca.cpp
        ProjetoFSOFT/Conta/ContaPoupanca.h
        ProjetoFSOFT/Gerenciamento/Gerenciamento.cpp
        ProjetoFSOFT/Gerenciamento/Gerenciamento.h
        ProjetoFSOFT/Transacoes/TipoTransacao.cpp
        ProjetoFSOFT/Transacoes/TipoTransacao.h
        ProjetoFSOFT/Transacoes/Transacoes.cpp
        ProjetoFSOFT/Transacoes/Transacoes.h
        ProjetoFSOFT/CMakeLists.txt
        ProjetoFSOFT/GestorSistemaBancario.cpp
        ProjetoFSOFT/GestorSistemaBancario.h
        ProjetoFSOFT/main.cpp
        README.md)
