#include "Manager.h"
#include <iostream>

using namespace std;

Manager::Manager()
{
    this->albumCount = 0;
    this->artistCount = 0;
    this->clientCount = 0;
}

Manager::~Manager()
{
}

int Manager::searchArtist(int key)
{
    for(int i=0; i<this->artistCount;i++)
    {
        if(this->artists[i].search(key))
        {
            return i;
        }
    }
    return -1;
}

int Manager::searchAlbum(int key)
{
    for(int i=0; i<this->albumCount; i++)
    {
        if(this->albums[i].search(key))
        {
            return i;
        }
    }
    return -1;
}

int Manager::searchClient(int key)
{
    for(int i=0;i<this->clientCount;i++)
    {
        if(this->clients[i].search(key))
        {
            return i;
        }
    }
    return -1;
}

void Manager::clientMenu()
{
    char option;
    do
    {
        cin.ignore();
        system("cls");
        cout << "Bienvenido al panel de control de clientes, seleccione la opci�n correspondiente:"<<endl;
        cout << "0.-Nuevo cliente\n1.-Listar clientes\n2.-Buscar y ver detalles\n3.-Modificar\n4.-Eliminar\n5.-Salir\nSu seleccion: ";
        cin >> option;
        system("cls");
        switch(option)
        {
            case '0':
            {
                int code;
                cout << "Ingrese el codigo para el cliente: ";
                cin >> code;
                int pos = this->searchClient(code);
                if(pos == -1)
                {
                    this->clients[clientCount].capture(code);
                    this->clientCount++;
                }
                else
                {
                    cout << "Error! Codigo repetido\n";
                }
                break;
            }
            case '1':
            {
                cout << ((this->clientCount == 0)? "Vacio\n" : "Albums:\n");
                for(int i=0; i<this->clientCount; i++)
                {
                    this->clients[i].show();
                    cout << "-----------------------------------------------------"<<endl;
                }
                break;
            }
            case '2':
            {
                int key;
                cout << "Ingrese la clave del cliente: ";
                cin >> key;
                int pos = this->searchClient(key);
                if(pos!=-1)
                {
                    cout << "Cliente encontrado! \n";
                    this->clients[pos].show();
                }
                else
                {
                    cout << "No se encontro el cliente :(\n";
                }
                break;
            }
            case '3':
            {
                int key;
                cout << "Ingrese la clave del cliente: ";
                cin >> key;
                int pos = this->searchClient(key);
                if(pos!=-1)
                {
                    cout << "Cliente encontrado! \n";
                    this->clients[pos].modify();
                }
                else
                {
                    cout << "No se encontro el cliente :(\n";
                }
                break;
            }
            case '4':
            {
                int key;
                cout << "Ingrese la clave del cliente: ";
                cin >> key;
                int pos = this->searchClient(key);
                if(pos!=-1)
                {
                    for(int i=pos; i<this->clientCount-1; i++)
                    {
                        this->clients[i] = this->clients[i+1];
                    }
                    cout << "Cliente eliminado :( \n";
                    this->clientCount--;

                }
                else
                {
                    cout << "No se encontro el cliente :(\n";
                }
                break;
            }
            case '5':
                return;
            default:
                cout << "Seleccione una opcion valida\n";
        }
        system("pause");
    }while(option!='5');
}

