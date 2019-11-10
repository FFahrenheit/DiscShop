#ifndef SELLER_H
#define SELLER_H

#include <iostream>

class Seller
{
    public:
        Seller();
        virtual ~Seller();
        bool search(int);
        void show();
        void capture(int);
        void modify();
    protected:
    private:
        int key;
        std::string name;
        float salary;
        std::string address;
        double phone;
};

#endif // SELLER_H
