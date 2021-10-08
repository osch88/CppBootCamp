#ifndef SHOP_H
#define SHOP_H

#include <iostream>


/*
    Date the customer visited
    Services performed ( at least 2 differnt services )
    Parts changed ( at least 2 different parts )
    Payment ( methods & amount )
*/

class Shop
{
    public:
        Shop() = default;
        ~Shop() = default;
        void print();

};

#endif