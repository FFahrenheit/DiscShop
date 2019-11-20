void menu()
{
    int option;
    cout << "\nMENU\n1.-Capturar\n2.-Mostrar\n3.-Buscar\n4.-Salir\nOpcion: ";
    cin >> option;
    switch(option)
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
            if(artist.search(clave))
            {
                artist.show();
            }
            else
            {
                cout << "NO EXISTE EL ARTISTA";
            }
            break;
        case 4:
            return;
    }
    menu();
}

int main()
{
    menu();
    return 0;
}