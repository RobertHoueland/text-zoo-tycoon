#include <iostream>
#include <cstdlib> //rand()
#include "zoo.h"
#include "animal.h"

using namespace std;

/* Default constructor to initalize variables */
Zoo::Zoo(){
    bank_amount = 0;
    month = 1;
    event = 0;
    numSeaLions = 0;
    numTigers = 0;
    numBlackBears = 0;
    /* Dynamic arrays of animals */
    sealionarray = new Sealion[numSeaLions];
    tigerarray = new Tiger[numTigers];
    blackbeararray = new Blackbear[numBlackBears];
}

/* Constructor to initalize variables and bank amount to any input given amount */
Zoo::Zoo(int amount){
    bank_amount = amount;
    month = 1;
    event = 0;
    numSeaLions = 0;
    numTigers = 0;
    numBlackBears = 0;
    /* Dynamic arrays of animals */
    sealionarray = new Sealion[numSeaLions];
    tigerarray = new Tiger[numTigers];
    blackbeararray = new Blackbear[numBlackBears];
}

/* Destructor to free and delete memory */
Zoo::~Zoo(){
    delete [] sealionarray;
    sealionarray = NULL;
    delete [] tigerarray;
    tigerarray = NULL;
    delete [] blackbeararray;
    blackbeararray = NULL;
}

/*******************************************************************
   ** Function: start_game
   ** Description: Starts the game
   ** Parameters: None
   ** Pre-Conditions: Start of game
   ** Post-Conditions: Game continues after
   *******************************************************************/
void Zoo::start_game(){
    /* Clear screen */
    cout << string(50, '\n');
    cout << "Welcome to Zoo Tycoon!" << endl;
}

/*******************************************************************
   ** Function: print_game
   ** Description: Print game status, with bank amount and month
   ** Parameters: None
   ** Pre-Conditions: Game has to be at start of month
   ** Post-Conditions: Game continues after
   *******************************************************************/
void Zoo::print_game(){
    cout << "--------------------------------------------------------" << endl;
    cout << "You have " << bank_amount << " dollars." << endl;
    cout << "You are on month " << month << "." << endl;
    cout << "You have " << numSeaLions - sealion.get_babies();
    cout << " adult sea lions, and " << sealion.get_babies();
    cout << " baby sea lions." << endl;
    cout << "You have " << numTigers - tiger.get_babies();
    cout << " adult tigers, and " << tiger.get_babies();
    cout << " baby tigers." << endl;
    cout << "You have " << numBlackBears - blackbear.get_babies();
    cout << " adult black bears, and " << blackbear.get_babies();
    cout << " baby black bears." << endl;
}

/*******************************************************************
   ** Function: animal_choice
   ** Description: Gives user option to buy animal
   ** Parameters: None
   ** Pre-Conditions: Start of month
   ** Post-Conditions: Returns user's choice
   *******************************************************************/
int Zoo::animal_choice(){
    int choice;
    cout << "--------------------------------------------------------" << endl;
    do{
        cout << "Which animal would you like to buy?" << endl;
        cout << "None: Press 0" << endl;
        cout << "Sea Lion: Press 1 ($800 each)" << endl;
        cout << "Tiger: Press 2 ($15,000 each)" << endl;
        cout << "Black Bear: Press 3 ($6,000 each)" << endl;
        cout << "Quit Game: Press 4" << endl;
        cin >> choice;
        if (choice < 0 || choice > 4)
            cout << endl << "Invalid input. Please retry." << endl << endl;
        cout << endl;
    } while (choice < 0 || choice > 4);
    return choice;
}

/*******************************************************************
   ** Function: animal_amount
   ** Description: Gives user option to buy 1 or 2 animals
   ** Parameters: Choice of previous function output for which animal
   ** Pre-Conditions: Start of month
   ** Post-Conditions: Returns user's amount
   *******************************************************************/
int Zoo::animal_amount(int choice){
    int amount = 0;
    if (choice == 0)
        return 0;
    do{
        if (choice == 1){
            sealion_art();
            cout << "How many sea lions would you like to buy? (1 or 2): ";
            cin >> amount;
        }
        if (choice == 2){
            tiger_art();
            cout << "How many tigers would you like to buy? (1 or 2): ";
            cin >> amount;
        }
        if (choice == 3){
            blackbear_art();
            cout << "How many black bears would you like to buy? (1 or 2): ";
            cin >> amount;
        }
        if (amount < 1 || amount > 2)
            cout << endl << "Invalid input. Please retry." << endl << endl;
    } while (amount < 1 || amount > 2);
    return amount;
}

