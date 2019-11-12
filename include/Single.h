#ifndef SINGLE_H
#define SINGLE_H

#include <Album.h>


class Single : public Album
{
    public:
        Single() = default;
        ~Single() = default;
        virtual void show();
        virtual void capture(int);
        virtual void modify();
    protected:
    private:
        int lenght;
};

#endif // SINGLE_HW
