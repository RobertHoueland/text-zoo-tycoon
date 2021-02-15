# text-zoo-tycoon

This game uses classes and inheritance for a zoo tycoon simulator. The player is the owner of the zoo, and there are exhibits of Blackbears, Sealions, and Tigers. The player must take care of these animals and earn money at the zoo. This is done by buying animals, feeding the animals, helping when they are sick, and raising their babies.

There are classes for each animal, that inherit an animal class. They each have unique traits. 

## Traits:

**Age:** 

Animals become adults at 3 years old, and is a baby when less than 30 days old.

**Cost:** 

Blackbears cost $6000 each, Sealions cost $800 each, Tigers cost $15000 each.

**Babies:** 

Blackbears have 2 babies at a time, Sealions have 1 at a time, and Tigers have 3 at a time. Babies cost twice as much to take care of when sick.

**Food Cost:** 

Daily food cost starts at $50 and changes to a random value between 80% and 120% of the base cost from the day before.

Expensive food costs twice as much, but animals get sick more often. Cheap food costs half the price, but animals get sick more often.

Blackbear food costs 3x the base food cost.

Sealion food costs the base food cost.

Tiger food costs 5x the base food cost.

**Revenue:**

Blackbears and tigers produce revenue equal to 10% of their cost each day. ($600 and $1500 respectively)

Sealions produce 20% of their cost each day in revenue ($160) but earn a bonus random amount from $150 to $400 for each Sealion on days with high attendance (Special Event).

Babies earn double revenue. 

## Game:

The owner starts with $100000 and proceeds one day at a time. Each day is a turn. On your turn:

1. The age of each animal increases by one day

2. The owner can buy up to two adult animals of a single species. The owner may only buy one species per day, but they do not have to buy any animals if they don't want to. Each animal starts at 3 years old. This money is taken from the owner's bank account.

3. The owner must pay the feeding cost for each animal in the zoo (including any they just bought). This is automatically subtracted from the owner's bank account each day.

4. A special event occurs. The possible options are: 

    a. One randomly chosen animal gets sick. In order to care for the sick animal, the owner must pay the amount of half the initial cost to buy the animal. If the owner has enough money to cover this cost, it is subtracted from their bank account. If they do not have enough money, then the sick animal dies and is removed from the zoo.

    b. A random chosen adult animal gives birth to babies. Each baby starts with age 0 and is added into the zoo.

    c. A boom in zoo attendance occurs. Sealions earn bonus revenue.

    d. No special event occurs on this day.

5. The owner earns their daily revenue for each animal.

The owner can quit each turn, or the game ends when they go bankrupt. 

### **To run:** Run make, and then run ./zoo_tycoon
