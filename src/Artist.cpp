#include "Artist.h"
#include <iostream>

using namespace std;

void Artist::show()
{
    cout << "Clave: "<<this->key << endl;
    cout << "Nombre: "<<this->name << endl;
    cout << "Pais de origen: "<<this->country << endl;
    cout << "Formado en: "<<this->formation << endl;
    cout << "Genero: " << this->genre << endl;
}

void Artist::capture(int code)
{
    this->key = code;
    cout << "Ingrese nombre: ";
    cin.ignore();
    getline(cin,this->name);
    cout << "Ingrese pais de origen: ";
    getline(cin,this->country);
    cout << "Ingrese genero: ";
    getline(cin,this->genre);
    cout << "Ingrese fecha de formacion (YYYY): ";
    cin >> this->formation;
    cout << "Artista ingresado\n";
    this->show();
}

bool Artist::search(int code)
{
    return this->key == code;
}

void Artist::modify()
{
    char option;
    cout << "Que desea modificar?\n0.-Nombre\n1.-Clave\n2.-Pais de origen\n3.-Genero\n4.-Fecha de formacion\nSu eleccion: ";
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
            getline(cin,this->country);
            break;
        case '3':
            getline(cin,this->genre);
            break;
        case '4':
            cin >> this->formation;
            break;
        default:
            return;
    }
        cout << "Informacion modificada!\nNuevos datos:\n";
        this->show();
}
