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
    double phone[3];
    string address;
};

Client::Client()
{
    name = "";
    address = "";
    key = NULL;
}

void Client::show()
{
    cout << "Codigo de cliente: " << this->key << endl;
    cout << "Nombre del cliente: " << this->name << endl;
    cout << "Telefonos del cliente: " << endl << this->phone[0] << endl;
    cout << this->phone[1] << endl << this->phone[2]<<endl;
    cout << "Direccion del cliente: " << this->address << endl;
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
    getline(cin, this->name);
    cout << "Ingrese la direccion del cliente: ";
    getline(cin, this->address);
    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese el telefono "<<i+1<<": ";
        cin >> phone[i];
    }
    cout << "Cliente capturado: " << endl;
}

Client client;

void menu()
{
    int option;
    do
    {
        cout << "\nMENU\n1.-Capturar\n2.-Mostrar\n3.-Buscar\n4.-Salir\nOpcion: ";
        cin >> option;
        system("cls");
        switch (option)
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
                if (client.search(clave))
                {
                    client.show();
                }
                else
                {
                    cout << "NO EXISTE EL CLIENTE";
                }
                break;
            case 4:
                break;
            default:
                cout << "Ingrese una opcion valida";
        }
        if(option!=4)
        {
            system("pause");
        }
    } while (option!=4);
}

int main()
{
    menu();
    return 0;
}
