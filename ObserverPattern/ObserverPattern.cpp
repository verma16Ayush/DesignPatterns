#include <bits/stdc++.h>
using namespace std;

class IObservable{
public:
    set<IObserver*> observers;
    virtual void addObserver(IObserver* observer) = 0;
    virtual void removeObserver(IObserver* observer) = 0;
    virtual void notifyObservers() = 0;
};

class IObserver{
public:
    IObservable* observable;
    virtual void update() = 0;
};

class WeatherStation : public IObservable {
    int temperature, pressure, humidity;
public:
    WeatherStation(){
        this->temperature = 0;
        this->pressure = 0;
        this->humidity = 0;
    }
    
    void addObserver(IObserver* observer) {
        this->observers.insert(observer);
    }

    void removeObserver(IObserver* observer) {
        this->observers.erase(observer);
    }

    void notifyObservers() {
        set<IObserver*>::iterator itr;
        for(itr = this->observers.begin(); itr != this->observers.end(); itr++) {
            (*itr)->update();
        }
    }

    int getTemperature() {
        return this->temperature;
    }

    int getPressure() {
        return this->pressure;
    }

    int getHumidity() {
        return this->humidity;
    }

    int setTemperature(int temperature) {
        this->temperature = temperature;
        notifyObservers();
    }

    int setPressure(int pressure) {
        this->pressure = pressure;
        notifyObservers();
    }

    int setHumidity(int humidity) {
        this->humidity = humidity;
        notifyObservers();
    }
};

class PhoneDisplay: public IObserver {
    WeatherStation* station;
    int currentTemperature, currentPressure, currentHumidity;
public:
    PhoneDisplay(WeatherStation* station){
        this->station = station;
    }

    void update() {
        this->currentHumidity = this->station->getHumidity();
        this->currentTemperature = this->station->getTemperature();
        this->currentPressure = this->station->getPressure();

        cout << "Temperature: " << this->currentTemperature;
        cout << "Pressure: " << this->currentPressure;
        cout << "Humidity: " << this->currentHumidity;
    }
};

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}