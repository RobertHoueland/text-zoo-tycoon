#include "animal.h"

Animal::Animal(){
    age = 48;
    babies = 0;
    food_cost = 80;
}

void Animal::set_age(const int new_age){
    this->age = new_age;
}

int Animal::get_age() const{
    return this->age;
}

void Animal::set_cost(const int new_cost){
    this->cost = new_cost;
}

int Animal::get_cost() const{
    return this->cost;
}

void Animal::set_babies(const int new_babies){
    this->age = new_babies;
}

int Animal::get_babies() const{
    return this->babies;
}

void Animal::set_food_cost(const int new_food_cost){
    this->food_cost = new_food_cost;
}

int Animal::get_food_cost() const{
    return this->food_cost;
}

void Animal::set_revenue(const int new_revenue){
    this->revenue = new_revenue;
}

int Animal::get_revenue() const{
    return this->revenue;
}