#include <iostream>
#include "Seller.h"

using namespace std;

bool Seller::search(int code)
{
    return this->key == code;
}


void Seller::show()
{
    cout << "Nomina: " << this->key<<endl;
    cout << "Nombre del vendedor: "<<this->name<<endl;
    cout << "Telefono del vendedor: "<<this->phone<<endl;
    cout << "Direccion del vendedor: "<<this->address<<endl;
    cout << "Pago: "<<this->salary << endl;
}

void Seller::capture(int code)
{
    this->key = code;
    cin.ignore();
    cout << "Ingrese el nombre del vendedor: ";
    getline(cin,this->name);
    cout << "Ingrese la direccion del vendedor: ";
    getline(cin,this->address);
    cout << "Ingrese el telefono del vendedor: ";
    cin >> this->phone;
    cout << "Ingrese el pago del vendedor: ";
    cin >> this->salary;
    cout << "Cliente capturado: "<<endl;
    this->show();
}

void Seller::modify()
{
    char option;
    cout << "Que desea modificar?\n0.-Nombre\n1.-Clave\n2.-Direccion\n3.-Telefono\n4.-Salario\nSu eleccion: ";
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
        case '4':
            cin >> this->salary;
            break;
        default:
            return;
    }
        cout << "Informacion modificada!\nNuevos datos:\n";
        this->show();
}
