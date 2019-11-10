#include "Client.h"
#include <iostream>

using namespace std;

Client::Client()
{
}

Client::~Client()
{
}

void Client::show()
{
    cout << "Codigo de cliente: " << this->key<<endl;
    cout << "Nombre del cliente: "<<this->name<<endl;
    cout << "Telefono del cliente: "<<this->phone<<endl;
    cout << "Direccion del cliente: "<<this->address<<endl;
}

bool Client::search(int code)
{
    return this->key == code;
}

void Client::capture(int code)
{
    this->key = code;
    cin.ignore();
    cout << "Ingrese el nombre del cliente: ";
    getline(cin,this->name);
    cout << "Ingrese la direccion del cliente: ";
    getline(cin,this->address);
    cout << "Ingrese el telefono del cliente: ";
    cin >> this->phone;
    cout << "Cliente capturado: "<<endl;
    this->show();
}

void Client::modify()
{
    char option;
    cout << "Que desea modificar?\n0.-Nombre\n1.-Clave\n2.-Direccion\n3.-Telefono\nSu eleccion: ";
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
            getline(cin,this->address);
            break;
        case '3':
            cin >> this->phone;
            break;
        default:
            return;
    }
        cout << "Informacion modificada!\nNuevos datos:\n";
        this->show();
}
