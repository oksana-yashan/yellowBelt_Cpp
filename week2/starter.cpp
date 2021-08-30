#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

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

struct BusesForStopResponse {
  vector<string> buses;
};

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

struct StopsForBusResponse {
   string bus;
   vector<pair<string, vector<string>>> stop_buses;
};

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

struct AllBusesResponse {
  map<string, vector<string>> buses_to_stops;
};

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

class BusManager {

private:
  map<string, vector<string>> buses_to_stops;
  map<string, vector<string>> stops_to_buses;

public:
  void AddBus(const string& bus, const vector<string>& stops) {
      
      buses_to_stops[bus] = stops;
      for (const string& stop : stops) {
        stops_to_buses[stop].push_back(bus);
      }

  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
      if (stops_to_buses.count(stop) == 0) {
        return BusesForStopResponse{{}};
      } else {
        return BusesForStopResponse{stops_to_buses.at(stop)};
      }
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
      
      vector<pair<string, vector<string>>> res;
      if (buses_to_stops.count(bus) != 0) {
        for (const string& stop : buses_to_stops.at(bus)) {
          res.push_back(make_pair(stop, stops_to_buses.at(stop)));
        }
      }
      return StopsForBusResponse{bus, res};

  }

  AllBusesResponse GetAllBuses() const {

    return AllBusesResponse{buses_to_stops};
  }
};




int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
