#include <iostream>

using namespace std;

class Client
{
    public:
        Client();
        ~Client() = default;
        bool search(int);
        void show();
        void capture();
    protected:
    private:
        string name;
        int key;
        double phone;
        string address;
};

Client::Client()
{
    name = "";
    address = "";
    key = NULL;
    phone = NULL;
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

void Client::capture()
{
    cout << "Ingrese la clave: ";
    cin >> this->key;
    cin.ignore();
    cout << "Ingrese el nombre del cliente: ";
    getline(cin,this->name);
    cout << "Ingrese la direccion del cliente: ";
    getline(cin,this->address);
    cout << "Ingrese el telefono del cliente: ";
    cin >> this->phone;
    cout << "Cliente capturado: "<<endl;
}

Client client;

void menu()
{
    int option;
    cout << "\nMENU\n1.-Capturar\n2.-Mostrar\n3.-Buscar\n4.-Salir\nOpcion: ";
    cin >> option;
    system("cls");
    switch(option)
    {
        case 1:
            client.capture();
            break;
        case 2:
            client.show();
            break;
        case 3:
            int clave;
            cout << "Ingrese clave a buscar: ";
            cin >> clave;
            if(client.search(clave))
            {
                client.show();
            }
            else
            {
                cout << "NO EXISTE EL CLIENTE";
            }
            break;
        case 4:
            return;
    }
    system("pause");
    menu();
}

int main()
{
    menu();
    return 0;
}
