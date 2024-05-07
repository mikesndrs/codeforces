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

int handle_input(ll& n, vector<vector<ll>>& w_h_list) {
  ll w;
  ll h;
  string s;
  string line;
  vector<ll> w_h_vec;
  string key;

  getline(cin, line);
  istringstream iss (line);
  getline(iss, s, ' ');
  n = stoll(s);
  getline(iss, s, ' ');
  w = stoll(s);
  getline(iss, s, ' ');
  h = stoll(s);
  for (int i = 0; i < n; i++) {
    key = "";
    getline(cin, line);
    istringstream iss (line);
    w_h_vec = {};
    getline(iss, s, ' ');
    w_h_vec.push_back(stoll(s));
    key += s;
    key += ' ';
    getline(iss, s, ' ');
    w_h_vec.push_back(stoll(s));
    key += s;
    w_h_vec.push_back(i + 1);
    if (w_h_vec[0] > w && w_h_vec[1] > h) {
      w_h_list.push_back(w_h_vec);
    }
  }
  n = w_h_list.size();
  return 0;
}

int sort_w_h(vector<vector<ll>>& w_h_list) {
  sort(w_h_list.begin(), w_h_list.end(), [](vector<ll> a, vector<ll> b) {return a[0] > b[0];});
  return 0;
}

int get_dependency_list(
  ll& n,
  vector<vector<ll>>& w_h_list,
  vector<ll>& max_chain_list,
  vector<ll>& parent_list
) {
  for (int i = 0 ; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (
        w_h_list[j][0] < w_h_list[i][0]
        && w_h_list[j][1] < w_h_list[i][1]
        && max_chain_list[j] <= max_chain_list[i]
      ) {
        max_chain_list[j] = max_chain_list[i] + 1;
        parent_list[j] = i;
      }
    }
  }
  return 0;
}

int find_max_index(ll& j, vector<ll>& max_chain_list) {
  j = max_element(max_chain_list.begin(), max_chain_list.end()) - max_chain_list.begin();
  return 0;
}

int fill_best_chain_order(
  ll& j,
  vector<ll>& best_chain_order,
  vector<vector<ll>>& w_h_list,
  vector<ll>& parent_list
) {
  for (int i = 0 ; i < w_h_list.size(); i++) {
    best_chain_order.push_back(w_h_list[j][2]);
    j = parent_list[j];
    if (j == -1) {
      break;
    }
  }
  return 0;
}

int print_result(ll max_chain_length, vector<ll> best_chain_order) {
  if (max_chain_length > 0) {
    cout << max_chain_length << endl;
    for (ll chain_el : best_chain_order) {
      cout << chain_el << ' ';
    }
    cout << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}

int main() {
  ll n, w, h, j, max_chain_length;
  vector<vector<ll>> w_h_list = {};
  vector<ll> best_chain_order = {};
  
  handle_input(n, w_h_list);
  vector<ll> parent_list(n, -1);
  vector<ll> max_chain_list(n, 1);
  sort_w_h(w_h_list);
  get_dependency_list(n, w_h_list, max_chain_list, parent_list);
  find_max_index(j, max_chain_list);
  if (n > 0) {
    max_chain_length = max_chain_list[j];
  } else {
    max_chain_length = 0;
  }
  fill_best_chain_order(j, best_chain_order, w_h_list, parent_list);
  print_result(max_chain_length, best_chain_order);
  return 0;
}
