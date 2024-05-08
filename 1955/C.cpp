#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <deque>

typedef long long ll;
using namespace std;

int handle_input(ll& n, ll& k, string& s, string& line, deque<ll>& durability) {
  durability = {};
  getline(cin, line);
  istringstream iss (line);
  getline(iss, s, ' ');
  n = stoll(s);
  getline(iss, s, ' ');
  k = stoll(s);
  getline(cin, line);
  istringstream iss2 (line);
  for (ll i = 0; i < n; i++) {
    getline(iss2, s, ' ');
    durability.push_back(stoll(s));
  }
  return 0;
}

int main() {
  ll t, n, k, res;
  deque<ll> durability;
  string s, line;
  getline(cin, line);
  t = stoll(line);
  for (ll i = 0; i < t; i++) {
    handle_input(n, k, s, line, durability);
    res = 0;
    ll kr = k;
    for (ll i = 0; i < k; i++) {
      if (kr == 0) {
        break;
      } else if (durability.size() == 0) {
        break;
      } else if (durability.size() == 1) {
        if (kr >= durability.front()) {
          durability.pop_front();
          res += 1;
        }
        break;
      }
      ll d_min = min(durability.front(), durability.back());
      if (kr >= 2 * d_min) {
        durability.front() -= d_min;
        durability.back() -= d_min;
        if (durability.front() == 0) {
          durability.pop_front();
          res += 1;
        };
        if (durability.back() == 0) {
          durability.pop_back();
          res += 1;
        };
        kr -= 2 * d_min;
      } else if (kr == (2 * d_min) - 1) {
        durability.front() -= d_min;
        if (durability.front() == 0) {
          durability.pop_front();
          res += 1;
        };
        kr -= (2 * d_min) - 1;
        break;
      } else {
        break;
      }
    }
    cout << res << endl;
  }
  return 0;
}

