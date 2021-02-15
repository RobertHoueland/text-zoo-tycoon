#include "sea_lion.h"
#include <cstdlib> //rand()

Sealion::Sealion(){
    cost = 800;
    revenue = 160;
    food_cost = 1;
    babies = 0;
}

int Sealion::get_cost() const{
    return this->cost;
}

float Sealion::get_revenue() const{
    return this->revenue;
}

int Sealion::get_extra_revenue() const{
    return rand() % 251 + 150;
}

int Sealion::get_food_cost() const{
    return this->food_cost;
}

void Sealion::set_babies(const int new_babies){
    this->babies = new_babies;
}

int Sealion::get_babies() const{
    return this->babies;
}