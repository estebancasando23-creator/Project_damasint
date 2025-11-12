#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>

struct Jugador {
    char simbolo;
    int x;
    int y;
};

extern char Tablero[23][57];

void Ingresarnombres(std::string& nom1, std::string& nom2);
void Lanzardado(int& J1, int& J2, const std::string& nom1, const std::string& nom2);
void ElegirFicha(char& F1, char& F2, const std::string& nom1, const std::string& nom2, int pJ1, int pJ2, int& T);
void Elegirposicionestablero(char F);
void muestraTablero();
void muestraFilasYcolumnas();
void TableroDatosDelJugador();

void PintarPosAnt(Jugador* J);
void PintarPosAct(Jugador* J);
void Caracteristicas(Jugador* J, char c, int xpos, int ypos);
void EvaluarPosTablero(Jugador* J, int x, int y, bool& salir);
void movimientosFichas(Jugador* J);
void EscogerFicha(Jugador* J, const std::string& nombre, char ficha, int T);
bool Ganador(Jugador* J);

#endif // INTERFAZ_H
