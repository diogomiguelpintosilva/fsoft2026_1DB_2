#include <gtest/gtest.h>
#include "ContaPoupanca.h"
#include <string>


TEST(ContaPoupancaTest, ConstrutorSaldoZero) {

    ContaPoupanca cp("P1234001", "5678");

    EXPECT_EQ("P1234001", cp.getNumeroConta());
    EXPECT_DOUBLE_EQ(0.0, cp.getSaldo());
}

TEST(ContaPoupancaTest, DepositarValorValido) {

    ContaPoupanca cp("P1234001", "5678");
    bool resultado = cp.depositar(150.0);

    EXPECT_TRUE(resultado);
    EXPECT_DOUBLE_EQ(150.0, cp.getSaldo());
}

TEST(ContaPoupancaTest, DepositarValorZero) {

    ContaPoupanca cp("P1234001", "5678");
    bool resultado = cp.depositar(0.0);

    EXPECT_FALSE(resultado);
    EXPECT_DOUBLE_EQ(0.0, cp.getSaldo());
}

TEST(ContaPoupancaTest, DepositarValorNegativo) {

    ContaPoupanca cp("P1234001", "5678");
    bool resultado = cp.depositar(-100.0);

    EXPECT_FALSE(resultado);
    EXPECT_DOUBLE_EQ(0.0, cp.getSaldo());
}

TEST(ContaPoupancaTest, VerificarPinCorreto) {

    ContaPoupanca cp("P1234001", "5678");
    EXPECT_TRUE(cp.verificarPin("5678"));
}

TEST(ContaPoupancaTest, VerificarPinErrado) {

    ContaPoupanca cp("P1234001", "5678");
    EXPECT_FALSE(cp.verificarPin("0000"));
}

TEST(ContaPoupancaTest, MostrarInfoContemNumero) {

    ContaPoupanca cp("P1234001", "5678");

    std:: string info = cp.mostrarInfo();

    EXPECT_FALSE(info.empty());
    EXPECT_NE(std::string::npos, info.find("P1234001"));
}