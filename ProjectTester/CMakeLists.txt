cmake_minimum_required(VERSION 3.14)
project(fsoft2026_1DB_2_Tests)

set(CMAKE_CXX_STANDARD 14)

# Caminho para o codigo da aplicacao (pasta Project)
set(BANCO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../Project)

include_directories(${BANCO_DIR}/Headers)

# ----- Google Test -----
set(GOOGLE_TEST_LIB ${CMAKE_CURRENT_SOURCE_DIR}/googleTestLib/googletest-main)
set(GOOGLE_TEST_LIB_INCLUDE ${GOOGLE_TEST_LIB}/googletest/include)

add_subdirectory(${GOOGLE_TEST_LIB})
include_directories(${GOOGLE_TEST_LIB_INCLUDE})

add_executable(fsoft2026_1DB_2_Tests
        maintest.cpp

        ${BANCO_DIR}/Headers/GestorSistemaBancario.h
        ${BANCO_DIR}/Sources/GestorSistemaBancario.cpp

        ${BANCO_DIR}/Headers/Conta.h
        ${BANCO_DIR}/Sources/Conta.cpp

        ${BANCO_DIR}/Headers/ContaOrdem.h
        ${BANCO_DIR}/Sources/ContaOrdem.cpp

        ${BANCO_DIR}/Headers/Cliente.h
        ${BANCO_DIR}/Sources/Cliente.cpp

        ${BANCO_DIR}/Headers/ContaPoupanca.h
        ${BANCO_DIR}/Sources/ContaPoupanca.cpp

        ${BANCO_DIR}/Headers/TipoTransacao.h
        ${BANCO_DIR}/Sources/TipoTransacao.cpp

        ${BANCO_DIR}/Headers/Transacoes.h
        ${BANCO_DIR}/Sources/Transacoes.cpp

        ${BANCO_DIR}/Headers/Gerenciamento.h
        ${BANCO_DIR}/Sources/Gerenciamento.cpp
)
target_link_libraries(fsoft2026_1DB_2_Tests gtest gtest_main)