#include <iostream>

using namespace std;

class Album
{
    public:
        void modify();
        bool search(int);
        void show();
        void capture(int);
    private:
        int key;
        string name;
        int artistCode;
        int year;
        float price;
        string genre;
};

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

Album albums[20];
int albumCount = 0;

int searchAlbum(int code)
{
    for(int i=0; i<albumCount;i++)
    {
        if(albums[i].search(code))
        {
            return i;
        }
    }
    return -1;
}

void albumMenu()
{
    char option;
    do
    {
        system("cls");
        cout << "Bienvenido al panel de control de albums, seleccione la opción correspondiente:"<<endl;
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
                int pos = searchAlbum(code);
                if(pos == -1)
                {
                    albums[albumCount].capture(code);
                    albumCount++;
                }
                else
                {
                    cout << "Error! Codigo repetido\n";
                }
                break;
            }
            case '1':
            {
                cout << ((albumCount == 0)? "Vacio\n" : "Albums:\n");
                for(int i=0; i<albumCount; i++)
                {
                    albums[i].show();
                    cout << "-----------------------------------------------------"<<endl;
                }
                break;
            }
            case '2':
            {
                int key;
                cout << "Ingrese la clave del album: ";
                cin >> key;
                int pos = searchAlbum(key);
                if(pos!=-1)
                {
                    cout << "Album encontrado! \n";
                    albums[pos].show();
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
                int pos = searchAlbum(key);
                if(pos!=-1)
                {
                    cout << "Album encontrado! \n";
                    albums[pos].modify();
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
                int pos = searchAlbum(key);
                if(pos!=-1)
                {
                    for(int i=pos; i<albumCount-1; i++)
                    {
                        albums[i] = albums[i+1];
                    }
                    cout << "Album eliminado :( \n";
                    albumCount--;

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

int main()
{
    albumMenu();
    return 0;
}