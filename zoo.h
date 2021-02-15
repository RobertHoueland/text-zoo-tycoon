#ifndef ZOO_H
#define ZOO_H

#include "animal.h"
#include "sea_lion.h"
#include "tiger.h"
#include "black_bear.h"

class Zoo{
    private:
        int bank_amount;
        int month;
        int event;
        int numSeaLions;
        int numTigers;
        int numBlackBears;
        Sealion* sealionarray;
        Tiger* tigerarray;
        Blackbear* blackbeararray;
        Animal animal;
        Sealion sealion;
        Tiger tiger;
        Blackbear blackbear;
    public:
        Zoo();
        Zoo(int);
        ~Zoo();

        void set_bank(const int);
        int get_bank() const;

        void start_game();
        void print_game();
        int animal_choice();
        int animal_amount(int);
        void buy_animal(int, int);
        int food_type();
        void monthly_food(int);
        int check_bank();
        void special_event(int);
        void animal_sick();
        void give_birth();
        void monthly_revenue();
        void add_sealion();
        void add_tiger();
        void add_blackbear();
        void remove_sealion();
        void remove_tiger();
        void remove_blackbear();
        void sealion_art();
        void tiger_art();
        void blackbear_art();
};

#endif