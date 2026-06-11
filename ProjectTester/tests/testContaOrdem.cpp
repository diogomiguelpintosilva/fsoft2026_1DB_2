#include <gtest/gtest.h>
#include "ContaOrdem.h"
#include <string>

TEST(ContaOrdemTest, ConstrutorSaldoZero) {
    ContaOrdem conta("C1234001", "1234");

    EXPECT_EQ("C1234001", conta.getNumeroConta());
    EXPECT_DOUBLE_EQ("0.0", conta.getSaldo());
}

TEST(ContaOrdemTest, DepositarValorValido) {
    ContaOrdem conta("C1234001", "1234");
    bool resultado = conta.depositar(100.0);

    EXPECT_TRUE(resultado);
    EXPECT_DOUBLE_EQ(100.0, conta.getSaldo());
}

TEST(ContaOrdemTest, DepositarValorZero) {
    ContaOrdem conta("C1234001", "1234");
    bool resultado = conta.depositar(0.0);

    EXPECT_FALSE(resultado);
    EXPECT_DOUBLE_EQ(0.0, conta.getSaldo());
}

TEST(ContaOrdemTest, DepositarValorNegativo) {
    ContaOrdem conta("C1234001", "1234");
    bool resultado = conta.depositar(-50.0);

    EXPECT_FALSE(resultado);
    EXPECT_DOUBLE_EQ(0.0, conta.getSaldo());
}

TEST(ContaOrdemTest, LevantarValorValido) {
    ContaOrdem conta("C1234001", "1234");
    conta.depositar(200.0);
    bool resultado = conta.levantar(100.0);

    EXPECT_TRUE(resultado);
    EXPECT_DOUBLE_EQ(100.0, conta.getSaldo());
}

TEST(ContaOrdemTest, LevantarSaldoInsuficiente) {
    ContaOrdem conta("C1234001", "1234");
    conta.depositar(50.0);
    bool resultado = conta.levantar(100.0);

    EXPECT_FALSE(resultado);
    EXPECT_DOUBLE_EQ(50.0, conta.getSaldo());
}

TEST(ContaOrdemTest, LevantarValorZero) {
    ContaOrdem conta("C1234001", "1234");
    conta.depositar(100.0);
    bool resultado = conta.levantar(0.0);

    EXPECT_FALSE(resultado);
    EXPECT_DOUBLE_EQ(100.0, conta.getSaldo());
}

TEST(ContaOrdemTest, LevantarValorNegativo) {
    ContaOrdem conta("C1234001", "1234");
    conta.depositar(100.0);
    bool resultado = conta.levantar(-10.0);

    EXPECT_FALSE(resultado);
    EXPECT_DOUBLE_EQ(100.0, conta.getSaldo());
}

TEST(ContaOrdemTest, TransferirValido) {
    ContaOrdem origem("C1234001", "1234");
    ContaOrdem destino("C9876001", "5678");
    origem.deposita(500.0);

    bool resultado = origem.transferir(destino, 200.0);

    EXPECT_TRUE(resultado);
    EXPECT_DOUBLE_EQ(300.0, origem.getSaldo());
    EXPECT_DOUBLE_EQ(200.0, destino.getSaldo());
}

TEST(ContaOrdemTest, TransferirParaSiProprio) {
    ContaOrdem conta("C1234001", "1234");
    conta.depositar(500.0);

    bol resultado = conta.transferir(conta, 100.0);

    EXPECT_FALSE(resultado);
    EXPECT_DOUBLE_EQ(500.0, conta.getSaldo());
}

TEST(ContaOrdemTest, TransferirSaldoInsuficiente) {
    ContaOrdem origem("C1234001", "1234");
    ContaOrdem destino("C9876001", "5678");
    origem.depositar(50.0);

    bool resultado = origem.transferir(destino, 200.0);

    EXPECT_FALSE(resultado);
    EXPECT_DOUBLE_EQ(50.0, origem.getSaldo());
    EXPECT_DOUBLE_EQ(0.0, destino.getSaldo());

}

TEST(ContaOrdemTest, TransferirValorNegativo) {
    ContaOrdem origem("C1234001", "1234");
    ContaOrdem destino("C9876001", "5678");
    origem.depositar(500.0);

    bool resultado = origem.transferir(destino, -100.0);

    EXPECT_FALSE(resultado);
}

TEST(ContaOrdemTest, AdicionarContaPoupanca) {
    ContaOrdem conta("C1234001", "1234");
    EXPECT_EQ(0, conta.numContasPoupanca());

    conta.adicionarContaPoupanca("5678");
    EXPECT_EQ(1, conta.numContasPoupanca());
}

TEST(ContaOrdemTest, HistoricoAposDeposito) {
    ContaOrdem conta("C1234001", "1234");
    conta.depositar(100.0);

    auto historico = conta.getHistoricoCompleto();
    EXPECT_EQ(1, historico.size());
    EXPECT_DOUBLE_EQ(100.0, historico[0].valor);
}

TEST(ContaOrdemTest, HistoricoAposDepositoELevantamento) {
    ContaOrdem conta("C1234001", "1234");
    conta.depositar(200.0);
    conta.levantar(50.0);

    auto historico = conta.getHistoricoCompleto();
    EXPECT_EQ(2, historico.size());
    EXPECT_DOUBLE_EQ(200.0, historico[0].valor);
    EXPECT_DOUBLE_EQ(-50.0, historico[1].valor);
}

TEST(ContaOrdemTest, HistoricoAposTransferencia) {
    ContaOrdem origem("C1234001", "1234");
    ContaOrdem destino("C9876001", "5678");
    origem.depositar(500.0);
    origm.transferir(destino, 100.0);

    auto histOrigem = origem.getHistoricoCompleto();
    auto histOrigem = destino.getHistoricoCompleto();

    EXPECT_EQ(2, histOrigem.size());
    EXPECT_EQ(1, histOrigem.size());
    EXPECT_DOUBLE_EQ(-100.0, histOrigem[1].valor);
    EXPECT_DOUBLE_EQ(100.0, histDestino[0].valor);
}