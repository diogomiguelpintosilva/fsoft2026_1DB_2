#include <gtest/gtest.h>
#include "GestorSistemaBancario.h"
#include <string>


// Registar Cliente Novo deve funcionar
TEST(GestorTest, RegistarClienteNovo) {

    GestorSistemaBancario gestor ("Banco ISEP");

    Cliente*c = gestor.registarCliente("Tiago", "123456789", "1234");

    EXPECT_NE(nullptr, c);
    EXPECT_EQ(1, gestor.getClientes().size());
}

// Registar 2 clientes com o mesmo NIF, deve falhar
TEST(GestorTest, RegistarNifDuplicado) {

    GestorSistemaBancario gestor ("Banco ISEP");

    gestor.registarCliente("Tiago", "123456789", "1234");
    Cliente*c2 = gestor.registarCliente("Ana", "123456789", "5678");

    EXPECT_EQ(nullptr, c2);
    EXPECT_EQ(1, gestor.getClientes().size());
}

// Verificar se NIF existe - caso verdadeiro
TEST(GestorTest, ExisteNifTrue) {

    GestorSistemaBancario gestor ("Banco ISEP");

    gestor.registarCliente("Tiago", "123456789", "1234");
    EXPECT_TRUE(gestor.existeNif("123456789"));
}

// Verificar se NIF existe - caso falso
TEST(GestorTest, ExisteNifFalse) {

    GestorSistemaBancario gestor ("Banco ISEP");

    EXPECT_FALSE(gestor.existeNif("987654321"));
}

// Autenticar com NIF e Passwords corretos
TEST(GestorTest, AutenticarValido) {

    GestorSistemaBancario gestor ("Banco ISEP");

    gestor.registarCliente("Tiago", "123456789", "1234");

    Cliente*c = gestor.autenticarCliente("123456789", "1234");
    EXPECT_NE(nullptr, c);
    EXPECT_EQ("Tiago", c->getNome());
}

// Autenticar com Password errada, deve falhar
TEST(GestorTest, AutenticarPasswordErrada) {
    GestorSistemaBancario gestor ("Banco ISEP");

    gestor.registarCliente("Tiago", "123456789", "1234");

    Cliente*c = gestor.autenticarCliente("123456789", "9999");
    EXPECT_EQ(nullptr, c);
}

// Autenticar com NIF que não existe, deve falhar
TEST(GestorTest, AutenticarNifInexistente) {
    GestorSistemaBancario gestor ("Banco ISEP");

    Cliente*c = gestor.autenticarCliente("999999999", "1234");
    EXPECT_EQ(nullptr, c);
}

// Buscar cliente por NIF existente
TEST(GestorTest, BuscarPorNifExistente) {

    GestorSistemaBancario gestor ("Banco ISEP");

    gestor.registarCliente("Tiago", "123456789", "1234");
    Cliente*c = gestor.buscarClientePorNif("123456789");

    EXPECT_NE(nullptr, c);
    EXPECT_EQ("123456789", c -> getNif());
}

// Buscar cliente por NIF que não existe
TEST(GestorTest, BuscarPorNifInexistente) {
    GestorSistemaBancario gestor ("Banco ISEP");

    Cliente*c = gestor.buscarClientePorNif("999999999");

    EXPECT_EQ(nullptr, c);
}

// Registar varios clientes distintos
TEST(GestorTest, RegistarVariosClientes) {

    GestorSistemaBancario gestor ("Banco ISEP");

    gestor.registarCliente("Tiago", "123456789", "1234");
    gestor.registarCliente("Ana", "987654321", "5678");
    gestor.registarCliente("Pedro", "111111111", "9999");

    EXPECT_EQ(3, gestor.getClientes().size());
}