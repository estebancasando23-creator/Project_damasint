mira: #include "interfaz.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>

struct Jugador{
    char simbolo;
    int x, y;

    
};
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
void  Ingresarnombres(char* nom1, char* nom2){
    std::cout<<"ingrese el nombre del jugador 1: ";
    std::getline(std::cin, nom1);
    strupr(nom1);//esta es pa pasar a mayuscula  
    std::cout<<"ingrese el nombre del jugador 2: ";
    std::getline(std::cin, nom2); 
    strupr(nom2);
}
void Lanzardado(int& J1, int& J2, char *nom1, char* nom2){
    int dado;
    dado = (rand() % 6) + 1;
    std::cout<<"Lanzando dados...";

    J1 = dado.Next(1, 7);
    J2 = dado.Next(1, 7);
    if (J1>J2){
        std::cout<<"El turno es de jugador: "<< nom1<<std::endl;
    }else{
        std::cout<<"El turno es de jugador: "<< nom2<<std::endl;
    }
} 
void ElegirFicha(char& F1, char& F2, char* nom1, char* nom2, int pJ1, int pJ2, int& T){
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
        
        Tablero[18][24] = 'A'; Tablero[18][28] = 'A'; Tablero[18][32] = 'A'; Tablero[18][36] = 'A';
        Tablero[19][26] = 'A'; Tablero[19][30] = 'A'; Tablero[19][34] = 'A'; Tablero[20][28] = 'A';
        Tablero[20][32] = 'A'; Tablero[21][30] = 'A';

        Tablero[8][24] = 'B'; Tablero[8][28] = 'B'; Tablero[8][32] = 'B'; Tablero[8][36] = 'B';
        Tablero[7][26] = 'B'; Tablero[7][30] = 'B'; Tablero[7][34] = 'B'; Tablero[6][28] = 'B';
        Tablero[6][32] = 'B'; Tablero[5][30] = 'B';

        break;

    case 'C':
    case 'D':

        Tablero[17][6] = 'C'; Tablero[17][10] = 'C'; Tablero[17][14] = 'C'; Tablero[17][18] = 'C';
        Tablero[16][8] = 'C'; Tablero[16][12] = 'C'; Tablero[16][16] = 'C'; Tablero[15][10] = 'C';
        Tablero[15][14] = 'C'; Tablero[14][12] = 'C';

        Tablero[9][42] = 'D'; Tablero[9][46] = 'D'; Tablero[9][50] = 'D'; Tablero[9][52] = 'D';
        Tablero[10][44] = 'D'; Tablero[10][48] = 'D'; Tablero[10][54] = 'D'; Tablero[11][46] = 'D';
        Tablero[11][50] = 'D'; Tablero[12][48] = 'D';
        
        break;
    case 'E':
    case 'F':
        Tablero[17][42] = 'E'; Tablero[17][46] = 'E'; Tablero[17][50] = 'E'; Tablero[17][54] = 'E';
        Tablero[16][44] = 'E'; Tablero[16][48] = 'E'; Tablero[16][52] = 'E'; Tablero[15][46] = 'E';
        Tablero[15][50] = 'E'; Tablero[14][48] = 'E';

        Tablero[9][6] = 'F'; Tablero[9][10] = 'F'; Tablero[9][14] = 'F'; Tablero[9][18] = 'F';
        Tablero[10][8] = 'F'; Tablero[10][12] = 'F'; Tablero[10][16] = 'F'; Tablero[11][10] = 'F';
        Tablero[11][14] = 'F'; Tablero[12][12] = 'F';
        break;
    }
}

