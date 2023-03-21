class Singleton {
    static Singleton* instance;
    Singleton() {
        instance = nullptr;
    }
public:
    static Singleton* getInstance() {
        if(instance)
            return instance;
        instance = new Singleton();
        return instance;
    }
    // ... do stuff
};

