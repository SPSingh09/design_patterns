#include <iostream>
#include "observer.hpp"

using namespace std;

int main() {
  WeatherStation ws;
  PhoneDisplay *phd1 = new PhoneDisplay(&ws, 1);
  PhoneDisplay *phd2 = new PhoneDisplay(&ws, 2);

  ws.Register(phd1);
  ws.Register(phd2);

  /* lets say weather station is measuring temprature and temprature get updated
   * wather station will notify its observers
   * (think in terms of client - server, where weather station is working like a server)
   */
  for (int i = 0; i < 2; i++) {
    ws.SenseTemprature();

    // let the sensing finish properly
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // update all registered observers
    ws.Notify();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }

  // say phoneDisplay 1 deregisters
  ws.DeRegister(phd1);

  for (int i = 0; i < 2; i++) {
    ws.SenseTemprature();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    ws.Notify();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }

  delete phd1;
  delete phd2;

  return 0;
}
