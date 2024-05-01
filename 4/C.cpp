#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

typedef long long ll;
using namespace std;

int main() {
  ll n;
  string line;
  map<string, ll> my_set;

  getline(cin, line);
  n = stoll(line);
  for (ll i = 0; i < n; i++) {
    getline(cin, line);
    
    if ( my_set.find(line) != my_set.end() ) {
      cout << line << my_set[line] << endl;
      my_set[line] += 1;
    } else {
      cout << "OK" << endl;
      my_set[line] = 1;
    }
  }

  return 0;
}


