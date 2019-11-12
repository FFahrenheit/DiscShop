#include "Single.h"
#include <iostream>

using namespace std;

void Single::show()
{
    Album::show();
    cout << "Duracion: " << this->lenght<<endl;
}

void Single::capture(int code)
{
    cout << "Ingrese la duracion: ";
    cin >> this->lenght;
    Album::capture(code);
}

void Single::modify()
{
    char option;
    cout << "Que desea modificar?\n0.-Nombre\n1.-Clave\n2.-Lanzamiento\n3.-Genero\n4.-Precio\n5.-Artista\n5.-Duracion\nSu eleccion: ";
    cin >> option;
    system("cls");
    cout << "Ingrese nuevo valor: ";
    cin.ignore();
    switch(option)
    {
        case '0':
            getline(cin,this->name);
            break;
        case '1':
            cin>>this->key;
            break;
        case '2':
            cin >> this->year;
            break;
        case '3':
            getline(cin,this->genre);
            break;
        case '4':
            cin >> this->price;
            break;
        case '5':
            cin >> this->price;
            break;
        case '6':
            cin >> this->lenght;
        default:
            return;
    }
}
