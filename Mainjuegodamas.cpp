int main() {
    std::srand((unsigned)std::time(nullptr));

    std::string jugador1, jugador2;
    int dado1 = 0, dado2 = 0, turno = 0;
    char ficha1 = ' ', ficha2 = ' ';
    int opcion = 0;

    do {
        system("cls");
        SetColorSimple(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        std::cout << "=============================\n";
        std::cout << "       MENU PRINCIPAL        \n";
        std::cout << "=============================\n";
        std::cout << "1. Jugar\n";
        std::cout << "0. Salir\n";
        std::cout << "=============================\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                system("cls");
                std::cout << "Iniciando el juego...\n";
                Ingresarnombres(jugador1, jugador2);
                Lanzardado(dado1, dado2, jugador1, jugador2);
                ElegirFicha(ficha1, ficha2, jugador1, jugador2, dado1, dado2, turno);
                std::cout << "\n¡Juego finalizado!\n";
                system("pause");
                break;

            case 0:
                std::cout << "Saliendo del programa...\n";
                break;

            default:
                std::cout << "Opcion invalida.\n";
                system("pause");
                break;
        }

    } while (opcion != 0);

    return 0;
}
