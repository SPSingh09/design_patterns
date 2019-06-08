#include "observer.hpp"
#include <chrono>
#include <iostream>
#include <random>
#include <string>

using namespace std;

WeatherStation::WeatherStation() {
  //  cout << "WeatherStation constructor called" << endl;
}
WeatherStation::~WeatherStation() {
}

void WeatherStation::Register(IObserver* obs) {
  cout << "Registering observer " << obs << endl;
  observer.push_back(obs);
}

void WeatherStation::DeRegister(IObserver* obs) {
  for (int i = 0; i < observer.size(); i++) {
    if (obs == observer[i]) {
      cout << "deregistering observer " << obs << endl;
      observer.erase(observer.begin() + i);
    }
  }
}

void WeatherStation::Notify() {
  //  cout << "Notify called" << endl;
  for (int i; i < observer.size(); i++) {
    observer[i]->Update();
  }
}

void WeatherStation::SenseTemprature() {
  cout << "Sensing temprature" << endl;
  std::random_device rd;
  std::mt19937 eng(rd());
  std::uniform_int_distribution<> distr(0, 100);
  this->temprature = distr(eng);
}

int WeatherStation::GetTemprature() {
  //  cout << "GetTemprature called" << endl;
  return this->temprature;
}

void PhoneDisplay::Update() {
  // cout << "update called" << endl;
  int temprature = station->GetTemprature();
  cout << "PhoneDisplay " << id << ": current temprature is " << temprature << "`C" << endl;
}

