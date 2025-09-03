//coversor de Horas 14/05/205
//Nehemias Vecino

#include <iostream>
#include <windows.h>
#include <cctype> // para tolower
#include "colors.h"

using namespace std;

// Función para mover el cursor
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para dibujar el marco una vez
void dibujarMarco(int width, int height) {
    // Parte superior
    cout << char(201);
    for (int i = 0; i < width - 2; i++) cout << char(205);
    cout << char(187) << endl;

    // Cuerpo
    for (int i = 0; i < height - 2; i++) {
        cout << char(186);
        for (int j = 0; j < width - 2; j++) cout << " ";
        cout << char(186) << endl;
    }

    // Parte inferior
    cout << char(200);
    for (int i = 0; i < width - 2; i++) cout << char(205);
    cout << char(188) << endl;

    // Líneas verticales internas
    for (int i = 1; i < height - 1; i++) {
        gotoxy(11, i); cout << char(186);
        gotoxy(23, i); cout << char(186);
    }

    // Líneas horizontales internas
    gotoxy(1, 2);
    for (int i = 1; i <= width - 2; i++) cout << char(205);
    gotoxy(1, 4);
    for (int i = 1; i <= width - 2; i++) cout << char(205);
}

// Función para ejecutar la operación
void ejecutarOperacion() {
    double Minutos, Segundos, Horas;

    gotoxy(2, 1);  cout << "Minutos";
    gotoxy(14, 3); cout << "Segundos";
    gotoxy(26, 3); cout << "Horas";

    gotoxy(5, 3);  cout << "        "; // Limpia el área
    gotoxy(5, 3);  cin >> Minutos;

    Segundos = Minutos * 60;
    Horas = Minutos / 60;

    gotoxy(5, 5);  cout << "        ";
    gotoxy(5, 5);  cout << Minutos;

    gotoxy(15, 5); cout << "        ";
    gotoxy(15, 5); cout << Segundos;

    gotoxy(28, 5); cout << "        ";
    gotoxy(28, 5); cout << Horas;
}

int main() {
    system(""); // Habilita colores en consola de Windows
    int width = 35;
    int height = 8;
    char opcion;

    bool continuar = true;
    while (continuar) {
        system("cls"); // Limpia la pantalla
        dibujarMarco(width, height);
        ejecutarOperacion();

        bool respuesta_valida = false;
        do {
            gotoxy(0, 10); cout << "                                         "; // Limpia línea anterior
            gotoxy(0, 10);
            cout << WHITE << BG_RED << "¿Quieres hacer otra operación? (s/n): " << RESET;
            cin >> opcion;
            opcion = tolower(opcion);

            if (opcion == 's') {
                respuesta_valida = true;
                continuar = true;
            } else if (opcion == 'n') {
                respuesta_valida = true;
                continuar = false;
                gotoxy(0, 12); cout << "Hasta luego!" << endl;
            } else {
                gotoxy(0, 11);
                cout << "Opción no válida. Por favor ingrese 's' o 'n'.";
            }
        } while (!respuesta_valida);
    }

    gotoxy(0, 20);
    return 0;
}