/*******************************************************************
   ** Function: buy_animal
   ** Description: Changes bank account
   ** Parameters: Choice of animal and amount
   ** Pre-Conditions: After user chooses animals
   ** Post-Conditions: Change bank account
   *******************************************************************/
void Zoo::buy_animal(int choice, int amount){
    if (choice == 1){
        bank_amount -= sealion.get_cost() * amount;
        numSeaLions += amount;
        sealionarray[numSeaLions].set_age(48);
        add_sealion();
    }
    if (choice == 2){
        bank_amount -= tiger.get_cost() * amount;
        numTigers += amount;
        tigerarray[numTigers].set_age(48);
        add_tiger();
    }
    if (choice == 3){
        bank_amount -= blackbear.get_cost() * amount;
        numBlackBears += amount;
        blackbeararray[numBlackBears].set_age(48);
        add_blackbear();
    }
}

/*******************************************************************
   ** Function: food_type
   ** Description: Allows user to choose type of food
   ** Parameters: None
   ** Pre-Conditions: Before food is bought
   ** Post-Conditions: Changes food
   *******************************************************************/
int Zoo::food_type(){
    int type;
    do{
        cout << endl;
        cout << "Which type of food would you like to buy for your animals?";
        cout << endl << "Regular: Press 1" << endl;
        cout << "Premium (twice as expensive, less chance of getting sick): Press 2";
        cout << endl << "Cheap (half cost, higher chance of getting sick): Press 3";
        cout << endl;
        cin >> type;
        cout << string(50, '\n');
        if (type < 1 || type > 3)
            cout << endl << "Invalid input. Please retry." << endl << endl;
    } while (type < 1 || type > 3);
    return type;
}

/*******************************************************************
   ** Function: monthly_repeat
   ** Description: Runs monthly events
   ** Parameters: Animal reference, int type of food
   ** Pre-Conditions: Runs at end of month
   ** Post-Conditions: Changes food cost
   *******************************************************************/
void Zoo::monthly_food(int type){
    month ++;
    /* Increment ages */
    int sealionbabies = sealion.get_babies();
    int tigerbabies = tiger.get_babies();
    int blackbearbabies = blackbear.get_babies();
    cout << "BABIES " << sealionbabies << endl;
    for (int i = 0; i < numSeaLions; i++){
        if (sealionarray[i].get_age() == 6 && sealionbabies > 0){
            sealionbabies -= 1;
            sealion.set_babies(sealionbabies);
        }
        int newage = sealionarray[i].get_age();
        newage++;
        sealionarray[i].set_age(newage);
    }
    for (int i = 0; i < numTigers; i++){
        if (tigerarray[i].get_age() == 6 && tigerbabies > 0){
            tigerbabies -= 1;
            tiger.set_babies(tigerbabies);
        }
        int newage = tigerarray[i].get_age();
        newage++;
        tigerarray[i].set_age(newage);
    }
    for (int i = 0; i < numBlackBears; i++){
        if (blackbeararray[i].get_age() == 6 && blackbearbabies > 0){
            blackbearbabies -= 1;
            blackbear.set_babies(blackbearbabies);
        }
        int newage = blackbeararray[i].get_age();
        newage++;
        blackbeararray[i].set_age(newage);
    }
    event = (rand() % 5);
    animal.set_food_cost(((event * 10) + 80) * 0.8);
    float cost = numSeaLions * sealion.get_food_cost();
    cost += numTigers * tiger.get_food_cost();
    cost += numBlackBears * blackbear.get_food_cost();
    float food = animal.get_food_cost() * cost;
    if (type == 2)
        food *= 2;
    if (type == 3)
        food /= 2;
    bank_amount -= food;
    cout << "You paid $" << food << " for food for the month." << endl;
}

/*******************************************************************
   ** Function: check_bank
   ** Description: Checks if bank account is empty
   ** Parameters: None
   ** Pre-Conditions: Runs in loop
   ** Post-Conditions: Outputs whether bank account is empty
   *******************************************************************/
int Zoo::check_bank(){
    if (bank_amount < 1)
        return 1;
    return 0;
}

/*******************************************************************
   ** Function: special_event
   ** Description: Runs special monthly event randomly
   ** Parameters: Int type of food
   ** Pre-Conditions: Runs each month
   ** Post-Conditions: Causes special event
   *******************************************************************/
