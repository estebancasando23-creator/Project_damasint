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
        std::cout << "        MENU PRINCIPAL       \n";
        std::cout << "=============================\n";
        std::cout << "1. Ingresar nombres de jugadores\n";
        std::cout << "2. Lanzar dados\n";
        std::cout << "3. Elegir fichas\n";
        std::cout << "4. Mostrar tablero\n";
        std::cout << "5. Mostrar coordenadas del tablero\n";
        std::cout << "0. Salir\n";
        std::cout << "=============================\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                system("cls");
                Ingresarnombres(jugador1, jugador2);
                std::cout << "\nJugadores cargados: " << jugador1 << " y " << jugador2 << "\n";
                system("pause");
                break;

            case 2:
                system("cls");
                if (jugador1.empty() || jugador2.empty()) {
                    std::cout << "Primero ingrese los nombres (opcion 1)\n";
                } else {
                    Lanzardado(dado1, dado2, jugador1, jugador2);
                }
                std::cout << "\n";
                system("pause");
                break;

            case 3:
                system("cls");
                if (dado1 == 0 && dado2 == 0) {
                    std::cout << "Primero debe lanzar los dados (opcion 2)\n";
                } else {
                    ElegirFicha(ficha1, ficha2, jugador1, jugador2, dado1, dado2, turno);
                    Elegirposicionestablero(ficha1);
                    Elegirposicionestablero(ficha2);
                }
                system("pause");
                break;

            case 4:
                system("cls");
                muestraTablero();
                std::cout << "\n";
                system("pause");
                break;

            case 5:
                system("cls");
                muestraFilasYcolumnas();
                std::cout << "\n";
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
