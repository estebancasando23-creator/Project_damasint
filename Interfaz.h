#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include <string>
#include <limits>

class Interfaz {
public:
    static void mostrarTitulo() {
        std::cout << "\n=====================================\n";
        std::cout << "       DAMAS INTERNACIONALES\n";
        std::cout << "=====================================\n";
    }

    static void mostrarMenu() {
        mostrarTitulo();
        std::cout << "1. Jugar\n";
        std::cout << "2. Reglas\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";
    }

    static void mostrarReglas() {
        std::cout << "\n=== Reglas de Damas Internacionales ===\n";
        std::cout << "- El tablero tiene 10x10 casillas.\n";
        std::cout << "- Cada jugador inicia con 20 fichas.\n";
        std::cout << "- Solo se mueven por casillas negras.\n";
        std::cout << "- Para capturar, se salta sobre una pieza rival.\n";
        std::cout << "- Al llegar al extremo opuesto, una ficha se corona como Dama.\n";
        std::cout << "=======================================\n";
    }

    static void mostrarGanador(const std::string& nombre) {
        std::cout << "\n=====================================\n";
        std::cout << "          ¡Felicidades!\n";
        std::cout << "   Ganador: " << nombre << "\n";
        std::cout << "=====================================\n";
    }

    static void mostrarEmpate() {
        std::cout << "\n=====================================\n";
        std::cout << "             ¡Empate!\n";
        std::cout << "=====================================\n";
    }

    static void pausar() {
        std::cout << "\nPresiona ENTER para continuar...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};

#endif
