//Conversor de grados Celsius a Fahrenheit 07/05/2025.
//Nehemias Vecino
//Librerias necesarias "color.h"
#include <iostream>
#include <windows.h>
#include "colors.h"

using namespace std;


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
	system("");
	bool respuesta_valida = false;
	char Opcion;
    double ValorC, ValorF, ValorC1, ValorF1;
    int width = 28;   //ANCHO
    int height = 12;   //ALTURA
    
    //PARTE SUPERIOR
    cout << char(201);
    for (int i = 0; i < width - 2; i++) {
        cout << char(205);
    }
    cout << char(187) << endl;

    //LADOS
    for (int i = 0; i < height - 2; i++) {
        cout << char(186);
        for (int j = 0; j < width - 2; j++) {
            cout << " ";
        }
        cout << char(186) << endl;
    }

    //PARTE INFERIOR
    cout << char(200);
    for (int i = 0; i < width - 2; i++) {
        cout << char(205);
    }
    cout << char(188) << endl;

    int column = 13;
    int startRow = 1;
    int endRow = height - 2;

    for (int i = startRow; i <= endRow; i++) {
        gotoxy(column, i);
        cout << char(186);
    }

    //Primera horizontal
    int row = 3;
    int row1 = 5;
    int row2 =  7;
    int startCol = 1;
    int endCol = width - 2;
    //Segunda horizontal
    int startCol1 = 1;
    int endCol1 = width - 2;

    gotoxy(startCol, row);
    for (int i = startCol; i <= endCol; i++) {
        cout << char(205);
    }
    
     gotoxy(startCol1, row1);
    for (int i = startCol; i <= endCol; i++) {
        cout << char(205);
    }
     
     gotoxy(startCol1, row2);
    for (int i = startCol; i <=endCol; i++){
    	cout << char(205);
	}
	
    gotoxy(17,4);
    cout<<"Valor F"<< endl;
    
    
    gotoxy(4, 2);
    cout << "Celsius";
    gotoxy(16, 2);
    cout << "Fahrenheit";


    gotoxy(4,4);
    cout << "Valor C";
	gotoxy(6,6);
	cin >> ValorC;

    ValorF = ValorC * 1.8 + 32;
    

    gotoxy(20,6);
    cout << ValorF;
    
    
    	//color amarillo en Opcion si seguis o no.
    	do {
		gotoxy(0,15);
		cout <<GREEN << BG_YELLOW<<"¿quieres hacer otra operacion? (s/n):"; cin >> Opcion;
		Opcion = tolower(Opcion);
		if (Opcion == 's' || Opcion == 'n'){
			respuesta_valida = true;
		} else {
			cout <<"Opcion no valida. por favor, ingrese 's' o 'n'."<< endl; 
		}		
} while (!respuesta_valida);
if (Opcion == 's'){
	goto Operacion2; 
} else {
	//sino te tira el mensaje hasta luego.
	cout << "Hasta luego" << endl;

}

Operacion2:
	
	gotoxy(6,8);
	cin >> ValorC1;

    ValorF1 = (ValorC1 * 1.8 + 32);
    
    gotoxy(20,8);
    cout << ValorF1;
    	

    gotoxy(0,20);
    return 0;
}

