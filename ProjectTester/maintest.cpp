#include <gtest/gtest.h>
#include "tests/testCliente.cpp"
#include "tests/testContaOrdem.cpp"
#include "tests/testContaPoupanca.cpp"
#include "tests/testGestor.cpp"
#include "tests/testGerenciamento.cpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}