void Zoo::special_event(int type){
    int event = (rand() % 4);
    /* Normal food chance */
    if (type == 1)
        event = (rand() % 4);
    /* Premium food chance */
    if (type == 2)
        event = (rand() % 6 + 4);
    /* Cheap food chance */
    if (type == 3)
        event = (rand()) % 5 + 10;
    if (event == 1 || event == 5 || event == 11 || event == 12)
        animal_sick();
    if (event == 2 || event == 6 || event == 7 || event == 13)
        give_birth();
    if (event == 3 || event == 8 || event == 9 || event == 14){
        cout << endl << "A boom in zoo attendance has occured!" << endl;
        int extra = sealion.get_extra_revenue() * numSeaLions;
        bank_amount += extra;
        cout << "You have earned $" << extra << " from your ";
        cout << numSeaLions << " sea lions!" << endl;
    }
}

/*******************************************************************
   ** Function: animal_sick
   ** Description: Runs event if animal is sick
   ** Parameters: None
   ** Pre-Conditions: Runs if random special event picks it
   ** Post-Conditions: Random animal gets sick
   *******************************************************************/
void Zoo::animal_sick(){
    int animal = rand() % 3;
    int baby = rand() % 2;
    /* Sea lion gets sick */
    if (animal == 0 || (numTigers == 0 && numBlackBears == 0)){
        /* Baby sea lion gets sick */
        if (baby == 0 && sealion.get_babies() > 0){
            cout << endl << "Oh no! One of your baby sea lions has gotten sick!";
            cout << endl << "You will need to pay $800 to care for it." << endl;
            if (bank_amount < sealion.get_cost()){
                cout << "You do not have enough money, it will die." << endl;
                numSeaLions -= 1;
                int babies = sealion.get_babies();
                babies--;
                sealion.set_babies(babies);
                remove_sealion();
            }
            else
                bank_amount -= sealion.get_cost();
        }
        /* Adult sea lion gets sick */
        if ((baby == 1 || sealion.get_babies() < 1) && (numSeaLions - sealion.get_babies() > 0)){
            cout << endl << "Oh no! One of your sea lions has gotten sick!" << endl;
            cout << "You will need to pay $400 to care for it." << endl;
            if (bank_amount < sealion.get_cost() * 0.5){
                cout << "You do not have enough money, it will die." << endl;
                numSeaLions -= 1;
                remove_sealion();
            }
            else
                bank_amount -= sealion.get_cost() * 0.5;
        }
    }
    /* Tiger gets sick */
    else if (animal == 1 || (numSeaLions == 0 && numBlackBears == 0)){
        /* Baby tiger gets sick */
        if (baby == 0 && tiger.get_babies() > 0){
            cout << endl << "Oh no! One of your baby tigers has gotten sick!";
            cout << endl << "You will need to pay $15,000 to care for it." << endl;
            if (bank_amount < tiger.get_cost()){
                cout << "You do not have enough money, it will die." << endl;
                numTigers -= 1;
                int babies = tiger.get_babies();
                babies--;
                tiger.set_babies(babies);
                remove_tiger();
            }
            else
                bank_amount -= tiger.get_cost();
        }
        /* Adult tiger gets sick */
        if ((baby == 1 || tiger.get_babies() < 1) && (numTigers - tiger.get_babies() > 0)){
            cout << endl << "Oh no! One of your tigers has gotten sick!" << endl;
            cout << "You will need to pay $7,500 to care for it." << endl;
            if (bank_amount < tiger.get_cost() * 0.5){
                cout << "You do not have enough money, it will die." << endl;
                numTigers -= 1;
                remove_tiger();
            }
            else
                bank_amount -= tiger.get_cost() * 0.5;
        }
    }
    /* Blackbear gets sick */
    else if (animal == 2 || (numTigers == 0 && numSeaLions == 0)){
        /* Baby black bear gets sick */
        if (baby == 0 && blackbear.get_babies() > 0){
            cout << endl << "Oh no! One of your baby black bears has gotten sick!";
            cout << endl << "You will need to pay $6,000 to care for it." << endl;
            if (bank_amount < blackbear.get_cost()){
                cout << "You do not have enough money, it will die." << endl;
                numBlackBears -= 1;
                int babies = blackbear.get_babies();
                babies--;
                blackbear.set_babies(babies);
                remove_blackbear();
            }
            else
                bank_amount -= blackbear.get_cost();
        }
        /* Adult black bear gets sick */
        if ((baby == 1 || blackbear.get_babies() < 1) && (numBlackBears - blackbear.get_babies() > 0)){
            cout << endl << "Oh no! One of your black bears has gotten sick!"; 
            cout << endl << "You will need to pay $3,000 to care for it." << endl;
            if (bank_amount < blackbear.get_cost() * 0.5){
                cout << "You do not have enough money, it will die." << endl;
                numBlackBears -= 1;
                remove_blackbear();
            }
            else
                bank_amount -= blackbear.get_cost() * 0.5;
        }
    }
}

