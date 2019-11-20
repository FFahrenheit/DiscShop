#include <iostream>

using namespace std;

class Artist
{
    public:
        Artist();
        ~Artist(){};
        void show();
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

Artist artist;

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
                artist.capture();
                break;
            case 2:
                artist.show();
                break;
            case 3:
                int clave;
                cout << "Ingrese clave a buscar: ";
                cin >> clave;
                if (artist.search(clave))
                {
                    artist.show();
                }
                else
                {
                    cout << "NO EXISTE EL ARTISTA";
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