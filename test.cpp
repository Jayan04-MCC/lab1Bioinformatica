#include "pch.h"

#include <gtest/gtest.h>

TEST(ClasificacionTest, EsADN) {
    EXPECT_EQ(clasificarCadena("ACGT"), TipoCadena::ADN);
}

TEST(ClasificacionTest, EsARN) {
    EXPECT_EQ(clasificarCadena("ACGU"), TipoCadena::ARN);
}

TEST(ClasificacionTest, EsProteina) {
    EXPECT_EQ(clasificarCadena("ACDEFGHIKLMNPQRSTVWY"), TipoCadena::PROTEINA);
}

TEST(ClasificacionTest, EsDesconocida) {
    EXPECT_EQ(clasificarCadena("XYZ123"), TipoCadena::DESCONOCIDA);
}

TEST(AminoacidoTest, ListaCorrecta) {
    std::vector<std::string> esperado = { "Alanina", "Cisteína", "Aspartato" };
    EXPECT_EQ(extraerAminoacidos("ACD"), esperado);
}
