int main() {
    int opcion = 0;

    do {
        system("cls");
        std::cout << "===== MENU =====\n";
        std::cout << "1. Jugar\n";
        std::cout << "0. Salir\n";
        std::cout << "================\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                system("cls");
                std::cout << "Iniciando el juego...\n";

                // Aquí llamas tus funciones del juego
                char fichaJ1, fichaJ2;
                int turno = 0;
                int dado1 = 0, dado2 = 0;
                char nombreJ1[20];
                char nombreJ2[20];

                Ingresarnombres(nombreJ1, nombreJ2);
                Lanzardado(dado1, dado2, nombreJ1, nombreJ2);
                Elegirficha(fichaJ1, fichaJ2, nombreJ1, nombreJ2, dado1, dado2, turno);

                std::cout << "\nJuego finalizado.\n";
                system("pause");
                break;
            }

            case 0:
                std::cout << "Saliendo...\n";
                break;

            default:
                std::cout << "Opcion invalida.\n";
                system("pause");
                break;
        }

    } while (opcion != 0);

    return 0;
}
