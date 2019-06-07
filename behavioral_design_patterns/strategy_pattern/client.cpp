#include <iostream>
#include "strategies.hpp"

using namespace std;

// Client want to create a new Duck => RubberDuck
class RubberDuck : public Duck {
 public:
  RubberDuck() {
    IQuackStrategy *qs = new NoQuack;
    IFlyStrategy *fs = new NoFly;
    InitializeDuck(qs, fs);
  }
  ~RubberDuck() {}
  void Execute() {
    cout << "Executing rubber duck strategies..." << endl;
    Quack();
    Fly();
  }
};

// Client want to create a new Duck => SimpleDuck
class SimpleDuck : public Duck {
 public:
  SimpleDuck() {
    IQuackStrategy *qs = new SimpleQuack;
    IFlyStrategy *fs = new SimpleFly;
    InitializeDuck(qs, fs);
  }
  ~SimpleDuck() {}
  void Execute() {
    cout << "Executing simple duck strategies..." << endl;
    Quack();
    Fly();
  }
};

// Client want to create a new Duck => SimpleDuck
class SmartDuck : public Duck {
 public:
  SmartDuck() {
    IQuackStrategy *qs = new QuackLoud;
    IFlyStrategy *fs = new FlyHigh;
    InitializeDuck(qs, fs);
  }
  ~SmartDuck() {}
  void Execute() {
    cout << "Executing smart duck strategies..." << endl;
    Quack();
    Fly();
  }
};
/*
 *
 *
 * Client can keep adding as may ducks as needed with plug and play strategies*/

// Driver function
int main() {
  // rubber duck simulation
  RubberDuck rd;
  rd.Execute();

  // simple duck simulation
  SimpleDuck sd;
  cout << "\nLets quack simple duck..." << endl;
  sd.Quack();

  // smart duck simulation
  SmartDuck smd;
  cout << "\nLets fly smart duck..." << endl;
  smd.Fly();
  return 0;
}
