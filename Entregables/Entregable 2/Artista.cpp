#include <iostream>

using namespace std;

class Artist
{
    public:
        Artist(){};
        ~Artist(){};
        void show();
        void capture();
    protected:
    private:
        int key;
        int formation;
        string name;
        string genre;
        string country;
};

void Artist::show()
{
    cout << "Clave: "<<this->key << endl;
    cout << "Nombre: "<<this->name << endl;
    cout << "Pais de origen: "<<this->country << endl;
    cout << "Formado en: "<<this->formation << endl;
    cout << "Genero: " << this->genre << endl;
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

int main()
{
    Artist artist;
    artist.capture();
    cout << "---------------------";
    artist.show();
    return 0;
}