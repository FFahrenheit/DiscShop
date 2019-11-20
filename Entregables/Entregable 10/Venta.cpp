#include <iostream>

using namespace std;

class Sale
{
    public:
        Sale() = default;
        ~Sale() = default;
        void show();
        void capture(int, int, int, int);
        bool search(int);
    protected:
    private:
        int key;
        int albumCode;
        int clientCode;
        int sellerCode;
        string concept;
};


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

Sale sales[20];
int saleAutoIncrement=0;
int salesCount = 0;

int searchSale(int key)
{
    for(int i=0; i<salesCount; i++)
    {
        if(sales[i].search(key))
        {
            return i;
        }
    }
    return -1;
}

bool newSale()
{
    int album,seller,client,key;
    system("cls");
    cout << "Ingrese la clave del album o single de venta: ";
    cin >> album;
    cout << "Ingrese la clave del vendedor: ";
    cin >> seller;
    cout << "Ingrese la clave del cliente: ";
    cin >> client;
    saleAutoIncrement ++;
    sales[salesCount].capture(saleAutoIncrement,album,seller,client);
    salesCount ++;
    return true;
}

void salesMenu()
{
    char option;
    do
    {
        system("cls");
        cout << "Bienvenido al panel de control de ventas, seleccione la opción correspondiente:"<<endl;
        cout << "0.-Nueva venta\n1.-Listar ventas\n2.-Buscar y ver detalles\n3.-Modificar\n4.-Eliminar\n5.-Salir\nSu seleccion: ";
        cin >> option;
        system("cls");
        switch(option)
        {
            case '0':
            {
                newSale();
                break;
            }
            case '1':
            {
                cout << ((salesCount == 0)? "Vacio\n" : "Ventas:\n");
                for(int i=0; i<salesCount; i++)
                {
                    sales[i].show();
                    cout << "-----------------------------------------------------"<<endl;
                }
                break;
            }
            case '2':
            {
                int key;
                cout << "Ingrese la clave de la venta: ";
                cin >> key;
                int pos = searchSale(key);
                if(pos!=-1)
                {
                    cout << "Venta encontrada! \n";
                    sales[pos].show();
                }
                else
                {
                    cout << "No se encontro la venta :(\n";
                }
                break;
            }
            case '3':
            {
                cout << "Nuestro sistema de ventas es delicado\nSi desea modificar una venta, eliminela y vuelvala a capturar con los datos correctos";
                break;
            }
            case '4':
            {
                int key;
                cout << "Ingrese la clave de la venta: ";
                cin >> key;
                int pos = searchSale(key);
                if(pos!=-1)
                {
                    for(int i=pos; i<salesCount-1; i++)
                    {
                        sales[i] = sales[i+1];
                    }
                    cout << "Venta eliminada :( \n";
                    salesCount--;

                }
                else
                {
                    cout << "No se encontro la venta :(\n";
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
    salesMenu();
    return 0;
}