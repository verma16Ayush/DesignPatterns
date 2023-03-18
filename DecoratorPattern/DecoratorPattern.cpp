#include <bits/stdc++.h>
using namespace std;

class Beverage {
public:
    void getDescription();
    virtual int getCost() = 0;
};

class AddOnDecorator : public Beverage {
public: 
    Beverage* beverage;
    AddOnDecorator(Beverage* _beverage) {
        this->beverage = _beverage;
    }
    virtual int getCost() = 0;
};


class Espresso : public Beverage {
    int cost;
public:
    Espresso(int _cost = 2) {
        this->cost = _cost;
    }

    int getCost() {
        return this->cost;
    }
};

class Decaf : public Beverage {
    int cost;
public:
    Decaf(int _cost = 1) {
        this->cost = _cost;
    }

    int getCost() {
        return this->cost;
    }
};

class Caramel : public AddOnDecorator {
    int cost;
public:
    Caramel(Beverage* _beverage, int _cost = 2) : AddOnDecorator(_beverage) {
        this->cost = _cost;
    }

    int getCost() {
        return this->beverage->getCost() + this->cost;
    }
};

class Chocolate : public AddOnDecorator {
    int cost;
public:
    Chocolate(Beverage* _beverage, int _cost = 5) : AddOnDecorator(_beverage) {
        this->cost = _cost;
    }

    int getCost() {
        return this->beverage->getCost() + this->cost;
    }
};

class SoyMilk : public AddOnDecorator {
    int cost;
public: 
    SoyMilk(Beverage* _beverage, int _cost = 10) : AddOnDecorator(_beverage) {
        this->cost = _cost;
    }
    
    int getCost() {
        return this->beverage->getCost() + this->cost;
    }
};
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Beverage* beverage = new SoyMilk(new Chocolate(new Espresso()));
    cout << beverage->getCost() << endl;
    return 0;
}