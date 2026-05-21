#ifndef VIEWUTILS_H
#define VIEWUTILS_H

#include <string>
#include <limits>
#include <iostream>
#include <cctype>

inline void limparInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline void pausar() {
    std::cout << "\n Prima ENTER para continuar ...";
    std::cin.get();
}

inline void cabecalho(const std::string& titulo) {
    std::cout << "\n =======================\n";
    std::cout << " " << titulo << "\n";
    std::cout << " =======================\n";
}

inline bool validarNif(const std::string& nif) {
    if (nif.size() != 9) return false;
    for (char c : nif)
        if (!std::isdigit(c)) return false;
    return true;
}

inline bool validarPassword(const std::string& password) {
    if (password.size() != 4) return false;
    for (char c : password)
        if (!std::isdigit(c)) return false;
    return true;
}

#endif // VIEWUTILS_H
