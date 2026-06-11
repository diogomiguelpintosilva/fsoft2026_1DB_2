#include <gtest/gtest.h>
#include "Gerenciamento.h"
#include "ContaOrdem.h"
#include <string>

TEST(GerenciamentoTest, InicioZero) {
    Gerenciamento g;

    EXPECT_DOUBLE_EQ(0.0, g.getGanhos());
    EXPECT_DOUBLE_EQ(0.0, g.getDespesas());
    EXPECT_DOUBLE_EQ(0.0, g.getLucros());
}

TEST(GerenciamentoTest, AtualizarComDeposito) {
    ContaOrdem conta("C1234001", "1234");
    conta.depositar(500.0);

    Gerenciamento g;
    g.atualizar(conta);

    EXPECT_DOUBLE_EQ(500.0, g.getGanhos());
    EXPECT_DOUBLE_EQ(0.0,   g.getDespesas());
    EXPECT_DOUBLE_EQ(500.0, g.getLucros());
}

TEST(GerenciamentoTest, AtualizarComLevantamento) {
    ContaOrdem conta("C1234001", "1234");
    conta.depositar(500.0);
    conta.levantar(200.0);

    Gerenciamento g;
    g.atualizar(conta);

    EXPECT_DOUBLE_EQ(500.0, g.getGanhos());
    EXPECT_DOUBLE_EQ(200.0, g.getDespesas());
    EXPECT_DOUBLE_EQ(300.0, g.getLucros());
}

TEST(GerenciamentoTest, AtualizarComTransferenciaSaida) {
    ContaOrdem origem("C1234001", "1234");
    ContaOrdem destino("C9876001", "5678");
    origem.depositar(500.0);
    origem.transferir(destino, 100.0);

    Gerenciamento g;
    g.atualizar(origem);

    EXPECT_DOUBLE_EQ(500.0, g.getGanhos());
    EXPECT_DOUBLE_EQ(100.0, g.getDespesas());
    EXPECT_DOUBLE_EQ(400.0, g.getLucros());
}

TEST(GerenciamentoTest, AtualizarComTransferenciaEntrada) {
    ContaOrdem origem("C1234001", "1234");
    ContaOrdem destino("C9876001", "5678");
    origem.depositar(500.0);
    origem.transferir(destino, 200.0);

    Gerenciamento g;
    g.atualizar(destino);

    EXPECT_DOUBLE_EQ(200.0, g.getGanhos());
    EXPECT_DOUBLE_EQ(0.0,   g.getDespesas());
    EXPECT_DOUBLE_EQ(200.0, g.getLucros());
}

TEST(GerenciamentoTest, ResumoNaoVazio) {
    Gerenciamento g;
    std::string resumo = g.mostrarResumo();

    EXPECT_FALSE(resumo.empty());
}