void Manager::artistMenu()
{
        char option;
    do
    {
        cin.ignore();
        system("cls");
        cout << "Bienvenido al panel de control de artistas, seleccione la opci�n correspondiente:"<<endl;
        cout << "0.-Nuevo artista\n1.-Listar artistas\n2.-Buscar y ver detalles\n3.-Modificar\n4.-Eliminar\n5.-Salir\nSu seleccion: ";
        cin >> option;
        system("cls");
        switch(option)
        {
            case '0':
            {
                int code;
                cout << "Ingrese el codigo para el artista: ";
                cin >> code;
                int pos = this->searchArtist(code);
                if(pos == -1)
                {
                    this->artists[artistCount].capture(code);
                    this->artistCount++;
                }
                else
                {
                    cout << "Error! Codigo repetido\n";
                }
                break;
            }
            case '1':
            {
                cout << ((this->artistCount == 0)? "Vacio\n" : "Artistas:\n");
                for(int i=0; i<this->artistCount; i++)
                {
                    this->artists[i].show();
                    cout << "-----------------------------------------------------"<<endl;
                }
                break;
            }
            case '2':
            {
                int key;
                cout << "Ingrese la clave del artista: ";
                cin >> key;
                int pos = this->searchArtist(key);
                if(pos!=-1)
                {
                    cout << "Album encontrado! \n";
                    this->artists[pos].show();
                }
                else
                {
                    cout << "No se encontro el artista :(\n";
                }
                break;
            }
            case '3':
            {
                int key;
                cout << "Ingrese la clave del artista: ";
                cin >> key;
                int pos = this->searchArtist(key);
                if(pos!=-1)
                {
                    cout << "Album encontrado! \n";
                    this->artists[pos].modify();
                }
                else
                {
                    cout << "No se encontro el artista :(\n";
                }
                break;
            }
            case '4':
            {
                int key;
                cout << "Ingrese la clave del artista: ";
                cin >> key;
                int pos = this->searchArtist(key);
                if(pos!=-1)
                {
                    for(int i=pos; i<this->artistCount-1; i++)
                    {
                        this->artists[i] = this->artists[i+1];
                    }
                    cout << "Artista eliminado :( \n";
                    this->artistCount--;

                }
                else
                {
                    cout << "No se encontro el artista :(\n";
                }
                break;
            }
            case '5':
                return;
            default:
                cout << "Seleccione una opcion valida\n";
        }
        system("pause");
    }while(option!='5');
}

void Manager::albumMenu()
{
    char option;
    do
    {
        cin.ignore();
        system("cls");
        cout << "Bienvenido al panel de control de albums, seleccione la opci�n correspondiente:"<<endl;
        cout << "0.-Nuevo album\n1.-Listar albumes\n2.-Buscar y ver detalles\n3.-Modificar\n4.-Eliminar\n5.-Salir\nSu seleccion: ";
        cin >> option;
        system("cls");
        switch(option)
        {
            case '0':
            {
                int code;
                cout << "Ingrese el codigo para el album: ";
                cin >> code;
                int pos = this->searchAlbum(code);
                if(pos == -1)
                {
                    this->albums[albumCount].capture(code);
                    this->albumCount++;
                }
                else
                {
                    cout << "Error! Codigo repetido\n";
                }
                break;
            }
            case '1':
            {
                cout << ((this->albumCount == 0)? "Vacio\n" : "Albums:\n");
                for(int i=0; i<this->albumCount; i++)
                {
                    this->albums[i].show();
                    cout << "-----------------------------------------------------"<<endl;
                }
                break;
            }
            case '2':
            {
                int key;
                cout << "Ingrese la clave del album: ";
                cin >> key;
                int pos = this->searchAlbum(key);
                if(pos!=-1)
                {
                    cout << "Album encontrado! \n";
                    this->albums[pos].show();
                }
                else
                {
                    cout << "No se encontro el album :(\n";
                }
                break;
            }
            case '3':
            {
                int key;
                cout << "Ingrese la clave del album: ";
                cin >> key;
                int pos = this->searchAlbum(key);
                if(pos!=-1)
                {
                    cout << "Album encontrado! \n";
                    this->albums[pos].modify();
                }
                else
                {
                    cout << "No se encontro el album :(\n";
                }
                break;
            }
            case '4':
            {
                int key;
                cout << "Ingrese la clave del album: ";
                cin >> key;
                int pos = this->searchAlbum(key);
                if(pos!=-1)
                {
                    for(int i=pos; i<this->albumCount-1; i++)
                    {
                        this->albums[i] = this->albums[i+1];
                    }
                    cout << "Album eliminado :( \n";
                    this->albumCount--;

                }
                else
                {
                    cout << "No se encontro el album :(\n";
                }
                break;
            }
            case '5':
                return;
            default:
                cout << "Seleccione una opcion valida\n";
        }
        system("pause");
    }while(option!='5');
}

void Manager::menu()
{
    char option;
    do
    {
        system("cls");
        cout << "Bienvenido al sistema de disquera, Que desea hacer hoy?\n";
        cout << "Administrar:\n1.-Albums\n2.-Artistas\n3.-Vendedores\n4.-Clientes\n5.-Ventas\n6.-Salir\nSu seleccion:";
        cin >> option;
        switch(option)
        {
        case '1':
            this->albumMenu();
            break;
        case '2':
            this->artistMenu();
            break;
        case '3':
            this->clientMenu();
        case '6':
            break;
        default:
            cout << "Aun no lo hago diskulp";
        }
    }while(option!= '6');
}