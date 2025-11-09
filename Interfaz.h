//interfaz 
#ifndef Interfaz.h
#define Interfaz.h
#include <vector>
#include <string>

const int tamaño_tablero = 10;
struct pieza{
  char tipo;
  bool Dama
  pieza(char t = ´ ´,bool d = false) : tipo(t), Dama(d)
  bool esJugador(int jugador) const;
};
struct Jugador{
  std::string nombre;
  int piezas_restantes;
  int num;
Jugador(std::string n, int i) : nombre(n), piezas_restantes(20), num(i) {}
void lostpieza 
}



#endif
