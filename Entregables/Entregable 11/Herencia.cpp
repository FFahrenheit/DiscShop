#include <iostream>

using namespace std;

class Album
{
    public:
        void modify();
        bool search(int);
        void show();
        void capture(int);
    protected:
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

class Single : public Album
{
    public:
        Single() = default;
        ~Single() = default;
        virtual void show();
        virtual void capture(int);
        virtual void modify();
    protected:
    private:
        int lenght;
};

void Single::show()
{
    Album::show();
    cout << "Duracion: " << this->lenght<<endl;
}

void Single::capture(int code)
{
    cout << "Ingrese la duracion: ";
    cin >> this->lenght;
    Album::capture(code);
}

void Single::modify()
{
    char option;
    cout << "Que desea modificar?\n0.-Nombre\n1.-Clave\n2.-Lanzamiento\n3.-Genero\n4.-Precio\n5.-Artista\n5.-Duracion\nSu eleccion: ";
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
        case '6':
            cin >> this->lenght;
        default:
            return;
    }
}

Album albums[20];
int albumCount = 0;
Single singles[20];
int singleCount = 0;

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

int searchSingle(int code)
{
    for(int i=0; i<singleCount;i++)
    {
        if(singles[i].search(code))
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

void singleMenu()
{
    char option;
    do
    {
        system("cls");
        cout << "Bienvenido al panel de control de singles, seleccione la opción correspondiente:"<<endl;
        cout << "0.-Nuevo album\n1.-Listar albumes\n2.-Buscar y ver detalles\n3.-Modificar\n4.-Eliminar\n5.-Salir\nSu seleccion: ";
        cin >> option;
        system("cls");
        switch(option)
        {
            case '0':
            {
                int code;
                cout << "Ingrese el codigo para el single: ";
                cin >> code;
                int pos = searchSingle(code);
                if(pos == -1)
                {
                    singles[singleCount].capture(code);
                    singleCount++;
                }
                else
                {
                    cout << "Error! Codigo repetido\n";
                }
                break;
            }
            case '1':
            {
                cout << ((singleCount == 0)? "Vacio\n" : "singles:\n");
                for(int i=0; i<singleCount; i++)
                {
                    singles[i].show();
                    cout << "-----------------------------------------------------"<<endl;
                }
                break;
            }
            case '2':
            {
                int key;
                cout << "Ingrese la clave del single: ";
                cin >> key;
                int pos = searchSingle(key);
                if(pos!=-1)
                {
                    cout << "single encontrado! \n";
                    singles[pos].show();
                }
                else
                {
                    cout << "No se encontro el single :(\n";
                }
                break;
            }
            case '3':
            {
                int key;
                cout << "Ingrese la clave del single: ";
                cin >> key;
                int pos = searchSingle(key);
                if(pos!=-1)
                {
                    cout << "single encontrado! \n";
                    singles[pos].modify();
                }
                else
                {
                    cout << "No se encontro el single :(\n";
                }
                break;
            }
            case '4':
            {
                int key;
                cout << "Ingrese la clave del single: ";
                cin >> key;
                int pos = searchSingle(key);
                if(pos!=-1)
                {
                    for(int i=pos; i<singleCount-1; i++)
                    {
                        singles[i] = singles[i+1];
                    }
                    cout << "single eliminado :( \n";
                    singleCount--;

                }
                else
                {
                    cout << "No se encontro el single :(\n";
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
    char opc;
    do
    {
        system("cls");
        cout << "Ingrese el control que desea\n1.-Albums\n2.-Singles\n3.-Salir\nOpcion: ";
        cin >> opc; 
        switch(opc)
        {
            case '1':
                albumMenu();
                break;
            case '2':
                singleMenu();
                break;
            case '3':
                cout << "Gracias por su visita\n";
                break;
            default:
                cout << "Ingrese una opcion valida\n";
                break;
        }
        system("pause");
    }while(opc!='3');
    return 0;
}