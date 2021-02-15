/******************************************************
** Program: zoo_tycoon.cpp
** Author: Robert Houeland
** Date: 05/10/2020
** Description: Plays a game of zoo tycoon.
** Input: User can own a zoo, and own animals.
** Output: Game has random events.
******************************************************/

#include <iostream>
#include <cstdlib> //srand()
#include <ctime> //time()
#include "animal.h"
#include "zoo.h"
#include "sea_lion.h"
#include "tiger.h"
#include "black_bear.h"

using namespace std;

int main(){
    srand(time(NULL));
    Zoo zoo(100000);
    zoo.start_game();
    int type = 1;
    do{
        zoo.print_game();
        int choice = zoo.animal_choice();
        if (choice == 4)
            return 0;
        int amount = zoo.animal_amount(choice);
        zoo.buy_animal(choice, amount);
        type = zoo.food_type();
        zoo.special_event(type);
        zoo.monthly_revenue();
        zoo.monthly_food(type);
    } while (zoo.check_bank() == 0);
    if (zoo.check_bank() == 1)
        cout << endl << "Game over. You are out of money." << endl << endl;

    return 0;
}