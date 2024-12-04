#include <bits/stdc++.h>
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

#define CHECK(v, x1, x2, x3, x4, y1, y2, y3, y4)                               \
  (v[y1][x1] == 'X' && v[y2][x2] == 'M' && v[y3][x3] == 'A' && v[y4][x4] == 'S')

typedef long long ll;

bool in_zero_subsqr(ll v_size, ll str_size, ll x, ll y) {
  return 0 <= x && x < str_size && 0 <= y && y < v_size;
}

bool in_sqr_cntr(ll v_size, ll str_size, ll x, ll y) {
  return 0 <= x - 1 && x + 1 < str_size && 0 <= y - 1 && y + 1 < v_size;
}

int task1() {
  vector<string> v;
  string s;
  while (cin >> s) {
    v.push_back(s);
  }
  ll count = 0;
  for (long unsigned int i = 0; i < v.size(); i++) {
    for (long unsigned int j = 0; j < v[i].size(); j++) {
      if (v[i][j] != 'X')
        continue;

      // E
      if (in_zero_subsqr(v[i].size(), v.size(), j + 3, i) &&
          CHECK(v, j, j + 1, j + 2, j + 3, i, i, i, i)) {
        count++;
      }
      // W
      if (in_zero_subsqr(v[i].size(), v.size(), j - 3, i) &&
          CHECK(v, j, j - 1, j - 2, j - 3, i, i, i, i)) {
        count++;
      }
      // N
      if (in_zero_subsqr(v[i].size(), v.size(), j, i - 3) &&
          CHECK(v, j, j, j, j, i, i - 1, i - 2, i - 3)) {
        count++;
      }
      // S
      if (in_zero_subsqr(v[i].size(), v.size(), j, i + 3) &&
          CHECK(v, j, j, j, j, i, i + 1, i + 2, i + 3)) {
        count++;
      }
      // NE
      if (in_zero_subsqr(v[i].size(), v.size(), j + 3, i - 3) &&
          CHECK(v, j, j + 1, j + 2, j + 3, i, i - 1, i - 2, i - 3)) {
        count++;
      }
      // SE
      if (in_zero_subsqr(v[i].size(), v.size(), j + 3, i + 3) &&
          CHECK(v, j, j + 1, j + 2, j + 3, i, i + 1, i + 2, i + 3)) {
        count++;
      }
      // NW
      if (in_zero_subsqr(v[i].size(), v.size(), j - 3, i - 3) &&
          CHECK(v, j, j - 1, j - 2, j - 3, i, i - 1, i - 2, i - 3)) {
        count++;
      }
      // SW
      if (in_zero_subsqr(v[i].size(), v.size(), j - 3, i + 3) &&
          CHECK(v, j, j - 1, j - 2, j - 3, i, i + 1, i + 2, i + 3)) {
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}

int task2() {
  vector<string> v;
  string s;
  while (cin >> s) {
    v.push_back(s);
  }
  ll count = 0;
  for (long unsigned int i = 0; i < v.size(); i++) {
    for (long unsigned int j = 0; j < v[i].size(); j++) {
      if (v[i][j] != 'A')
        continue;

      int valid_x = 0;

      if (in_sqr_cntr(v.size(), v[i].size(), j, i)) {
        if ((v[i - 1][j - 1] == 'S' && v[i + 1][j + 1] == 'M') ||
            (v[i - 1][j - 1] == 'M' && v[i + 1][j + 1] == 'S')) {
          valid_x += 1;
        }
        if ((v[i + 1][j - 1] == 'S' && v[i - 1][j + 1] == 'M') ||
            (v[i + 1][j - 1] == 'M' && v[i - 1][j + 1] == 'S')) {
          valid_x += 1;
        }
        if (valid_x == 2) {
          count++;
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // task1();
  // task2();

  return 0;
}
