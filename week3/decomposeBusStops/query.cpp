#include <string>
#include <iostream>
#include <vector>

using namespace std;
#include "query.h"

istream& operator >> (istream& is, Query& q) {
    string operation_code;
    is >> operation_code;

    if (operation_code == "NEW_BUS") {

      q.type = QueryType::NewBus;
      cin >> q.bus;
      
      int stop_count=0;
      cin >> stop_count;
      q.stops.resize(stop_count);
      for (string& stop : q.stops) {
        cin >> stop;
      }
      
      
    } else if (operation_code == "BUSES_FOR_STOP") {
      q.type = QueryType::BusesForStop;
      cin >> q.stop;

    } else if (operation_code == "STOPS_FOR_BUS") {

      q.type = QueryType::StopsForBus;
      cin >> q.bus;
      

    } else if (operation_code == "ALL_BUSES") {
      q.type = QueryType::AllBuses;
      }
  return is;
}






