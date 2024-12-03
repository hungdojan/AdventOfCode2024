#include <bits/stdc++.h>
#include <regex>
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
#define endl '\n';

typedef long long ll;

int task1() {
  regex pattern("(mul\\((\\d{1,3}),\\s*(\\d{1,3})\\))");
  string line;
  smatch match;
  ll sum = 0;
  while (getline(cin, line)) {
    while (regex_search(line, match, pattern)) {
      ll prod = stoi(match[2]) * stoi(match[3]);
      sum += prod;
      line = match.suffix().str();
    }
  }
  cout << sum << endl;
  return 0;
}

int task2() {
  regex pattern("(mul\\((\\d{1,3}),\\s*(\\d{1,3})\\)|don't\\(\\)|do\\(\\))");
  string line;
  smatch match;
  ll sum = 0;
  bool read = true;
  while (getline(cin, line)) {
    while (regex_search(line, match, pattern)) {
      if (match[1].str().rfind("don't()", 0) == 0) {
        read = false;
      } else if (match[1].str().rfind("do()", 0) == 0) {
        read = true;
      }

      if (read && match[1].str().rfind("mul", 0) == 0) {
        sum += stoi(match[2]) * stoi(match[3]);
      }
      line = match.suffix().str();
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