/*******************************************************************
   ** Function: give_birth
   ** Description: Runs event if animal gives birth
   ** Parameters: None
   ** Pre-Conditions: Runs if random special event picks it
   ** Post-Conditions: Random animal gives birth
   *******************************************************************/
void Zoo::give_birth(){
    int anim = rand() % 3;
    /* Sea lion gives birth */
    if (anim == 0 && (numSeaLions - sealion.get_babies() > 0)){
        cout << "A sea lion has given birth to 1 baby!" << endl;
        numSeaLions++;
        sealionarray[numSeaLions].set_age(0);
        add_sealion();
        int num_babies = sealion.get_babies();
        num_babies++;
        sealion.set_babies(num_babies);
    }
    /* Tiger gives birth */
    if (anim == 1 && (numTigers - tiger.get_babies() > 0)){
        cout << "A tiger has given birth to 3 babies!" << endl;
        numTigers++;
        tigerarray[numTigers].set_age(0);
        add_tiger();
        numTigers++;
        tigerarray[numTigers].set_age(0);
        add_tiger();
        numTigers++;
        tigerarray[numTigers].set_age(0);
        add_tiger();
        int num_babies = tiger.get_babies();
        num_babies += 3;
        tiger.set_babies(num_babies);
    }
    /* Black bear gives birth */
    if (anim == 2 && (numBlackBears - blackbear.get_babies() > 0)){
        cout << "A black bear has given birth to 2 babies!" << endl;
        numBlackBears++;
        blackbeararray[numBlackBears].set_age(0);
        add_blackbear();
        numBlackBears++;
        blackbeararray[numBlackBears].set_age(0);
        add_blackbear();
        int num_babies = blackbear.get_babies();
        num_babies += 2;
        blackbear.set_babies(num_babies);
    }
}

/*******************************************************************
   ** Function: monthly_revenue
   ** Description: Generates revenue for each animal
   ** Parameters: None
   ** Pre-Conditions: Runs at end of each month
   ** Post-Conditions: Bank account is modified
   *******************************************************************/
void Zoo::monthly_revenue(){
    float revenue = (numSeaLions * sealion.get_revenue());
    revenue += (numTigers * tiger.get_revenue());
    revenue += (numBlackBears * blackbear.get_revenue());
    revenue += (sealion.get_babies() * sealion.get_revenue() * 2);
    revenue += (tiger.get_babies() * tiger.get_revenue() * 2);
    revenue += (blackbear.get_babies() * blackbear.get_revenue() * 2);
    bank_amount += revenue;
    cout << endl << "Your animals earned $" << revenue;
    cout << " of revenue this month!" << endl; 
}

/*******************************************************************
   ** Function: add_sealion
   ** Description: Adds a sea lion to array
   ** Parameters: None
   ** Pre-Conditions: Runs when buying sea lion
   ** Post-Conditions: Sea lion array is updated
   *******************************************************************/
void Zoo::add_sealion(){
    Sealion *temparr = new Sealion[numSeaLions + 1];
    for (short i = 0; i < numSeaLions; i++)
        temparr[i] = sealionarray[i];
    delete [] sealionarray;
    sealionarray = temparr;
}

/*******************************************************************
   ** Function: add_tiger
   ** Description: Adds a tiger to array
   ** Parameters: None
   ** Pre-Conditions: Runs when buying tiger
   ** Post-Conditions: Tiger array is updated
   *******************************************************************/
void Zoo::add_tiger(){
    Tiger *temparr = new Tiger[numTigers + 1];
    for (short i = 0; i < numTigers; i++)
        temparr[i] = tigerarray[i];
    delete [] tigerarray;
    tigerarray = temparr;
}

/*******************************************************************
   ** Function: add_blackbear
   ** Description: Adds a black bear to array
   ** Parameters: None
   ** Pre-Conditions: Runs when buying black bear
   ** Post-Conditions: Black bear array is updated
   *******************************************************************/
void Zoo::add_blackbear(){
    Blackbear *temparr = new Blackbear[numBlackBears + 1];
    for (short i = 0; i < numBlackBears; i++)
        temparr[i] = blackbeararray[i];
    delete [] blackbeararray;
    blackbeararray = temparr;
}

