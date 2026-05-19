#include <string>

class Gerenciamento {
public:
    Gerenciamento();

    double getDespesas()const;
    double getGanhos()const;
    double getLucros()const;

    void mostrarResumo()const;

private:
    double despesas;
    double ganhos;
    double Lucros;

};

#endif