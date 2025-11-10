//implementacion 
#include "interfaz.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <cstdlib>

struct Jugador{
    char simbolo;
    int x, y;
};
struct Tablero[10][10] = {
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    
};

void  Ingresarnombres(char* nom1, char* nom2){
    std::cout<<"ingrese el nombre del jugador 1: ";
    std::getline(std::cin, nom1);
    strupr(nom1);//esta es pa pasar a mayuscula  
    std::cout<<"ingrese el nombre del jugador 2: ";
    std::getline(std::cin, num2); 
    strupr(nom2);
}
void Lanzardado(int& J1, int& J2, char *nom1, char* nom2){
    int dado;
    dado = (rand() % 6) + 1;
    std::cout<<"Lanzando dados...";

    J1 = (rand() % 6) + 1;
    J2 = (rand() % 6) + 1;
    if (J1>J2){
        std::cout<<"El turno es de jugador: "<< nom1<<std::endl;
    }else{
        std::cout<<"El turno es de jugador: "<< nom2<<std::endl;
    }
} 
void Elegirficha(char& F1, char& F2, char* nom1, char* nom2, int pJ1, int pJ2, int& T){
    int opc;

    if (pJ1 > pJ2)
    {
        T = 1;
        std::cout<<nom1<< "elige una ficha"<<std::endl;
        std::cout<<"1 caracter A"<<std::endl;
        std::cout<<"2 caracter B"<<std::endl;
        std::cout<<"3 caracter C"<<std::endl;
        std::cout<<"4 caracter D"<<std::endl;
        std::cout<<"5 caracter E"<<std::endl;
        std::cout<<"6 caracter F"<<std::endl;
        do{
            std::cout<<"ingrese su eleccion: ";
            std::cin>>opc;
        } while (opc < 1 || opc > 6);

        switch (opc){
        case 1: F1 = "A"; break;
        case 2: F1 = "B"; break;
        case 3: F1 = "C"; break;
        case 4: F1 = "D"; break;
        case 5: F1 = "E"; break;
        case 6: F1 = "F"; 
        }
        if (F1 == 'A')F2 = 'B';
        else if(F1 == 'B')F2 = 'A';
        else if(F1 == 'C')F2 = 'D';
        else if(F1 == 'D')F2 = 'C';
        else if(F1 == 'E')F2 = 'F';
        else if(F1 == 'F')F2 = 'E';
        
    }else{
        T = 2;
        std::cout<<nom2<< "elige una ficha"<<std::endl;
        std::cout<<"1 caracter A"<<std::endl;
        std::cout<<"2 caracter B"<<std::endl;
        std::cout<<"3 caracter C"<<std::endl;
        std::cout<<"4 caracter D"<<std::endl;
        std::cout<<"5 caracter E"<<std::endl;
        std::cout<<"6 caracter F"<<std::endl;

        do{std::cout<<"ingrese su eleccion: ";
            std::cin>>opc;
        } while (opc < 1 || opc > 6);
        
        switch (opc){
        case 1: F2 = "A"; break;
        case 2: F2 = "B"; break;
        case 3: F2 = "C"; break;
        case 4: F2 = "D"; break;
        case 5: F2 = "E"; break;
        case 6: F2 = "F"; 
        }
        if (F1 == 'A')F2 = 'B';
        else if(F2 == 'B')F1 = 'A';
        else if(F2 == 'C')F1 = 'D';
        else if(F2 == 'D')F1 = 'C';
        else if(F2 == 'E')F1 = 'F';
        else if(F2 == 'F')F1 = 'E';
    }
    
}

void Elegirposicionestablero(char F){
    switch (F)
    {
    case 'A':
    case 'B':
        
        Tablero[0][0] = 'A'; Tablero[0][4] = 'A'; Tablero[0][6] = 'A'; Tablero[0][8] = 'A';  // Fila 0 
        Tablero[1][2] = 'A'; Tablero[1][5] = 'A'; Tablero[1][7] = 'A';  // Fila 1 (
        Tablero[2][4] = 'A'; Tablero[2][6] = 'A';  // Fila 2 (antes 20)
        break;
    
    default:
        break;
    }
}



int main(){
    char fichaJ1;
    char fichaJ2;
    int Turno;
    char* nombreJ1 = new char[20];
    char* nombreJ2 = new char[20];

    int puntajeJ1, puntajeJ2;
    int movientosJ1 = 0, movimientosJ2 = 0;
    
    Ingresarnombres(nombreJ1, nombreJ2);
    Lanzardado(puntajeJ1, puntajeJ2, nombreJ1, nombreJ2);
    Elegirficha(fichaJ1, fichaJ2, nombreJ1, nombreJ2, puntajeJ1, puntajeJ2, Turno);
    Elegirposicionestablero(fichaJ1); 
}