/*******************************************************************
   ** Function: remove_sealion
   ** Description: Removes a sea lion from array
   ** Parameters: None
   ** Pre-Conditions: Runs when sea lion dies
   ** Post-Conditions: Sea lion array is updated
   *******************************************************************/
void Zoo::remove_sealion(){
    Sealion *temparr = new Sealion[numSeaLions - 1];
    for (short i = 0; i < numSeaLions; i++)
        temparr[i] = sealionarray[i];
    delete [] sealionarray;
    sealionarray = temparr;
}

/*******************************************************************
   ** Function: remove_tiger
   ** Description: Removes a tiger from array
   ** Parameters: None
   ** Pre-Conditions: Runs when tiger dies
   ** Post-Conditions: Tiger array is updated
   *******************************************************************/
void Zoo::remove_tiger(){
    Tiger *temparr = new Tiger[numTigers - 1];
    for (short i = 0; i < numTigers; i++)
        temparr[i] = tigerarray[i];
    delete [] tigerarray;
    tigerarray = temparr;
}

/*******************************************************************
   ** Function: remove_blackbear
   ** Description: Removes a black bear from array
   ** Parameters: None
   ** Pre-Conditions: Runs when black bear dies
   ** Post-Conditions: Black bear array is updated
   *******************************************************************/
void Zoo::remove_blackbear(){
    Blackbear *temparr = new Blackbear[numBlackBears - 1];
    for (short i = 0; i < numBlackBears; i++)
        temparr[i] = blackbeararray[i];
    delete [] blackbeararray;
    blackbeararray = temparr;
}

/*******************************************************************
   ** Function: sealion_art
   ** Description: Creates sea lion ASCII art (credits to "pb")
   ** Parameters: None
   ** Pre-Conditions: Runs when buying sea lion
   ** Post-Conditions: Outputs art, had to use double backslash to print "\"
   *******************************************************************/
void Zoo::sealion_art(){
    cout << "          -~~~~-" << endl;
    cout << "         |O __ O|" << endl;
    cout << "      -__|_\\__/_|__-" << endl;
    cout << "      ---(__/\\__)---" << endl;
    cout << "        /||~--~||\\" << endl;
    cout << "       / ||    || \\" << endl;
    cout << "      |  `'    `'  |" << endl;
    cout << "    _/ /\\__    __/\\ \\_" << endl;
    cout << "  ~~~~~    ~~~~    ~~~~~" << endl;
}

/*******************************************************************
   ** Function: tiger_art
   ** Description: Creates tiger ASCII art (credits to "fL")
   ** Parameters: None
   ** Pre-Conditions: Runs when buying tiger
   ** Post-Conditions: Outputs art, had to use double backslash to print "\"
   *******************************************************************/
void Zoo::tiger_art(){
    cout << "                         __,,,,_" << endl;
    cout << "          _ __..-;''`--/'/ /.',-`-." << endl;
    cout << "      (`/' ` |  \\ \\ \\ / / / / .-'/`,_" << endl;
    cout << "     /'`\\ \\   |  \\ | \\| // // / -.,/_,'-," << endl;
    cout << "    /<7' ;  \\ \\  | ; ||/ /| | \\/    |`-/,/-.,_,/')" << endl;
    cout << "   /  _.-, `,-\\,__|  _-| / \\ \\/|_/  |    '-/.;.\'" << endl;
    cout << "   `-`  f/ ;      / __/ \\__ `/ |__/ |" << endl;
    cout << "        `-'      |  -| =|\\_  \\  |-' |" << endl;
    cout << "              __/   /_..-' `  ),'  //" << endl;
    cout << "             ((__.-'((___..-'' \\__.'" << endl;
}

/*******************************************************************
   ** Function: blackbear_art
   ** Description: Creates black bear ASCII art holding a honey pot (credits to "mrf")
   ** Parameters: None
   ** Pre-Conditions: Runs when buying black bear
   ** Post-Conditions: Outputs art, had to use double backslash to print "\"
   *******************************************************************/
void Zoo::blackbear_art(){
    cout << "     (()__(()" << endl;
    cout << "     /       \\" << endl;
    cout << "    ( /    \\  \\" << endl;
    cout << "     \\ o o    /" << endl;
    cout << "     (_()_)__/ \\" << endl;
    cout << "    / _,==.____ \\" << endl;
    cout << "   (   |--|      )" << endl;
    cout << "   /\\_.|__|'-.__/\\_" << endl;
    cout << "  / (        /     \\" << endl;
    cout << "  \\  \\      (      /" << endl;
    cout << "   )  '._____)    /" << endl;
    cout << "(((____.--(((____/" << endl;
}