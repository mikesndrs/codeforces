#include <iostream>
  
typedef long long ll;
  
int main(){
  ll input;
  std::cin >> input;
  if (input < 4) {
    std::cout << "NO";
  } else if (input % 2 == 0) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}