void muestraTablero(){
    for (int i = 0; i < 23; i++){
        for (int j = 0; j < 57; j++){
            
            Console::SetCursorPosition(j, i);
            if (Tablero[i][j]  == 'O')Console::ForegroundColor = ConsoleColor::White;
            else if(Tablero[i][j] == 'A')Console::ForegroundColor = ConsoleColor::Red;
            else if(Tablero[i][j] == 'B')Console::ForegroundColor = ConsoleColor::Yellow;
            else if(Tablero[i][j] == 'C')Console::ForegroundColor = ConsoleColor::Magenta;
            else if(Tablero[i][j] == 'D')Console::ForegroundColor = ConsoleColor::DarkCyan;
            else if(Tablero[i][j] == 'E')Console::ForegroundColor = ConsoleColor::DarkGreen;
            else if(Tablero[i][j] == 'F')Console::ForegroundColor = ConsoleColor::Green;
            
            if (Tablero[i][j] == 'N'){
                std::cout << ' ';
            }else{
                std::cout << Tablero[i][j];
            }
        }
        std::cout <<std::endl;
    }
    
}

void muestraFilasYcolumnas(){
    Console::ForegroundColor = ConsoleColor::Blue;

    Console::SetCursorPosition(6, 2); std::cout << "A";
    Console::SetCursorPosition(8, 2); std::cout << "B";
    Console::SetCursorPosition(10, 2); std::cout << "C";
    Console::SetCursorPosition(12, 2); std::cout << "D";
    Console::SetCursorPosition(14, 2); std::cout << "E";
    Console::SetCursorPosition(16, 2); std::cout << "F";
    Console::SetCursorPosition(18, 2); std::cout << "G";
    Console::SetCursorPosition(20, 2); std::cout << "H";
    Console::SetCursorPosition(22, 2); std::cout << "I";
    Console::SetCursorPosition(24, 2); std::cout << "J";
    Console::SetCursorPosition(26, 2); std::cout << "K";
    Console::SetCursorPosition(28, 2); std::cout << "L";
    Console::SetCursorPosition(30, 2); std::cout << "M";
    Console::SetCursorPosition(32, 2); std::cout << "N";
    Console::SetCursorPosition(34, 2); std::cout << "Ñ";
    Console::SetCursorPosition(36, 2); std::cout << "O";
    Console::SetCursorPosition(38, 2); std::cout << "P";
    Console::SetCursorPosition(40, 2); std::cout << "Q";
    Console::SetCursorPosition(42, 2); std::cout << "R";
    Console::SetCursorPosition(44, 2); std::cout << "S";
    Console::SetCursorPosition(46, 2); std::cout << "T";
    Console::SetCursorPosition(48, 2); std::cout << "V";
    Console::SetCursorPosition(50, 2); std::cout << "W";
    Console::SetCursorPosition(52, 2); std::cout << "X";
    Console::SetCursorPosition(54, 2); std::cout << "Y";
    Console::SetCursorPosition(56, 2); std::cout << "Z";

    Console::SetCursorPosition(2, 5); std::cout << "A";
    Console::SetCursorPosition(2, 6); std::cout << "B";
    Console::SetCursorPosition(2, 7); std::cout << "C";
    Console::SetCursorPosition(2, 8); std::cout << "D";
    Console::SetCursorPosition(2, 9); std::cout << "E";
    Console::SetCursorPosition(2, 10); std::cout << "F";
    Console::SetCursorPosition(2, 11); std::cout << "G";
    Console::SetCursorPosition(2, 12); std::cout << "H";
    Console::SetCursorPosition(2, 13); std::cout << "I";
    Console::SetCursorPosition(2, 14); std::cout << "J";
    Console::SetCursorPosition(2, 15); std::cout << "K";
    Console::SetCursorPosition(2, 15); std::cout << "L";
    Console::SetCursorPosition(2, 16); std::cout << "M";
    Console::SetCursorPosition(2, 17); std::cout << "N";
    Console::SetCursorPosition(2, 18); std::cout << "Ñ";
    Console::SetCursorPosition(2, 19); std::cout << "O";
    Console::SetCursorPosition(2, 20); std::cout << "P";
    Console::SetCursorPosition(2, 21); std::cout << "Q";

    Console::ForegroundColor = ConsoleColor::White;
}

