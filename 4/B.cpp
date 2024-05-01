#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int main() {
  ll d;
  ll min_time;
  ll max_time;
  vector<ll> leeway;
  vector<ll> time_per_day;
  ll sum_time;
  ll sum_min = 0;
  ll sum_max = 0;

  string line;

  getline(cin, line);
  istringstream iss (line);
  string s;
  getline(iss, s, ' ');
  d = stoll(s);
  getline(iss, s, ' ');
  sum_time = stoll(s);
  for (ll i=0; i < d; i++) {
    getline(cin, line);
    istringstream iss (line);
    getline(iss, s, ' ');
    min_time = stoll(s);
    sum_min += min_time;
    getline(iss, s, ' ');
    max_time = stoll(s);
    sum_max += max_time;
    leeway.push_back(max_time - min_time);
    time_per_day.push_back(max_time);
  }
  if (sum_min <= sum_time && sum_time <= sum_max) {
    cout << "YES" << endl;
    ll diff = sum_max - sum_time;
    for (ll i=0; i < d; i++) {
      if (leeway[i] < diff) {
        time_per_day[i] -= leeway[i];
        diff -= leeway[i];
      } else {
        time_per_day[i] -= diff;
        break;
      }
    }
    for (ll i=0; i < d; i++) {
      cout << time_per_day[i] << ' ';
    }
  } else {
    cout << "NO" << endl;
  }

  return 0;
}

