#ifndef MANAGER_H
#define MANAGER_H

#include "Album.h"
#include "Artist.h"
#include "Client.h"
#include "Seller.h"
#include "Sale.h"

class Manager
{
    public:
        Manager();
        virtual ~Manager();
        void menu();
    protected:
    private:
        int albumCount;
        int artistCount;
        int clientCount;
        int sellerCount;
        int salesCount;
        int saleAutoIncrement;
        Artist artists[20];
        Album albums[20];
        Client clients[20];
        Seller sellers[20];
        Sale sales[40];
        void albumMenu();
        void artistMenu();
        void clientMenu();
        void sellerMenu();
        void salesMenu();
        bool newSale();
        int searchSeller(int);
        int searchAlbum(int);
        int searchArtist(int);
        int searchClient(int);
        int searchSale(int);
};

#endif // MANAGER_H
