#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <utility>
#include <deque>

using namespace std;



int main() {
  // int start, n;
  // string expr, newExpr;

  // cin>>start>>n;
  // expr = to_string(start);
  // // getline(cin, newExpr);

  // for (int i=0; i<=n; ++i) {
  //     if (i != 0)
  //         expr = "("+expr+") ";
  //     getline(cin,newExpr);
  //     // cout<<"i:"<<i<<" "<<newExpr<<"    "<<expr<<endl;
  //     expr += newExpr;
  // }
  // cout<<expr<<endl;



  int n, number;
  string newExpr;
  deque<string> expr;

  map<char, int8_t> priority = {{'*', 1}, {'/', 1}, {'+', 2}, {'-', 2}};

  cin>>number>>n;
  cin.get();   // get '\n'
  expr.push_back(to_string(number));

  int8_t prevPriority = 1;   //the most significant priority;

  for (int i=0; i<n; ++i) {

      char operation;
      std::cin >> operation;
      int value;
      std::cin >> value;
      newExpr = string(1, operation)+" "+to_string(value);
      // getline(cin, newExpr, '\n');
      if (priority[operation]<prevPriority) {
          expr.push_front("(");
          expr.push_back(") ");
      } else 
          expr.push_back(" ");
      
      expr.push_back(newExpr);
      prevPriority = priority[operation];

  }

  for (auto& s: expr) {
    cout<<s;
  }
  cout<<endl;

  return 0;
}


