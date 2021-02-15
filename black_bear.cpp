#include "black_bear.h"

Blackbear::Blackbear(){
    cost = 6000;
    revenue = 600;
    food_cost = 3;
    babies = 0;
}

int Blackbear::get_cost() const{
    return this->cost;
}

float Blackbear::get_revenue() const{
    return this->revenue;
}

int Blackbear::get_food_cost() const{
    return this->food_cost;
}

void Blackbear::set_babies(const int new_babies){
    this->babies = new_babies;
}

int Blackbear::get_babies() const{
    return this->babies;
}