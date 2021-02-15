#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
    protected:
        int age;
        int cost;
        int babies;
        int food_cost;
        float revenue;
    public:
        Animal();

        void set_age(const int);
        int get_age() const;
        void set_cost(const int);
        int get_cost() const;
        void set_babies(const int);
        int get_babies() const;
        void set_food_cost(const int);
        int get_food_cost() const;
        void set_revenue(const int);
        int get_revenue() const;
};

#endif