int main() {
int main() {
    std::srand((unsigned)std::time(nullptr));

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
            case 1: {
                system("cls");
                std::cout << "Iniciando el juego...\n";

                // Variables locales al juego
                char fichaJ1, fichaJ2;
                int turno = 0;
                int dado1 = 0, dado2 = 0;
                char nombreJ1[20];
                char nombreJ2[20];

                // Llamada a las funciones de tu código original
                Ingresarnombres(nombreJ1, nombreJ2);
                Lanzardado(dado1, dado2, nombreJ1, nombreJ2);
                Elegirficha(fichaJ1, fichaJ2, nombreJ1, nombreJ2, dado1, dado2, turno);

                std::cout << "\n¡Fin de la partida!\n";
                system("pause");
                break;
            }

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
