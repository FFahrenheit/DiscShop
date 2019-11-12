#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

class Client
{
    public:
        Client() = default;
        ~Client() = default;
        bool search(int);
        void show();
        void capture(int);
        void modify();
    protected:
    private:
        std::string name;
        int key;
        double phone;
        std::string address;
};

#endif // CLIENT_H
