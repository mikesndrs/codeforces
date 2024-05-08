#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <list>
#include <algorithm>

typedef long long ll;
using namespace std;

int main() {
  ll t, n, a, b, res;
  string s, line;
  getline(cin, line);
  t = stoll(line);
  for (ll i = 0; i < t; i++) {
    getline(cin, line);
    istringstream iss (line);
    getline(iss, s, ' ');
    n = stoll(s);
    getline(iss, s, ' ');
    a = stoll(s);
    getline(iss, s, ' ');
    b = stoll(s);

    res = (n / 2) * min(2 * a, b) + (n % 2) * a;
    cout << res << endl;
  }
  return 0;
}

