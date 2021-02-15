#ifndef TIGER_H
#define TIGER_H

#include "animal.h"

class Tiger : public Animal{
    public:
        Tiger();

        int get_cost() const;
        float get_revenue() const;
        int get_food_cost() const;
        void set_babies(const int new_babies);
        int get_babies() const;
};

#endif