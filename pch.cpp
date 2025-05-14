

#include "pch.h"
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

TipoCadena clasificarCadena(const std::string& cadena) {
    std::unordered_set<char> adn = { 'A', 'C', 'G', 'T' };
    std::unordered_set<char> arn = { 'A', 'C', 'G', 'U' };
    std::unordered_set<char> aminoacidos = { 'A', 'C', 'D', 'E', 'F', 'G', 'H',
                                            'I', 'K', 'L', 'M', 'N', 'P', 'Q',
                                            'R', 'S', 'T', 'V', 'W', 'Y' };

    std::unordered_set<char> caracteres;
    for (char c : cadena) {
        if (std::isalpha(c))
            caracteres.insert(std::toupper(c));
    }

    if (std::all_of(caracteres.begin(), caracteres.end(), [&](char c) { return adn.count(c); }))
        return TipoCadena::ADN;

    if (std::all_of(caracteres.begin(), caracteres.end(), [&](char c) { return arn.count(c); }))
        return TipoCadena::ARN;

    if (std::all_of(caracteres.begin(), caracteres.end(), [&](char c) { return aminoacidos.count(c); }))
        return TipoCadena::PROTEINA;

    return TipoCadena::DESCONOCIDA;
}

std::vector<std::string> extraerAminoacidos(const std::string& cadena) {
    std::unordered_map<char, std::string> mapa = {
        {'A', "Alanina"},   {'C', "Cisteína"}, {'D', "Aspartato"}, {'E', "Glutamato"},
        {'F', "Fenilalanina"}, {'G', "Glicina"}, {'H', "Histidina"}, {'I', "Isoleucina"},
        {'K', "Lisina"},    {'L', "Leucina"},  {'M', "Metionina"},  {'N', "Asparagina"},
        {'P', "Prolina"},   {'Q', "Glutamina"}, {'R', "Arginina"},  {'S', "Serina"},
        {'T', "Treonina"},  {'V', "Valina"},    {'W', "Triptófano"}, {'Y', "Tirosina"}
    };

    std::vector<std::string> resultado;
    for (char c : cadena) {
        c = std::toupper(c);
        if (mapa.count(c))
            resultado.push_back(mapa[c]);
    }
    return resultado;
}
