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
    void modify();

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
    cout << "Codigo de cliente: " << this->key << endl;
    cout << "Nombre del cliente: " << this->name << endl;
    cout << "Telefono del cliente: " << this->phone << endl;
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
    cout << "Ingrese el telefono del cliente: ";
    cin >> this->phone;
    cout << "Cliente capturado: " << endl;
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

class Artist
{
    public:
        Artist();
        ~Artist(){};
        void show();
        void modify();
        void capture();
        bool search(int);
    protected:
    private:
        int key;
        int formation;
        string name;
        string genre;
        string country;
};

Artist::Artist()
{
    key = NULL;
    formation = 0;
    name = "";
    genre = "";
    country = "";
}

void Artist::show()
{
    cout << "Clave: "<<this->key << endl;
    cout << "Nombre: "<<this->name << endl;
    cout << "Pais de origen: "<<this->country << endl;
    cout << "Formado en: "<<this->formation << endl;
    cout << "Genero: " << this->genre << endl;
}

bool Artist::search(int k)
{
    return this->key == k;
}

void Artist::capture()
{
    cout << "Ingrese clave: ";
    cin >> this->key;
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

Client clients[10];
Artist artists[10];

void clientMenu()
{
    char opc; 
    do
    {
        system("cls");
        cout << "Menu cliente\n1.-Capturar\n2.-Mostrar\n3.-Modificar\n4.-Buscar\n5.-Salir\n";
        cin >> opc; 
        switch(opc)
        {
            case '1':
            for (int i = 0; i < 10; i++)
            {
                system("cls");
                clients[i].capture();
                system("pause");
            }
            break;
            case '2':
            for (int i = 0; i < 10; i++)
            {
                clients[i].show();
                cout << "-------------------------------"<<endl;
            }
            system("pause");
            break;
            case '3':
            {
                int code;
                cout <<"Ingrese el codigo: ";
                cin >> code; 
                for (int i = 0; i < 10; i++)
                {
                    if(clients[i].search(code))
                    {
                        clients[i].modify();
                        break; 
                    }
                }
                break;
            }
            case '4':
            {
                int code;
                cout <<"Ingrese el codigo: ";
                cin >> code; 
                for (int i = 0; i < 10; i++)
                {
                    if(clients[i].search(code))
                    {
                        clients[i].show();
                        int opc;
                        cout << "Presione 0 para continuar, 1 para modificar\n";
                        cin >> opc; 
                        if(opc==1)
                        {
                            clients[i].modify();
                        }
                    }
                }
                break;
            }
            case '5':
                break;
            default:
            cout << "Ingrese una opcion valida\n";
            system("pause");
            break;
        }
    }while(opc!='5');
}

void artistMenu()
{
    char opc; 
    do
    {
        system("cls");
        cout << "Menu cliente\n1.-Capturar\n2.-Mostrar\n3.-Modificar\n4.-Buscar\n5.-Salir\n";
        cin >> opc; 
        switch(opc)
        {
            case '1':
            for (int i = 0; i < 10; i++)
            {
                system("cls");
                artists[i].capture();
                system("pause");
            }
            break;
            case '2':
            for (int i = 0; i < 10; i++)
            {
                artists[i].show();
                cout << "-------------------------------"<<endl;
            }
            system("pause");
            break;
            case '3':
            {
                int code;
                bool found = false;
                cout <<"Ingrese el codigo: ";
                cin >> code; 
                for (int i = 0; i < 10; i++)
                {
                    if(artists[i].search(code))
                    {
                        artists[i].modify();
                        break;
                        found = true; 
                    }
                }
                if(!found)
                {
                    cout << "No encontrado"<<endl; 
                }
                system("pause");
                break;
            }
            case '4':
            {
                int code;
                bool found = false; 
                cout <<"Ingrese el codigo: ";
                cin >> code; 
                for (int i = 0; i < 10; i++)
                {
                    if(artists[i].search(code))
                    {
                        found = true;
                        artists[i].show();
                        int opc;
                        cout << "Presione 0 para continuar, 1 para modificar\n";
                        cin >> opc; 
                        if(opc==1)
                        {
                            artists[i].modify();
                        }
                    }
                    if(!found)
                    {
                        cout << "No encontrado\n";
                    }
                    system("pause");
                    break; 
                }
                system("pause");
                break;
            }
            case '5':
                break;
            default:
            cout << "Ingrese una opcion valida\n";
            system("pause");
            break;
        }
    }while(opc!='5');
}

void mainMenu()
{
    char opc;
    do
    {
        system("cls");
        cout <<"Ingrese la opcion que desee\n1.-Menu cliente\n2.-Menu artista\n3.-Salir\nOpcion: ";
        cin >> opc;
        switch(opc)
        {
            case '1':
                clientMenu();
                break;
            case '2':
                artistMenu();
                break;
            case '3':
                break;
            default:
                cout << "Ingrese una opcion valida\n";
                system("pause");
                break;
        }
    }while(opc!='3');
}

int main()
{
    cout << "Hey";
    mainMenu();
    return 0;
}