void TableroDatosDelJugador(){

    Console::SetCursorPosition(76, 9);
    std::cout <<"________________________________________";
    Console::SetCursorPosition(75, 11);
    std::cout <<"________________________________________";
    Console::SetCursorPosition(75, 13);
    std::cout <<"________________________________________";
    Console::SetCursorPosition(75, 15);
    std::cout <<"________________________________________";
    Console::SetCursorPosition(76, 18);
    std::cout <<"________________________________________";

    Console::SetCursorPosition(75, 10);
    std::cout <<"|";
    Console::SetCursorPosition(75, 11);
    std::cout <<"|";
    Console::SetCursorPosition(75, 12);
    std::cout <<"|";
    Console::SetCursorPosition(75, 13);
    std::cout <<"|";
    Console::SetCursorPosition(75, 14);
    std::cout <<"|";
    Console::SetCursorPosition(75, 15);
    std::cout <<"|"
    Console::SetCursorPosition(75, 16);
    std::cout <<"|";
    Console::SetCursorPosition(75, 17);
    std::cout <<"|";
    Console::SetCursorPosition(75, 18);
    std::cout <<"|";

    Console::SetCursorPosition(88, 10);
    std::cout <<"|";
    Console::SetCursorPosition(88, 11);
    std::cout <<"|";
    Console::SetCursorPosition(88, 12);
    std::cout <<"|";
    Console::SetCursorPosition(88, 13);
    std::cout <<"|"
    Console::SetCursorPosition(88, 14);
    std::cout <<"|"
    Console::SetCursorPosition(88, 15);
    std::cout <<"|";
    Console::SetCursorPosition(88, 16);
    std::cout <<"|";
    Console::SetCursorPosition(88, 17);
    std::cout <<"|";
    Console::SetCursorPosition(88, 18);
    std::cout <<"|";

    Console::SetCursorPosition(105, 10);
    std::cout <<"|";
    Console::SetCursorPosition(105, 11);
    std::cout <<"|";
    Console::SetCursorPosition(105, 12);
    std::cout <<"|";
    Console::SetCursorPosition(105, 13);
    std::cout <<"|";
    Console::SetCursorPosition(105, 14);
    std::cout <<"|";
    Console::SetCursorPosition(105, 15);
    std::cout <<"|";
    Console::SetCursorPosition(105, 16);
    std::cout <<"|";
    Console::SetCursorPosition(105, 17);
    std::cout <<"|";
    Console::SetCursorPosition(105, 18);
    std::cout <<"|";

    Console::SetCursorPosition(124, 10);
    std::cout <<"|";
    Console::SetCursorPosition(124, 11);
    std::cout <<"|";
    Console::SetCursorPosition(124, 12);
    std::cout <<"|";
    Console::SetCursorPosition(124, 13);
    std::cout <<"|";
    Console::SetCursorPosition(124, 14);
    std::cout <<"|";
    Console::SetCursorPosition(124, 15);
    std::cout <<"|";
    Console::SetCursorPosition(124, 16);
    std::cout <<"|";
    Console::SetCursorPosition(124, 17);
    std::cout <<"|";
    Console::SetCursorPosition(124, 18);
    std::cout <<"|";

    Console::SetCursorPosition(76, 12);
    std::cout <<"Pos en X";

    Console::SetCursorPosition(76, 14);
    std::cout <<"Pos en Y";

    Console::SetCursorPosition(76, 16);
    std::cout <<"Numero de ";

    Console::SetCursorPosition(76, 17);
    std::cout <<"Movimientos ";
}

