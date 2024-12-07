#include <bits/stdc++.h>
#include <sstream>
using namespace std;

#define I_2D(row, col, width) ((row) * (width) + (col))
#define PRll_ARR(arr, n)                                                       \
  do {                                                                         \
    for (ll i = 0; i < n; i++) {                                               \
      cout << arr[i] << " ";                                                   \
    }                                                                          \
    cout << "\n";                                                              \
  } while (0)
#define PRll_VEC_ARR(v, n)                                                     \
  do {                                                                         \
    for (ll i = 0; i < n; i++) {                                               \
      cout << i << ": ";                                                       \
      for (auto item : v[i]) {                                                 \
        cout << item << " ";                                                   \
      }                                                                        \
      cout << endl;                                                            \
    }                                                                          \
  } while (0)
#define endl '\n';

typedef long long ll;

void parse_line(string s, vector<string> &out, ll &solution) {
  size_t pos = s.find(":");
  string token = s.substr(0, pos);
  solution = stoll(token);
  s.erase(0, pos + 2);

  istringstream is(s);
  string num;
  while (is >> num) {
    out.push_back(num);
  }
}

bool backtrack(size_t index, vector<string> &v, ll total, ll sol) {
  if (total == sol && index == v.size())
    return true;

  if (total > sol || index >= v.size())
    return false;

  if (backtrack(index + 1, v, total * stoll(v[index]), sol))
    return true;
  return backtrack(index + 1, v, total + stoll(v[index]), sol);
}

bool backtrack2(size_t index, vector<string> &v, ll total, ll sol) {
  if (total == sol && index == v.size())
    return true;

  if (total > sol || index >= v.size())
    return false;

  ll concat_num = total * pow(10, v[index].size()) + stoll(v[index]);

  if (backtrack2(index + 1, v, concat_num, sol)) {
    return true;
  }
  if (backtrack2(index + 1, v, total * stoll(v[index]), sol)) {
    return true;
  }
  if (backtrack2(index + 1, v, total + stoll(v[index]), sol)) {
    return true;
  }
  return false;
}

ll task1() {
  string line;
  ll sum = 0;
  while (getline(cin, line)) {
    ll sol;
    vector<string> v;
    parse_line(line, v, sol);
    if (backtrack(0, v, 0, sol)) {
      sum += sol;
    }
  }
  cout << sum << endl;
  return 0;
}

ll task2() {
  string line;
  unsigned long long sum = 0;
  while (getline(cin, line)) {
    ll sol;
    vector<string> v;
    parse_line(line, v, sol);
    if (backtrack2(0, v, 0, sol)) {
      sum += sol;
    }
  }
  cout << sum << endl;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // task1();
  // task2();

  return 0;
}
