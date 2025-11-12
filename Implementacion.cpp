#include "interfaz.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include <limits>


static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


char Tablero[23][57] = {
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N'},
    {' ',' ',' ',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N'},
    {' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N'},
    {' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' '},
    {' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N'},
    {' ',' ',' ',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N'},
    {' ',' ',' ',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N'},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
};

static void SetCursorPositionSimple(int x, int y) {
    COORD pos;
    pos.X = (SHORT)x;
    pos.Y = (SHORT)y;
    SetConsoleCursorPosition(hConsole, pos);
}
static void SetColorSimple(WORD color) {
    SetConsoleTextAttribute(hConsole, color);
}



void Ingresarnombres(std::string& nom1, std::string& nom2){
    SetColorSimple(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    SetCursorPositionSimple(0,0);
    std::cout << "Ingrese el nombre del jugador 1: ";
    std::getline(std::cin, nom1);
    std::transform(nom1.begin(), nom1.end(), nom1.begin(), [](unsigned char c){ return std::toupper(c); });

    std::cout << "Ingrese el nombre del jugador 2: ";
    std::getline(std::cin, nom2);
    std::transform(nom2.begin(), nom2.end(), nom2.begin(), [](unsigned char c){ return std::toupper(c); });

    SetColorSimple(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Lanzardado(int& J1, int& J2, const std::string& nom1, const std::string& nom2){
    J1 = (std::rand() % 6) + 1;
    J2 = (std::rand() % 6) + 1;
    SetCursorPositionSimple(2,2);
    std::cout << "Lanzando dados... " << nom1 << ":" << J1 << " - " << nom2 << ":" << J2 << "   ";

    SetCursorPositionSimple(2,3);
    if (J1 > J2) std::cout << "El turno es de jugador: " << nom1;
    else if (J2 > J1) std::cout << "El turno es de jugador: " << nom2;
    else std::cout << "Empate en el lanzamiento.";
}

void ElegirFicha(char& F1, char& F2, const std::string& nom1, const std::string& nom2, int pJ1, int pJ2, int& T){
    int opc = 0;
    if (pJ1 > pJ2)
    {
        T = 1;
        SetCursorPositionSimple(2,5);
        std::cout << nom1 << " elige una ficha" << std::endl;
        std::cout << "1 A  2 B  3 C  4 D  5 E  6 F" << std::endl;
        do{
            SetCursorPositionSimple(2,8);
            std::cout << "ingrese su eleccion: ";
            std::cin >> opc;
            if (!std::cin) { std::cin.clear(); std::cin.ignore(1000,'\n'); opc = 0; }
        } while (opc < 1 || opc > 6);

        switch (opc){
        case 1: F1 = 'A'; break;
        case 2: F1 = 'B'; break;
        case 3: F1 = 'C'; break;
        case 4: F1 = 'D'; break;
        case 5: F1 = 'E'; break;
        case 6: F1 = 'F'; break;
        default: F1 = 'A'; break;
        }
        if (F1 == 'A') F2 = 'B';
        else if (F1 == 'B') F2 = 'A';
        else if (F1 == 'C') F2 = 'D';
        else if (F1 == 'D') F2 = 'C';
        else if (F1 == 'E') F2 = 'F';
        else if (F1 == 'F') F2 = 'E';
    } else {
        T = 2;
        SetCursorPositionSimple(2,5);
        std::cout << nom2 << " elige una ficha" << std::endl;
        std::cout << "1 A  2 B  3 C  4 D  5 E  6 F" << std::endl;
        do{
            SetCursorPositionSimple(2,8);
            std::cout << "ingrese su eleccion: ";
            std::cin >> opc;
            if (!std::cin) { std::cin.clear(); std::cin.ignore(1000,'\n'); opc = 0; }
        } while (opc < 1 || opc > 6);

        switch (opc){
        case 1: F2 = 'A'; break;
        case 2: F2 = 'B'; break;
        case 3: F2 = 'C'; break;
        case 4: F2 = 'D'; break;
        case 5: F2 = 'E'; break;
        case 6: F2 = 'F'; break;
        default: F2 = 'A'; break;
        }
        if (F2 == 'A') F1 = 'B';
        else if (F2 == 'B') F1 = 'A';
        else if (F2 == 'C') F1 = 'D';
        else if (F2 == 'D') F1 = 'C';
        else if (F2 == 'E') F1 = 'F';
        else if (F2 == 'F') F1 = 'E';
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Elegirposicionestablero(char F){
    
    switch (F)
    {
    case 'A':
        Tablero[18][24] = 'A'; Tablero[18][28] = 'A'; Tablero[18][32] = 'A'; Tablero[18][36] = 'A';
        Tablero[19][26] = 'A'; Tablero[19][30] = 'A'; Tablero[19][34] = 'A'; Tablero[20][28] = 'A';
        Tablero[20][32] = 'A'; Tablero[21][30] = 'A';
        break;
    case 'B':
        Tablero[8][24] = 'B'; Tablero[8][28] = 'B'; Tablero[8][32] = 'B'; Tablero[8][36] = 'B';
        Tablero[7][26] = 'B'; Tablero[7][30] = 'B'; Tablero[7][34] = 'B'; Tablero[6][28] = 'B';
        Tablero[6][32] = 'B'; Tablero[5][30] = 'B';
        break;
    case 'C':
        Tablero[17][6] = 'C'; Tablero[17][10] = 'C'; Tablero[17][14] = 'C'; Tablero[17][18] = 'C';
        Tablero[16][8] = 'C'; Tablero[16][12] = 'C'; Tablero[16][16] = 'C'; Tablero[15][10] = 'C';
        Tablero[15][14] = 'C'; Tablero[14][12] = 'C';
        break;
    case 'D':
        Tablero[9][42] = 'D'; Tablero[9][46] = 'D'; Tablero[9][50] = 'D'; Tablero[9][52] = 'D';
        Tablero[10][44] = 'D'; Tablero[10][48] = 'D'; Tablero[10][54] = 'D'; Tablero[11][46] = 'D';
        Tablero[11][50] = 'D'; Tablero[12][48] = 'D';
        break;
    case 'E':
        Tablero[17][42] = 'E'; Tablero[17][46] = 'E'; Tablero[17][50] = 'E'; Tablero[17][54] = 'E';
        Tablero[16][44] = 'E'; Tablero[16][48] = 'E'; Tablero[16][52] = 'E'; Tablero[15][46] = 'E';
        Tablero[15][50] = 'E'; Tablero[14][48] = 'E';
        break;
    case 'F':
        Tablero[9][6] = 'F'; Tablero[9][10] = 'F'; Tablero[9][14] = 'F'; Tablero[9][18] = 'F';
        Tablero[10][8] = 'F'; Tablero[10][12] = 'F'; Tablero[10][16] = 'F'; Tablero[11][10] = 'F';
        Tablero[11][14] = 'F'; Tablero[12][12] = 'F';
        break;
    default:
        break;
    }
}

void muestraTablero(){

    for (int i = 0; i < 23; i++){
        for (int j = 0; j < 57; j++){
            SetCursorPositionSimple(j, i);
            char ch = Tablero[i][j];
            WORD color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            if (ch == 'O') color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            else if (ch == 'A') color = FOREGROUND_RED | FOREGROUND_INTENSITY;
            else if (ch == 'B') color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            else if (ch == 'C') color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            else if (ch == 'D') color = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            else if (ch == 'E') color = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            else if (ch == 'F') color = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            SetColorSimple(color);
            if (ch == 'N' || ch == ' ') std::cout << ' ';
            else std::cout << ch;
        }
    }
    SetColorSimple(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void muestraFilasYcolumnas(){

    SetColorSimple(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    SetCursorPositionSimple(6, 2); std::cout << "A";
    SetCursorPositionSimple(8, 2); std::cout << "B";
    SetCursorPositionSimple(10,2); std::cout << "C";
    SetCursorPositionSimple(12,2); std::cout << "D";
    SetCursorPositionSimple(14,2); std::cout << "E";
    SetCursorPositionSimple(16,2); std::cout << "F";
    SetCursorPositionSimple(18,2); std::cout << "G";
    SetCursorPositionSimple(20,2); std::cout << "H";
    SetCursorPositionSimple(22,2); std::cout << "I";
    SetCursorPositionSimple(24,2); std::cout << "J";
    SetCursorPositionSimple(26,2); std::cout << "K";
    SetCursorPositionSimple(28,2); std::cout << "L";
    SetCursorPositionSimple(30,2); std::cout << "M";
    SetCursorPositionSimple(32,2); std::cout << "N";
    SetCursorPositionSimple(34,2); std::cout << "Ñ";
    SetCursorPositionSimple(36,2); std::cout << "O";
    SetCursorPositionSimple(38,2); std::cout << "P";
    SetCursorPositionSimple(40,2); std::cout << "Q";
    SetCursorPositionSimple(42,2); std::cout << "R";
    SetCursorPositionSimple(44,2); std::cout << "S";
    SetCursorPositionSimple(46,2); std::cout << "T";
    SetCursorPositionSimple(48,2); std::cout << "V";
    SetCursorPositionSimple(50,2); std::cout << "W";
    SetCursorPositionSimple(52,2); std::cout << "X";
    SetCursorPositionSimple(54,2); std::cout << "Y";
    SetCursorPositionSimple(56,2); std::cout << "Z";

    SetCursorPositionSimple(2, 5); std::cout << "A";
    SetCursorPositionSimple(2, 6); std::cout << "B";
    SetCursorPositionSimple(2, 7); std::cout << "C";
    SetCursorPositionSimple(2, 8); std::cout << "D";
    SetCursorPositionSimple(2, 9); std::cout << "E";
    SetCursorPositionSimple(2,10); std::cout << "F";
    SetCursorPositionSimple(2,11); std::cout << "G";
    SetCursorPositionSimple(2,12); std::cout << "H";
    SetCursorPositionSimple(2,13); std::cout << "I";
    SetCursorPositionSimple(2,14); std::cout << "J";
    SetCursorPositionSimple(2,15); std::cout << "K";
    SetCursorPositionSimple(2,16); std::cout << "L";
    SetCursorPositionSimple(2,17); std::cout << "M";
    SetCursorPositionSimple(2,18); std::cout << "N";
    SetCursorPositionSimple(2,19); std::cout << "Ñ";
    SetCursorPositionSimple(2,20); std::cout << "O";
    SetCursorPositionSimple(2,21); std::cout << "P";
    SetCursorPositionSimple(2,22); std::cout << "Q";
    SetColorSimple(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void TableroDatosDelJugador(){
    for (int r = 9; r <= 18; ++r) {
        SetCursorPositionSimple(75, r); std::cout << "|";
        SetCursorPositionSimple(88, r); std::cout << "|";
        SetCursorPositionSimple(105, r); std::cout << "|";
        SetCursorPositionSimple(124, r); std::cout << "|";
    }
    SetCursorPositionSimple(76, 12); std::cout << "Pos en X";
    SetCursorPositionSimple(76, 14); std::cout << "Pos en Y";
    SetCursorPositionSimple(76, 16); std::cout << "Numero de ";
    SetCursorPositionSimple(76, 17); std::cout << "Movimientos ";
}

void PintarPosAnt(Jugador* J){
    if (!J) return;
    if (J->y >= 0 && J->y < 23 && J->x >= 0 && J->x < 57) {
        Tablero[J->y][J->x] = 'O';
    }
}

void Caracteristicas(Jugador* J, char c, int xpos, int ypos)
{
    if (!J) return;
    J->simbolo = c;
    J->x = xpos;
    J->y = ypos;
}

void EvaluarPosTablero(Jugador* J, int x, int y, bool& salir)
{
    salir = false;
    if (!J) return;
    if (x < 0 || x >= 57 || y < 0 || y >= 23) {
        SetCursorPositionSimple(2,31); SetColorSimple(FOREGROUND_RED | FOREGROUND_INTENSITY); std::cout << "COORDENADAS FUERA DE RANGO"; _getch();
        SetColorSimple(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        return;
    }
    if (Tablero[y][x] == 'N' || Tablero[y][x] == ' ') {
        SetCursorPositionSimple(2,31); SetColorSimple(FOREGROUND_RED | FOREGROUND_INTENSITY); std::cout << "NO SE PUEDE MOVER A UNA CASILLA NO VALIDA"; _getch();
        SetColorSimple(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        return;
    }
    int dx = abs(J->x - x);
    int dy = abs(J->y - y);
    bool saltoSimple = false;
    bool saltoDoble = false;
    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) saltoSimple = true;
    if ((dx == 4 && dy == 2) || (dx == 2 && dy == 4)) saltoDoble = true;
    bool band = false;

    if (saltoSimple) {
        if (J->simbolo == 'A' && y < J->y) { J->x = x; J->y = y; band = true; }
        else if (J->simbolo == 'B' && y > J->y) { J->x = x; J->y = y; band = true; }
        else if (J->simbolo == 'C' && x > J->x) { J->x = x; J->y = y; band = true; }
        else if (J->simbolo == 'D' && x < J->x) { J->x = x; J->y = y; band = true; }
        else if (J->simbolo == 'E' && x < J->x) { J->x = x; J->y = y; band = true; }
        else if (J->simbolo == 'F' && x > J->x) { J->x = x; J->y = y; band = true; }
    }
    if (!band && saltoDoble) {
        int midx = (J->x + x) / 2;
        int midy = (J->y + y) / 2;
        if (midx >= 0 && midx < 57 && midy >= 0 && midy < 23) {
            char mid = Tablero[midy][midx];
            if (mid >= 'A' && mid <= 'F' && mid != J->simbolo) {
                J->x = x; J->y = y; band = true;
                Tablero[midy][midx] = 'O';
            }
        }
    }

    if (!band) {
        SetCursorPositionSimple(2,31); SetColorSimple(FOREGROUND_RED | FOREGROUND_INTENSITY); std::cout << "NO PUEDE REALIZAR ESTE MOVIMIENTO"; _getch();
        SetColorSimple(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    } else {
        salir = true;
    }
}

void movimientosFichas(Jugador* J)
{
    if (!J) return;
    int x,y;
    bool ok = false;
    SetColorSimple(FOREGROUND_RED | FOREGROUND_INTENSITY);
    SetCursorPositionSimple(J->x, J->y); std::cout << J->simbolo;
    SetColorSimple(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    do {
        SetCursorPositionSimple(2,28); std::cout << "Ingrese la posicion X (0-56): ";
        std::cin >> x;
        if (!std::cin) { std::cin.clear(); std::cin.ignore(1000,'\n'); x = -1; }
    } while (x < 0 || x > 56);

    do {
        SetCursorPositionSimple(2,29); std::cout << "Ingrese la posicion Y (0-22): ";
        std::cin >> y;
        if (!std::cin) { std::cin.clear(); std::cin.ignore(1000,'\n'); y = -1; }
    } while (y < 0 || y > 22);

    bool salir = false;
    EvaluarPosTablero(J, x, y, salir);
    if (salir) {
        PintarPosAnt(J);
        J->x = x;
        J->y = y;
        PintarPosAct(J);
    }

    for (int r = 25; r <= 31; ++r) { SetCursorPositionSimple(2, r); std::cout << std::string(60, ' '); }
}

void PintarPosAct(Jugador* J)
{
    if (!J) return;
    if (J->y >= 0 && J->y < 23 && J->x >= 0 && J->x < 57) {
        Tablero[J->y][J->x] = J->simbolo;
    }
}

void EscogerFicha(Jugador* J, const std::string& nombre, char ficha, int T)
{
    if (!J) return;
    int posX = -1, posY = -1;
    bool salir = false;
    char colum = 0, fila = 0;

    do {
        for (int r = 25; r <= 28; ++r) { SetCursorPositionSimple(2, r); std::cout << std::string(56, ' '); }
        SetCursorPositionSimple(2,25);
        std::cout << nombre << " Ingresa la COLUMNA [A-Y] de la ficha que quieres mover: ";
        std::cin >> colum; if (!std::cin) { std::cin.clear(); std::cin.ignore(1000,'\n'); colum = 0; }

        switch(toupper(colum)) {
            case 'A': posX= 6; break; case 'B': posX= 8; break; case 'C': posX= 10; break; case 'D': posX= 12; break;
            case 'E': posX= 14; break; case 'F': posX= 16; break; case 'G': posX= 18; break; case 'H': posX= 20; break;
            case 'I': posX= 22; break; case 'J': posX= 24; break; case 'K': posX= 26; break; case 'L': posX= 28; break;
            case 'M': posX= 30; break; case 'N': posX= 32; break; case 'O': posX= 34; break; case 'P': posX= 36; break;
            case 'Q': posX= 38; break; case 'R': posX= 40; break; case 'S': posX= 42; break; case 'T': posX= 44; break;
            case 'U': posX= 46; break; case 'V': posX= 48; break; case 'W': posX= 50; break; case 'X': posX= 52; break;
            case 'Y': posX= 54; break;
            default: posX = -1; break;
        }

        SetCursorPositionSimple(2,26);
        std::cout << nombre << " Ingresa la FILA [A-Q] de la ficha que quieres mover: ";
        std::cin >> fila; if (!std::cin) { std::cin.clear(); std::cin.ignore(1000,'\n'); fila = 0; }

        switch(toupper(fila)) {
            case 'A': posY= 5; break; case 'B': posY= 6; break; case 'C': posY= 7; break; case 'D': posY= 8; break;
            case 'E': posY= 9; break; case 'F': posY= 10; break; case 'G': posY= 11; break; case 'H': posY= 12; break;
            case 'I': posY= 13; break; case 'J': posY= 14; break; case 'K': posY= 15; break; case 'L': posY= 16; break;
            case 'M': posY= 17; break; case 'N': posY= 18; break; case 'O': posY= 19; break; case 'P': posY= 20; break;
            case 'Q': posY= 21; break; default: posY = -1; break;
        }

        if (posX == -1 || posY == -1) {
            SetCursorPositionSimple(3,28); SetColorSimple(FOREGROUND_RED | FOREGROUND_INTENSITY); std::cout << "Coordenadas invalidas"; _getch();
            SetColorSimple(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            continue;
        }

        if (Tablero[posY][posX] == ficha) salir = true;
        else {
            SetCursorPositionSimple(3,28); SetColorSimple(FOREGROUND_RED | FOREGROUND_INTENSITY); std::cout << "No puede mover esta ficha"; _getch();
            SetColorSimple(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    } while(!salir);

    if (T == 1) {
        SetCursorPositionSimple(96,14); std::cout << posY;
        SetCursorPositionSimple(96,12); std::cout << posX;
    } else {
        SetCursorPositionSimple(115,14); std::cout << posY;
        SetCursorPositionSimple(115,12); std::cout << posX;
    }

    Caracteristicas(J, ficha, posX, posY);
    PintarPosAnt(J);
    movimientosFichas(J);
    PintarPosAct(J);

    if (T == 1) {
        SetCursorPositionSimple(96,14); std::cout << "   ";
        SetCursorPositionSimple(96,12); std::cout << "   ";
    } else {
        SetCursorPositionSimple(115,14); std::cout << "   ";
        SetCursorPositionSimple(115,12); std::cout << "   ";
    }
}

bool Ganador(Jugador* J)
{
    if (!J) return false;
    if (J->simbolo == 'A' || J->simbolo == 'B') {
        bool a_gana = (Tablero[8][24] == 'A' && Tablero[8][28] == 'A' && Tablero[8][32] == 'A' && Tablero[8][36] == 'A' &&
                       Tablero[7][26] == 'A' && Tablero[7][30] == 'A' && Tablero[7][34] == 'A' && Tablero[6][28] == 'A' &&
                       Tablero[6][32] == 'A' && Tablero[5][30] == 'A');
        bool b_gana = (Tablero[18][24] == 'B' && Tablero[18][28] == 'B' && Tablero[18][32] == 'B' && Tablero[18][36] == 'B' &&
                       Tablero[19][26] == 'B' && Tablero[19][30] == 'B' && Tablero[19][34] == 'B' && Tablero[20][28] == 'B' &&
                       Tablero[20][32] == 'B' && Tablero[21][30] == 'B');
        return a_gana || b_gana;
    } else if (J->simbolo == 'C' || J->simbolo == 'D') {
        bool d_gana = (Tablero[17][6] == 'D' && Tablero[17][10] == 'D' && Tablero[17][14] == 'D' && Tablero[17][18] == 'D' &&
                       Tablero[16][8] == 'D' && Tablero[16][12] == 'D' && Tablero[16][16] == 'D' && Tablero[15][10] == 'D' &&
                       Tablero[15][14] == 'D' && Tablero[14][12] == 'D');
        bool c_gana = (Tablero[9][42] == 'C' && Tablero[9][46] == 'C' && Tablero[9][50] == 'C' && Tablero[9][52] == 'C' &&
                       Tablero[10][44] == 'C' && Tablero[10][48] == 'C' && Tablero[10][54] == 'C' && Tablero[11][46] == 'C' &&
                       Tablero[11][50] == 'C' && Tablero[12][48] == 'C');
        return c_gana || d_gana;
    } else if (J->simbolo == 'E' || J->simbolo == 'F') {
        bool f_gana = (Tablero[17][42] == 'F' && Tablero[17][46] == 'F' && Tablero[17][50] == 'F' && Tablero[17][54] == 'F' &&
                       Tablero[16][44] == 'F' && Tablero[16][48] == 'F' && Tablero[16][52] == 'F' && Tablero[15][46] == 'F' &&
                       Tablero[15][50] == 'F' && Tablero[14][48] == 'F');
        bool e_gana = (Tablero[9][6] == 'E' && Tablero[9][10] == 'E' && Tablero[9][14] == 'E' && Tablero[9][18] == 'E' &&
                       Tablero[10][8] == 'E' && Tablero[10][12] == 'E' && Tablero[10][16] == 'E' && Tablero[11][10] == 'E' &&
                       Tablero[11][14] == 'E' && Tablero[12][12] == 'E');
        return e_gana || f_gana;
    }
    return false;
}

