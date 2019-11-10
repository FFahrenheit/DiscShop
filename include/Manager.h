#ifndef MANAGER_H
#define MANAGER_H

#include "Album.h"
#include "Artist.h"
#include "Client.h"
#include "Seller.h"

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
        Artist artists[20];
        Album albums[20];
        Client clients[20];
        Seller sellers[20];
        void albumMenu();
        void artistMenu();
        void clientMenu();
        void sellerMenu();
        int searchSeller(int key);
        int searchAlbum(int key);
        int searchArtist(int key);
        int searchClient(int key);
};

#endif // MANAGER_H
