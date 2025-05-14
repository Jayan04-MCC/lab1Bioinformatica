
#pragma once

#include "gtest/gtest.h"
#ifndef BIOMOLECULA_H
#define BIOMOLECULA_H

#include <string>
#include <vector>

enum class TipoCadena {
    ADN,
    ARN,
    PROTEINA,
    DESCONOCIDA
};

TipoCadena clasificarCadena(const std::string& cadena);
std::vector<std::string> extraerAminoacidos(const std::string& cadena);

#endif
