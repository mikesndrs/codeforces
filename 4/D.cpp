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

int handle_input(ll& w, ll& h, unordered_map<string, vector<ll>>& w_h_list) {
  int n;
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
      w_h_list[key] = w_h_vec;
    }
  }
  return 0;
}

int filter_w_h(vector<ll>& w_h, unordered_map<string, vector<ll>>& new_w_h) {
  vector<string> key_list;
  vector<ll> n_w_h;
  string key;

  for (const auto& pair : new_w_h) {
    key = pair.first;
    n_w_h = pair.second;
    if (n_w_h[0] <= w_h[0] || n_w_h[1] <= w_h[1]) {
      key_list.push_back(key);
    }
  }
  for (string key : key_list) {
    new_w_h.erase(key);
  }
  return 0;
}
int find_pareto_w_h(
  unordered_map<string, vector<ll>>& w_h_list,
  vector<string>& pareto_w_h,
  string& key,
  vector<ll>& w_h_i,
  bool& should_add,
  vector<string>& should_remove
) {
  vector<ll> p_w_h_i;

  for (const auto& pair : w_h_list) {
    key = pair.first;
    w_h_i = pair.second;
    should_add = true;
    should_remove = {};

    for (const auto& p_key: pareto_w_h) {
      p_w_h_i = w_h_list[p_key];
      if (w_h_i[0] >= p_w_h_i[0] && w_h_i[1] >= p_w_h_i[1]) {
        should_add = false;
        break;
      } else if (w_h_i[0] < p_w_h_i[0] && w_h_i[1] < p_w_h_i[1]) {
        should_remove.push_back(p_key);
      }
    }
    for (const auto& r_key: should_remove) {
      pareto_w_h.erase(remove(pareto_w_h.begin(), pareto_w_h.end(), r_key), pareto_w_h.end());
    }
    if (should_add == true) {
      pareto_w_h.push_back(key);
    }
  }
  return 0;
}

int investigate_order(
  vector<vector<ll>>& chain,
  unordered_map<string, vector<ll>>& w_h_list,
  ll& max_chain_length,
  vector<int>& best_chain_order
) {
  int w_h_size = w_h_list.size();
  int chain_size = chain.size();

  if (w_h_size == 0) {
    if (chain_size > max_chain_length) {
      max_chain_length = chain_size;
      best_chain_order = {};
      for (vector<ll> chain_el : chain) {
        best_chain_order.push_back(chain_el[2]);
      }
    }
  } else if (chain_size + w_h_size > max_chain_length) {
    vector<vector<ll>> new_chain;
    vector<string> pareto_w_h;
    unordered_map<string, vector<ll>> new_w_h;
    vector<ll> w_h_i(3);
    string key;
    bool should_add;
    vector<string> should_remove;

    find_pareto_w_h(w_h_list, pareto_w_h, key, w_h_i, should_add, should_remove);
    for (const auto& p_key : pareto_w_h) {
      w_h_i = w_h_list[p_key];
      new_chain = chain;
      new_chain.push_back(w_h_i);
      new_w_h = w_h_list;
      filter_w_h(w_h_i, new_w_h);
      investigate_order(new_chain, new_w_h, max_chain_length, best_chain_order);
    }
  }
  return 0;
}

int beep(
  vector<vector<ll>>& chain,
  unordered_map<string, vector<ll>>& w_h_list,
  ll& max_chain_length,
  vector<int>& best_chain_order
) {
  return 0;
}

int print_result(ll max_chain_length, vector<int> best_chain_order) {
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
  ll w = 0;
  ll h = 0;
  unordered_map<string, vector<ll>> w_h_list = {};
  handle_input(w, h, w_h_list);

  for (int i = 0; i < 200; i++) {
    ll max_chain_length = 0;
    vector<int> best_chain_order = {};
    vector<vector<ll>> chain = {};
    // investigate_order(chain, w_h_list, max_chain_length, best_chain_order);
    beep(chain, w_h_list, max_chain_length, best_chain_order);
    print_result(max_chain_length, best_chain_order);
  }
  return 0;
}

// 11 3 3
// 1 1
// 4 4
// 5 6
// 6 7
// 8 9
// 6 5
// 7 6
// 8 7
// 9 8
// 10 10
// 3 3
