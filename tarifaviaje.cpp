//tafifa de viaje 19/03/2025
//Nehemias Vecino
#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombreApellido, destino;
    int kilometros = 0, valor = 0, totalPagar = 0;

    cout << "Nombre y Apellido: "; cin >> nombreApellido; 

    cout << "Destino: "; cin >> destino;

    cout << "Kilómetros: "; cin >> kilometros;

    cout << "Valor por kilómetro: "; cin >> valor;

    totalPagar = kilometros * valor;

    if (kilometros > 400) {
        totalPagar = (totalPagar * 50 ) /100;
        goto totalPagar;
    } else if (kilometros > 250) {
        totalPagar -= totalPagar * 0.15;
    }
	
    cout << "Destino: " << destino << endl;
    totalPagar:
	cout << "Total a pagar (con descuento):" << totalPagar << endl;

    return 0;
}

