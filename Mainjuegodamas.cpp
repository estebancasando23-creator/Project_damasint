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
