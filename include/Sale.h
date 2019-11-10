#ifndef SALE_H
#define SALE_H
#include <iostream>

class Sale
{
    public:
        Sale();
        virtual ~Sale();
        void show();
        void capture(int, int, int, int);
        bool search(int);
    protected:
    private:
        int key;
        int albumCode;
        int clientCode;
        int sellerCode;
        std::string concept;
};

#endif // SALE_H
