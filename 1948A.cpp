#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

typedef long long ll;
using namespace std;

int main() {
  ll input;
  string line;
  int idx = 0;
  getline(cin, line);
  int t = stoi(line);
  for (int i = 0; i < t; i++) {
    getline(cin, line);
    int n = stoi(line);
    if (n % 2 == 0) {
      cout << "YES" << endl;
      int count = n / 2;
      string my_str = "";
      for (int i=0; i < count; i++) {
        my_str += (char) ('A' + i % 2);
        my_str += (char) ('A' + i % 2);
      }
      cout << my_str << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
