#ifndef VIEWUTILS_H
#define VIEWUTILS_H

#include <string>
#include <limits>
#include <iostream>


inline void limparInput() {

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline void pausar() {

    std::cout << " \n Prima ENTER para continuar ...";
    std::cin.get();
}

inline void cabecalho(const std::string& titulo) {
    std::cout << "\n =======================\n";
    sdt::cout << " " << titulo << "\n";
    std::cout << "=======================\n";
}

#endif //VIEWUTILS_H