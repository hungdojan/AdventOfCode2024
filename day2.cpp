#include <bits/stdc++.h>
#include <sstream> // istringstream
using namespace std;

#define I_2D(row, col, width) ((row) * (width) + (col))
#define PRINT_ARR(arr, n)                                                      \
  do {                                                                         \
    for (int i = 0; i < n; i++) {                                              \
      cout << arr[i] << " ";                                                   \
    }                                                                          \
    cout << "\n";                                                              \
  } while (0)
#define PRINT_VEC_ARR(v, n)                                                    \
  do {                                                                         \
    for (int i = 0; i < n; i++) {                                              \
      cout << i << ": ";                                                       \
      for (auto item : v[i]) {                                                 \
        cout << item << " ";                                                   \
      }                                                                        \
      cout << endl;                                                            \
    }                                                                          \
  } while (0)

#define PRINT_VEC2_ARR(v)                                                      \
  do {                                                                         \
    for (auto &dim1 : v) {                                                     \
      for (auto item : dim1) {                                                 \
        cout << item << " ";                                                   \
      }                                                                        \
      cout << endl;                                                            \
    }                                                                          \
  } while (0)
#define endl '\n';

typedef long long ll;

bool dec_test(ll a, ll b) { return a > b && abs(a - b) <= 3; }
bool inc_test(ll a, ll b) { return a < b && abs(a - b) <= 3; }

int inc_valid(vector<ll> &arr) {
  int i = 0;
  for (; i < arr.size() - 1; i++) {
    if (!inc_test(arr[i], arr[i + 1])) {
      return false;
    }
  }
  return true;
}

bool dec_valid(vector<ll> &arr) {
  int i = 0;
  for (; i < arr.size() - 1; i++) {
    if (!dec_test(arr[i], arr[i + 1])) {
      return false;
    }
  }
  return true;
}

int task1() {
  string line;
  vector<vector<ll>> arr;
  while (getline(cin, line)) {
    istringstream is(line);
    ll t;
    vector<ll> tmp;
    while (is >> t) {
      tmp.push_back(t);
    }
    arr.push_back(tmp);
  }

  ll safe = 0;
  for (auto &lvl : arr) {
    if (inc_valid(lvl) || dec_valid(lvl)) {
      safe++;
    }
  }
  cout << safe << endl;
  return 0;
}

int task2() {
  string line;
  vector<vector<ll>> arr;
  // load input
  while (getline(cin, line)) {
    vector<ll> tmp;
    istringstream is(line);
    ll t;
    while (is >> t) {
      tmp.push_back(t);
    }
    arr.push_back(tmp);
  }

  ll safe = 0;
  for (auto &lvl : arr) {
    for (int i = 0; i < lvl.size(); i++) {
      // try to erase all the each element
      vector<ll> v(lvl);
      v.erase(v.begin() + i);
      if (inc_valid(v) || dec_valid(v)) {
        safe++;
        break;
      }
    }
  }
  cout << safe << endl;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // task1();
  // task2();

  return 0;
}
