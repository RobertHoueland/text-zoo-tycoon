#ifndef BLACK_BEAR_H
#define BLACK_BEAR_H

#include "animal.h"

class Blackbear : public Animal{
    public:
        Blackbear();

        int get_cost() const;
        float get_revenue() const;
        int get_food_cost() const;
        void set_babies(const int new_babies);
        int get_babies() const;
};

#endif