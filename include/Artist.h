#ifndef ARTIST_H
#define ARTIST_H

#include <iostream>

class Artist
{
    public:
        Artist();
        virtual ~Artist();
        void show();
        bool search(int);
        void capture(int);
        void modify();
    protected:
    private:
        int key;
        int formation;
        std::string name;
        std::string genre;
        std::string country;
};

#endif // ARTIST_H
