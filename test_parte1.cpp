#include <gtest/gtest.h>

TEST(PunterosTest, 00) {
    int numero = 2;
    int *puntero_a_numero;

    
    puntero_a_numero = &numero; 

    EXPECT_EQ(2, *puntero_a_numero); 

    // TODO: Pensar... ¿es necesario liberar memoria?
    // No porque es una variable local
}

TEST(PunterosTest, 01) {
    int *numero;

    
    numero = new int(2); 

    EXPECT_EQ(2, *numero);

    
    delete numero; 
    numero = nullptr; 

    EXPECT_EQ(nullptr, numero);
}

TEST(PunterosTest, 02) {
    int *numero = new int(2); 
    *numero += 3; 

    EXPECT_EQ(5, *numero);

    
    delete numero;
    numero = nullptr; 

    EXPECT_EQ(nullptr, numero);
}

TEST(PunterosTest, 03) {
    int numero = 2;
    int *puntero_a_numero;

    
    puntero_a_numero = &numero; 

    EXPECT_EQ(2, *puntero_a_numero);
}


TEST(PunterosTest, 04) {
    int *numero = new int; 
    int *alias_de_numero;
    *numero = 2; 

    
    alias_de_numero = numero;
    EXPECT_EQ(numero, alias_de_numero); 
    EXPECT_EQ(2, *alias_de_numero);     

    delete alias_de_numero;
    alias_de_numero = nullptr; 
    EXPECT_EQ(nullptr, alias_de_numero);

    // TODO: Pensar... ¿a dónde apunta con `numero` ahora? ¿Qué ocurre si
    // queremos acceder al valor en dicha posición de memoria?
    // Después de 'delete alias_de_numero;', la memoria a la que 'numero' apuntaba también es liberada.
}