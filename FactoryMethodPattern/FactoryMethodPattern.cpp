#include <bits/stdc++.h>
using namespace std;

// product abstract class;
class Animal {
public:
    string animalType;
    Animal(string _animalType) {
        this->animalType = _animalType;
    }

    virtual string getAnimalType() = 0;
};

// factory Abstract class
class Factory {
public:
    virtual Animal* animalFactory() = 0;
};

// concrete Products
class Cat : public Animal {
public:
    Cat(string _animalType = "cat") : Animal(_animalType) {}

    string getAnimalType() {
        return this->animalType;
    }
};

class Dog : public Animal {
public:
    Dog(string _animalType = "dog") : Animal(_animalType) {}

    string getAnimalType() {
        return this->animalType;
    }
};

class Bird : public Animal {
public:
    Bird(string _animalType = "bird") : Animal(_animalType) {}

    string getAnimalType() {
        return this->animalType;
    }
};

// concrete Factories
class RandomAnimalFactory : public Factory {
    // creates an animal at random
    Animal* animalFactory() {
        srand(time(0));
        int ri = rand() % 3;

        if(ri == 0)
            return new Cat();
        if(ri == 1)
            return new Dog();
        return new Bird();
    }
};


int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    Factory* factory = new RandomAnimalFactory();
    Animal* animal = factory->animalFactory();
    cout << animal->getAnimalType();
    return 0;
}