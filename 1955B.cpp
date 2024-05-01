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
    istringstream iss (line);
    vector<int> vals;
    int num;
    while (iss >> num) {
      vals.push_back(num);
    }
    int n=vals[0];
    int c=vals[1];
    int d=vals[2];

    getline(cin, line);
    istringstream iss2 (line);
    vector<int> vals2 = {};
    int num2;
    while (iss2 >> num2) {
      vals2.push_back(num2);
    }

    int min_val = *min_element(vals2.begin(), vals2.end());

    vector<int> my_set = {};
    for (int j = 0; j < n; j++) {
      for (int k= 0; k < n; k++) {
        int val = min_val + c * j + d * k;
        my_set.push_back(val);
      }
    }
    sort(vals2.begin(), vals2.end());
    sort(my_set.begin(), my_set.end());
    bool res = true;
    for (int j = 0; j < my_set.size(); j++) {
      if (my_set[j] != vals2[j]) {
        res = false;
        break;
      }
    }
    if (res) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}