// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int32_t i = 22;
  uint32_t j = 23;
  vector<int> v(10);
  
  std::cout << i+j<<" "<< sizeof(i+j)<<" "<<(i+j)+v;
}
