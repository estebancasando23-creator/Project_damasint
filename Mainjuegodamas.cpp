int main(){
    char fichaJ1;
    char fichaJ2;
    int Turno;
    char* nombreJ1 = new char[20];
    char* nombreJ2 = new char[20];
    int puntajeJ1, puntajeJ2;
    int movimientoJ1 = 0; movimientosJ2 = 0;

    IngresarNombres(nombreJ1, nombreJ2);
    LanzarDado(puntajeJ1, puntajeJ2, nombreJ1, nombreJ2);
    ElegirFicha(fichaJ1, fichaJ2, nombreJ1, nombreJ2, puntajeJ1, puntajeJ2, Turno);
    ElegirPosicionesTablero(fichaJ1);

    Console::Clear();
    Console::CursorVisible = false; 

    Jugador* JP1 = new Jugador;
    Jugador* JP2=  new Jugador;

    while (true)
    { 
        Console::CursorVisible= false;

        muestraTablero();
        muestrFilasYcolumnas();
        TablerosDatosDelJugador();

        Console::SetCursorPosition(91,10);
        std::cout<<nombreJ1<<"["<<fichaJ1<<"]";
        Console::SetCursorPosition(109,10);
        std::cout<<nombreJ2<<"["<<fichaJ2<<"]";
        Console::SetCursorPosition(97,17); std::cout<<movimientosJ1;
        Console::SetCursorPosition(115,17); std::cout<<movimientosJ2;

        if(Ganador(JP1)== true)break;

        if (Turno==1)
        {
            EscogerFicha(JP1, nombreJ1, fichaJ1, Turno);
            movimientosJ1++;
            Turno = 2;

        }
        else
        {
            EscogerFicha(JP2, nombreJ2, fichaJ2, Turno);
            movimientosJ2++;
            Turno = 1;
        }
        




}
Console::Clear();
if(Turno == 1)std::cout << "El ganador es: " << nombreJ2 <<std::endl;
else std::cout<<"El ganadorves: " << nombreJ1 << std::endl;

getch();
return 0;
}
