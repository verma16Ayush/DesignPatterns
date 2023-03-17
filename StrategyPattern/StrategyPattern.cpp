#include <bits/stdc++.h>
using namespace std;

// interface (Abstract Class)
class IQuackBehavior{
public:
    virtual void quack() = 0;
};

// interface (Abstract Class)
class IFlyBehavior{
public:
    virtual void fly() = 0;
};

// interface (Abstract Class)
class IDisplayBehavior{
public:
    virtual void display() = 0;
};

// concrete definition for flying
class SimpleFly : public IFlyBehavior {
public:
    void fly(){
        cout << "flying simply lol" << endl;
    }
};

class JetFly : public IFlyBehavior {
public:
    void fly(){
        cout << "flying with a jetpack!!! wheee" <<endl;
    }
};

class NoFly : public IFlyBehavior {
public:
    void fly(){
        throw std::invalid_argument("flying not allowed for this duck. there must be a mistake!");
    }
};

// concrete definition for display
class GraphicDisplay: public IDisplayBehavior{
public:
    void display(){
        cout << "🦆" << endl;
    }
};

class TextDisplay: public IDisplayBehavior {
public:
    void display(){
        cout << "yep, that's a duck alright" << endl;
    }
};

// concrete Definition for quacks
class SimpleQuack : public IQuackBehavior{
public:
    void quack(){
        cout << "simply quacking" << endl;
    }
};

class NoQuack : public IQuackBehavior {
public:
    void quack(){
        throw std::invalid_argument("quacking not allowed for this duck type. there must be a mistake");
    }
};

class Duck{
private:
    IQuackBehavior* quackBehavior;
    IFlyBehavior* flyBehavior;
    IDisplayBehavior* displayBehavior;
public:
    Duck(IQuackBehavior* quackBehavior, IFlyBehavior* flyBehavior, IDisplayBehavior* displayBehavior){
        this->quackBehavior = quackBehavior;
        this->flyBehavior = flyBehavior;
        this->displayBehavior = displayBehavior;
    }

    void fly(){
        this->flyBehavior->fly();
    }

    void display(){
        this->displayBehavior->display();
    }

    void quack(){
        this->quackBehavior->quack();
    }
};


int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // composing our object. with dependency injections
    Duck normalDuck(new SimpleQuack(), new SimpleFly(), new GraphicDisplay());
    normalDuck.fly();
    normalDuck.display();
    normalDuck.quack();

    // Duck rubberDuck(new NoQuack(), new NoFly(), new GraphicDisplay());
    // rubberDuck.display();
    // rubberDuck.fly();
    // rubberDuck.quack();

    Duck superDuck(new SimpleQuack(), new JetFly(), new GraphicDisplay());
    superDuck.fly();
    superDuck.quack();
    superDuck.display();
    return 0;
}