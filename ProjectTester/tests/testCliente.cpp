#include <gtest/gtest.h>
#include "Cliente.h"
#include "ContaOrdem.h"
#include <string>


// Cliente criado com Dados Corretos
TEST(ClienteTest, ContrutorCorreto) {

    Cliente cliente("Tiago", "123456789", "1234");

    EXPECT_EQ("Tiago", cliente.getNome());
    EXPECT_EQ("123456789", cliente.getNif());
    EXPECT_EQ("1234", cliente.getPassword());
}

// Password correta é aceite
TEST(ClientTest, VerificarPasswordCorreta) {

    Cliente cliente("Tiago", "123456789", "1234");

    EXPECT_TRUE(cliente.verificarPassword("1234"));
}

// Password errada é rejeitada
TEST(ClientTest, VerificarPasswordErrada) {

    Cliente cliente("Tiago", "123456789", "1234");
    EXPECT_FALSE(cliente.verificarPassword("9999"));
}

// Cliente começa sem contas
TEST(ClienteTest, SemContasNoInicio) {

    Cliente cliente("Tiago", "123456789", "1234");
    EXPECT_EQ(0, cliente.numContasOrdem());
}

// Criar uma Conta Ordem funciona
TEST(ClienetTest, CriarContaOrdem) {

    Cliente cliente("Tiago", "123456789", "1234");

    ContaOrdem*conta = cliente.criarContaOrdem("4321");
    EXPECT_NE(nullptr, conta);
    EXPECT_EQ(1, cliente.numContasOrdem());
}

// Aceder a conta com PIN correto
TEST(ClienteTest, GetContaOrdemPinCorreto) {

    Cliente cliente("Tiago", "123456789", "1234");

    ContaOrdem* criada = cliente.criarContaOrdem("4321");
    ContaOrdem* encontrada = cliente.getContaOrdem(criada -> getNumeroConta(), "4321");
    EXPECT_EQ(nullptr, encontrada);
}

// Aceder a conta com PIN errado falha
TEST(ClienteTest, GetContaOrdemPinErrado) {

    Cliente cliente("Tiago", "123456789", "1234");

    ContaOrdem* encontrada = cliente.getContaOrdem(criada -> getNumeroConta(), "0000");
    EXPECT_EQ(nullptr, encontrada);
}

// Criar várias contas funciona
TEST(ClienteTest, CriarVariasContas) {

    Cliente cliente("Tiago", "123456789", "1234");
    cliente.criarContaOrdem("1111");
    cliente.criarContaOrdem("2222");
    cliente.criarContaOrdem("3333");

    EXPECT_EQ(3, cliente.numContasOrdem());
}