#include <iostream>
#include <string>
#include "Album.h"

using namespace std;


void Album::modify()
{
    char option;
    cout << "Que desea modificar?\n0.-Nombre\n1.-Clave\n2.-Lanzamiento\n3.-Genero\n4.-Precio\n5.-Artista\nSu eleccion: ";
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
        default:
            return;
    }
        cout << "Informacion modificada!\nNuevos datos:\n";
        this->show();
}

Album::Album()
{
}

Album::~Album()
{
}

bool Album::search(int code)
{
    return code == this->key;
}

void Album::show()
{
    cout << "Clave: "<<this->key<<endl;
    cout << "Nombre: "<<this->name<<endl;
    cout << "Codigo del artista: "<<this->artistCode<<endl;
    cout << "Genero: "<<this->genre<<endl;
    cout << "Lanzamiento: "<<this->year<<endl;
    cout << "Precio: "<<this->price<<endl;
}

void Album::capture(int code)
{
    system("cls");
    this->key = code;
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin,this->name);
    cout << "Ingrese el numero de codigo de artista: ";
    cin >> this->artistCode;
    cout << "Ingrese el genero: ";
    cin.ignore();
    getline(cin,this->genre);
    cout << "Ingrese el precio: ";
    cin >> this->price;
    cout << "Ingrese el lanzamiento: ";
    cin >> this->year;
    cout << endl << "Agreado!"<<endl;
    this->show();
}
