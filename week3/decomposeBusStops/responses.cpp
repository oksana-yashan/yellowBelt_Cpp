#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "responses.h"

using namespace std;


ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if (r.buses.empty()) {
        cout << "No stop" << endl;
      } else {
        for (const string& bus : r.buses) {
          cout << bus << " ";
        }
        cout << endl;
      }
  return os;
}



ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  if (r.stop_buses.empty()) {
        cout << "No bus" << endl;
      } 
  else {
        for (const auto& item : r.stop_buses) {
          cout << "Stop " << item.first << ": ";
          if (item.second.size() == 1) {
            cout << "no interchange";
          } else {
            for (const string& other_bus : item.second) {
              if (r.bus != other_bus) {
                cout << other_bus << " ";
              }
            }
          }
          cout << endl;
        }
      }
  return os;
}



ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if (r.buses_to_stops.empty()) {
        cout << "No buses" << endl;
      } else {
        for (const auto& bus_item : r.buses_to_stops) {
          cout << "Bus " << bus_item.first << ": ";
          for (const string& stop : bus_item.second) {
            cout << stop << " ";
          }
          cout << endl;
        }
      }
  return os;
}
