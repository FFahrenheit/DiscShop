#include "Sale.h"
#include <iostream>

using namespace std;

Sale::Sale()
{
}

Sale::~Sale()
{
}

bool Sale::search(int code)
{
    return this->key == code;
}

void Sale::capture(int key, int album, int seller, int client)
{
    this->key = key;
    this->albumCode = album;
    this->sellerCode = seller;
    cin.ignore();
    cout << "Ingrese el concepto de la venta: ";
    getline(cin,this->concept);
    cout << "Venta capturada. Datos:\n";
    this->show();
}

void Sale::show()
{
    cout << "Clave: "<<this->key<<endl;
    cout << "Album: "<<this->albumCode<<endl;
    cout << "Cliente: "<<this->clientCode<<endl;
    cout << "Vendedor: "<<this->sellerCode<<endl;
    cout << "Concepto de venta: "<<this->concept<<endl;
}
