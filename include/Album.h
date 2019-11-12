#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>

class Album
{
    public:
        Album() = default;
        ~Album() = default;
        bool search(int);
        void show();
        void capture(int);
        void modify();
    protected:
        std::string name;
        std::string genre;
        float price;
        int artistCode;
        int year;
        int key;
    private:
};

#endif // ALBUM_H
