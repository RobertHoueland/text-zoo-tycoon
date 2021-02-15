#ifndef SEA_LION_H
#define SEA_LION_H

#include "animal.h"

class Sealion : public Animal{
    public:
        Sealion();

        int get_cost() const;
        float get_revenue() const;
        int get_extra_revenue() const;
        int get_food_cost() const;
        void set_babies(const int new_babies);
        int get_babies() const;
};

#endif