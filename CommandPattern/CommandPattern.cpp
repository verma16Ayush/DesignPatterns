class ICommand {
public:
    virtual void execute() = 0;
    virtual void unexecute() = 0;
};

class Light {
 // dummy class representing a light
public:
    Light() {}
    void on() {}
    void off() {}
    void dimUp() {}
    void dimDown() {}
};

class LightOnCommand : public ICommand {
    Light light;
public:
    LightOnCommand(Light light){
        this->light = light;
    }
    void execute() {
        this->light.on();
    }
    void unexecute() {
        this->light.off();
    }
};
class LightDimCommand : public ICommand {
    Light light;
public:
    LightDimCommand(Light light){
        this->light = light;
    }
    void execute() {
        this->light.dimDown();
    }
    void unexecute() {
        this->light.dimUp();
    }
};

class Invoker {
    ICommand* on;
    ICommand* dim;
public:
    Invoker(ICommand* on, ICommand* dim) {
        this->on = on;
        this->dim = dim;
    }

    void clickOn() {
        this->on->execute();
    }

    void clickOff() {
        this->on->unexecute();
    }

    void clickDimDown() {
        this->dim->execute();
    }

    void clickDimUp() {
        this->dim->unexecute();
    }
};