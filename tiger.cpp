#include "tiger.h"

Tiger::Tiger(){
    cost = 15000;
    revenue = 1500;
    food_cost = 5;
    babies = 0;
}

int Tiger::get_cost() const{
    return this->cost;
}

float Tiger::get_revenue() const{
    return this->revenue;
}

int Tiger::get_food_cost() const{
    return this->food_cost;
}

void Tiger::set_babies(const int new_babies){
    this->babies = new_babies;
}

int Tiger::get_babies() const{
    return this->babies;
}