void PintarPosAnt(Jugador* J){

    for (int i = 0; i < 19; i++){
        for (size_t i = 0; i < count; i++){
            Tablero[J->y][J->x] = '0 ';
        }
        
    }
    

}
void Caracteristicas(Jugador* J, char c, int xpos, int ypos)
{
    J->simbolo=C;
    J->X=xpos;
    J->y=ypos;
}
void EvaluarPosTablero(Jugador* J, int x, int y, bool& salir)
{
    bool saltosSimple= false; saltoDoble= false, band= false;

    if(Tablero[y][x] !='N' && Tablero[y][x] !='')
    {
        if(((J->x)+2==x||(J->x)-2==x)&&((J->y)+1==y||(J->y)-1==y)){saltoSimple=true;}
        else if(((J->x)+4==x||(J->x)-4==x)&&((J->y)+2==y||(J->y)-2==y))saltoDoble=true;

        if(saltoSimple==true && (Tablero[y][x] != 'A' && Tablero[y][x] !='B' && Tablero[y][x] != 'C' && Tablero[y][x] != 'D' && Tablero[y][x] !='E' && Tablero[y][x] != 'F'))

        {
            if(J->simbolo=='A' &&(J->y)>y)
            {
                J->x=x;
                J->y=y;
                band= true;

            }
            if(J->simbolo=='B'&&(J->y)<y)
            {
                J->x=x;
                J->y=y;
                band= true;

            }
            if(J->simbolo='C'&&(J->x)<x)
            {
                J->x=x;
                J->y=y;
                band=true;
            }
            if(J->simbolo=='E'&&(J->x)>x)
            {
                J->x=x;
                J->y=y;
                band=true;
            }
            if(J->simbolo=='F'&&(J->x)<x)
            {
                J->x=x;
                J->y=y;
                band= true;
            }
        }
        if(saltoDoble==true&&(Tablero[y][x] != 'A' && Tablero[y][x] != 'B' && Tablero[y][x] !='C' && Tablero[y][x] !='D' && Tablero[y][x] !='E' && Tablero[y][x] != 'F'))
        {
            if(J->x > x && J->y >y y && (J->simbolo=='E' || J->simbolo=='A' || J->simbolo == 'D'))
            {
                if(Tablero[(J->y)-1][(J->x)-2] >= 'A' && Tablero[(J->y)-1][(J->x)-2] <= 'F')
                {
                    J->x = x;
                    J->y = y;
                    band = true;
                }
            }
            else if(J->x < x && J->y >y && (J->simbolo == 'C' || J->simbolo == 'A' || J->simbolo == 'F'))
            {
                if(Tablero[(J->y)-1][(J->x)+2]>='A' && Tablero[(J->y)-1][(J->x)+2] <= 'F')

                {
                    J->x=x;
                    J->y=y;
                    band = true;
                }
            }
             else if(J->x > x && J->y <y && (J->simbolo == 'B' || J->simbolo == 'D' || J->simbolo == 'E'))
             {
                if(Tablero[(J->y)+1][(J->x)-2] >= 'A' && Tablero[(J->y)+1][(J->x)-2]<='F')
                {
                    J->x=x;
                    J->y=y;
                    band = true;
                }
             }
             else if (J->x < x && J->y < y && (J->simbolo == 'F' || J->simbolo == 'B' || J->simbolo == 'C'))
             {
                if(Tablero[(J->y)+1][(J->x)+2] >= 'A' && Tablero[(J->y)+1][(J->x)+2] <= 'F')
                {
                    J->x = x;
                    J->y = y;
                    band = true;
                }
             }
        }
    }

    if(band == false){ Console::SetCursorPosition(2,31); std::cout<< "NO PUEDE REALIZAR ESTE MOVIMIENTO"; getch();}
}
void movimientosFichas(Jugador* J)
{
    int x,y;
    bool salir;
    Console::BackgroundColor=ConsoleColor::Gray;
    Console::SetCursorPosition(J->x, J->y);std::cout<<J->simbolo;
    Console::BackgroundColor= ConsoleColor::Black;


    do
    {
        Console::SetCursorPosition(2,28); std::cout<<"                                            ";
        Console::SetCursorPosition(2,28); std::cout<<"Ingrese la posicion X a la que desea moverse: ";
        std::cin>>x;

    } while(x<0||x>57);
    
    do
    {
      Console::SetCursorPosition(2,29);std::cout<<"                                  ";
      Console::SetCursorPosition(2,29);std::cout<<"Ingrese la posicion Y a la que desea moverse: ";
      std::cin>>y;
    } while(y<0||y>23);

    EvaluarPosTablero(J, x, y, salir)

    Console::SetCursorPosition(2,25); std::cout<<"                                          ";
    Console::SetCursorPosition(2,26); std::cout<<"                                          ";
    Console::SetCursorPosition(2,27); std::cout<<"                                          ";
    Console::SetCursorPosition(2,28); std::cout<<"                                          ";
    Console::SetCursorPosition(2,29); std::cout<<"                                          ";
    Console::SetCursorPosition(2,30); std::cout<<"                                          ";
    Console::SetCursorPosition(2,31); std::cout<<"                                          ";
    Console::SetCursorPosition(50,10); std::cout<<"                                          ";
    Console::SetCursorPosition(50,11); std::cout<<"                                          ";



    
    
}
void PintarPosAct(Jugador* J)
{
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 27; j++)
        {
            Tablero[J->y][J->X] = J->simbolo;
        }
        
    }
}
void EscogerFicha(Jugador* J, char* nombre, char ficha, int T)
{
    int opc;
    int posX, posY;
    bool salir = false
    char colum, fila;


    do
    {
        Console::SetCursorPosition(2,25);
        std::cout <<"                                                        ";
        Console::SetCursorPosition(2,26);
        std::cout <<"                                                        ";
        Console::SetCursorPosition(2,27);
        std::cout <<"                                                        ";
        Console::SetCursorPosition(2,28);
        std::cout <<"                                                        ";


        Console::SetCursorPosition(2,25);
        std::cout<<nombre<<"Ingresa la COLUMNA [A-Y] de la ficha que quieres mover: ";
        std::cin>> colum;

        switch(toupper(colum))
        {
            case 'A': posX= 6; break;
            case 'B': posX= 8; break;
            case 'C': posX= 10; break;
            case 'D': posX= 12; break;
            case 'E': posX= 14; break;
            case 'F': posX= 16; break;
            case 'G': posX= 18; break;
            case 'H': posX= 20; break;
            case 'I': posX= 22; break;
            case 'J': posX= 24; break;
            case 'K': posX= 26; break;
            case 'L': posX= 28; break;
            case 'M': posX= 30; break;
            case 'N': posX= 32; break;
            case 'O': posX= 34; break;
            case 'P': posX= 36; break;
            case 'Q': posX= 38; break;
            case 'R': posX= 40; break;
            case 'S': posX= 42; break;
            case 'T': posX= 44; break;
            case 'U': posX= 46; break;
            case 'V': posX= 48; break;
            case 'W': posX= 50; break;
            case 'X': posX= 52; break;
            case 'Y': posX= 54; break;

        }


        Console::SetCursorPosition(2,26);
        std::cout<<nombre<<"Ingresa la FILA[A-Q] de la ficha que quieres mover: ";
        std::cin>>fila;

        switch(toupper(fila))
        {
             case 'A': posY= 5; break;
            case 'B': posY= 6; break;
            case 'C': posY= 7; break;
            case 'D': posY= 8; break;
            case 'E': posY= 9; break;
            case 'F': posY= 10; break;
            case 'G': posY= 11; break;
            case 'H': posY= 12; break;
            case 'I': posY= 13; break;
            case 'J': posY= 14; break;
            case 'K': posY= 15; break;
            case 'L': posY= 16; break;
            case 'M': posY= 17; break;
            case 'N': posY= 18; break;
            case 'O': posY= 19; break;
            case 'P': posY= 20; break;
            case 'Q': posY= 21; break;
        }

        if(Tablero[posY][posX]==ficha)salir=true;
        if(salir != true)
        {
            Console::SetCursorPosition(3,28);std::cout<<"No puede mover esta ficha";
            getch();
        }

    }while(salir != true);

    if(T==1)
    {
        Console::SetCursorPosition(96,14); std::cout<<posY;
        Console::SetCursorPosition(96,12); std::cout<<posX;
    
    }

    else
    {
        Console::SetCursorPosition(115,14); std::cout<<posY;
        Console::SetCursorPosition(115,12); std::out<<posX;

    }


    Caracteristicas(J, ficha, posX, posY);
    PintarPosAnt(J);
    movimientoFichas(J);
    PintarPosAct(J);

    if(T==1)
    {
        Console::SetCursorPosition(96,14); std::cout<<"  ";
        Console::SetCursorPosition(96,12); std::cout<<"  ";
        
    }
    else
    {
        Console::SetCursorPosition(115,14); std::cout<<"   ";
        Console::SetCursorPosition(115,12); std::cout<<"   ";
        

    }
    
}
bool Ganador(Jugador* J)
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            if(J->simbolo == 'A' || J->simbolo == 'B')
            {
                if(Tablero[8][24] == 'A' && Tablero[8][28] == 'A' && Tablero[8][32] == 'A' && Tablero[8][36] == 'A' && 
                    Tablero[7][26] == 'A' && Tablero[7][30] == 'A' && Tablero[7][34] == 'A' && Tablero[6][28] == 'A' &&
                Tablero[6][32] == 'A' && Tablero[5][30] == 'A') return true;


                else if((Tablero[18][24] == 'B' && Tablero[18][28] == 'B' && Tablero[18][32] == 'B' && Tablero[18][36] == 'B' && 
                    Tablero[19][26] == 'B' && Tablero[19][30] == 'B' && Tablero[19][34] == 'B' && Tablero[20][28] == 'B' &&
                Tablero[20][32] == 'B' && Tablero[21][30] == 'B') return true;
)
            }
            else if(J->simbolo == 'C' || J->simbolo == 'D')
            {
                if(Tablero[17][6] == 'D' && Tablero[17][10] == 'D' && Tablero[17][14] == 'D' && Tablero[17][18] == 'D' && 
                    Tablero[16][8] == 'D' && Tablero[16][12] == 'D' && Tablero[16][16] == 'D' && Tablero[15][10] == 'D' &&
                Tablero[15][14] == 'D' && Tablero[14][12] == 'D') return true;

                else if(Tablero[9][42] == 'C' && Tablero[9][46] == 'C' && Tablero[9][50] == 'C' && Tablero[9][54] == 'C' && 
                    Tablero[10][44] == 'C' && Tablero[10][48] == 'C' && Tablero[10][52] == 'C' && Tablero[11][46] == 'C' &&
                Tablero[11][50] == 'C' && Tablero[12][48] == 'C') return true;


            }
            else if(J->simbolo == 'E' || J->simbolo == 'F')
            {
                 if(Tablero[17][42] == 'F' && Tablero[17][46] == 'F' && Tablero[17][50] == 'F' && Tablero[17][54] == 'F' && 
                    Tablero[16][44] == 'F' && Tablero[16][48] == 'F' && Tablero[16][52] == 'F' && Tablero[15][46] == 'F' &&
                Tablero[15][50] == 'F' && Tablero[14][48] == 'F') return true;

                else if(Tablero[9][6] == 'E' && Tablero[9][10] == 'E' && Tablero[9][14] == 'E' && Tablero[9][18] == 'E' && 
                    Tablero[10][8] == 'E' && Tablero[10][12] == 'E' && Tablero[10][16] == 'E' && Tablero[11][10] == 'E' &&
                Tablero[11][14] == 'E' && Tablero[12][12] == 'E') return true;

            }
            
        }
        
    }
    
}


