#include "interfaz.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Juego {
private:
    std::string jugador1;
    std::string jugador2;
    int puntaje1;
    int puntaje2;

public:
    Juego() : puntaje1(0), puntaje2(0) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
    }

    void iniciarJuego() {
        std::cout << "Ingrese nombre del jugador 1: ";
        std::cin >> jugador1;
        std::cout << "Ingrese nombre del jugador 2: ";
        std::cin >> jugador2;

        // Simulación simple de puntajes aleatorios
        puntaje1 = std::rand() % 10;
        puntaje2 = std::rand() % 10;

        std::cout << jugador1 << ": " << puntaje1
                  << " - " << jugador2 << ": " << puntaje2 << "\n";

        if (puntaje1 > puntaje2)
            Interfaz::mostrarGanador(jugador1);
        else if (puntaje2 > puntaje1)
            Interfaz::mostrarGanador(jugador2);
        else
            Interfaz::mostrarEmpate();
    }

    void menuPrincipal() {
        int opcion = -1;
        while (opcion != 0) {
            Interfaz::mostrarMenu();
            std::cin >> opcion;

            switch (opcion) {
                case 1:
                    iniciarJuego();
                    break;
                case 2:
                    Interfaz::mostrarReglas();
                    Interfaz::pausar();
                    break;
                case 0:
                    std::cout << "\nSaliendo del juego...\n";
                    break;
                default:
                    std::cout << "\nOpcion invalida.\n";
            }
        }
    }
};
