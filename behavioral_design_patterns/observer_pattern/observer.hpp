#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class IObserver {
 public:
  virtual void Update() = 0;
};

class IObservable {
 public:
  virtual void Register(IObserver* obs) = 0;
  virtual void DeRegister(IObserver* obs) = 0;
  virtual void Notify() = 0;
};

class WeatherStation : public IObservable {
 public:
  WeatherStation();
  ~WeatherStation();
  void Register(IObserver* obs);
  void DeRegister(IObserver* obs);
  void Notify();

  int GetTemprature();
  void SenseTemprature();

 private:
  std::thread measure_thread;
  float temprature;
  std::vector<IObserver*> observer;
};

class PhoneDisplay : public IObserver {
 public:
  PhoneDisplay(WeatherStation* station, int id) {
    this->station = station;
    this->id = id;
  }
  ~PhoneDisplay() {}
  void Update();

 private:
  WeatherStation* station;
  int id;
};
