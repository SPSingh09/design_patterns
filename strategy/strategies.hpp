#include <iostream>

using namespace std;

// Interface classes
class IQuackStrategy {
	public:
		virtual void Quack() = 0;
};

class IFlyStrategy {
 public:
  virtual void Fly() = 0;
};
/*
 *
 *
 * Keep adding as may Behaviours (Interfaces) as needed base on the requirements*/

// Concrete class implementation
class NoQuack : public IQuackStrategy {
 public:
  void Quack() { cout << "Can not quack" << endl; }
};

class SimpleQuack : public IQuackStrategy {
 public:
  void Quack() { cout << "Simple: quack quack..." << endl; }
};

class QuackLoud : public IQuackStrategy {
 public:
  void Quack() { cout << "Loud: quack quack..." << endl; }
};

class NoFly : public IFlyStrategy {
 public:
  void Fly() { cout << "Can not fly" << endl; }
};

class SimpleFly : public IFlyStrategy {
 public:
  void Fly() { cout << "Simple: fly fly..." << endl; }
};

class FlyHigh : public IFlyStrategy {
 public:
  void Fly() { cout << "High: fly fly..." << endl; }
};

/*
 *
 *
 * Keep adding as many concrete behaviours as needed base on the requirements */

// base class
class Duck {
 public:
  Duck() {}
  ~Duck() {
    delete this->qs;
    delete this->fs;
  }
  void InitializeDuck(IQuackStrategy *qs, IFlyStrategy *fs) {
    this->qs = qs;
    this->fs = fs;
  }
  void Quack() { this->qs->Quack(); }
  void Fly() { this->fs->Fly(); }

 private:
  IQuackStrategy *qs;
  IFlyStrategy *fs;
};
