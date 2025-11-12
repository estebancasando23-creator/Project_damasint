interfaz: #ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include <limits>
#include <vector>

// ---------- Config / Globals ----------
extern HANDLE hConsole;

// tablero original 23x57
extern char Tablero[23][57];
extern bool Crown[23][57];

// símbolos globales
extern char jugador1Symbol;
extern char jugador2Symbol;

// ---------- Tipos ----------
struct Jugador {
    char simbolo;
    int x;
    int y;
};

// ---------- Prototipos ----------
void SetCursorPositionSimple(int x, int y);
void SetColorSimple(WORD color);
void waitKey();

int colLetterToX(char c);
int rowLetterToY(char r);
bool inBounds(int x, int y);
bool isPieceChar(char ch);
bool isOpponentChar(char ch, char mySym);

void Ingresarnombres(std::string& nom1, std::string& nom2);
void Lanzardado(int& J1, int& J2, const std::string& nom1, const std::string& nom2);
void ElegirFicha(char& F1, char& F2, const std::string& nom1, const std::string& nom2, int pJ1, int pJ2, int& T);
void Elegirposicionestablero(char F);
void muestraTablero();
void muestraFilasYcolumnas();
void TableroDatosDelJugador();

void PintarPosAnt(Jugador* J);
void Caracteristicas(Jugador* J, char c, int xpos, int ypos);
int EvaluarPosTableroSimple(Jugador* J, int x, int y, int &midX, int &midY);
bool canCaptureFrom(Jugador* J);
void applyMoveToBoard(Jugador* J, int dstX, int dstY, int midX=-1, int midY=-1);
void movimientosFichas(Jugador* J);

#endif
