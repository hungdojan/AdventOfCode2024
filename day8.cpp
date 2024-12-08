#include <bits/stdc++.h>
using namespace std;

#define I_2D(row, col, width) ((row) * (width) + (col))
#define PRINT_ARR(arr, n)                                                      \
  do {                                                                         \
    for (int i = 0; i < n; i++) {                                              \
      cout << arr[i] << endl;                                                  \
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
typedef complex<ll> pp;
#define ROW real()
#define COL imag()

inline bool in_map_square(ll row_max, ll col_max, pp a) {
  return 0 <= a.ROW && a.ROW < row_max && 0 <= a.COL && a.COL < col_max;
}

int in_range(ll row_max, ll col_max, pp a, pp b, vector<string> &arr) {
  pp v = a - b;
  pp flip_v = b - a;
  int valid = 0;
  if (in_map_square(row_max, col_max, a + v) &&
      in_map_square(row_max, col_max, b + v)) {
    auto new_pos = a + v != b ? (a + v) : (b + v);
    // update map -> add antenas
    if (arr[new_pos.ROW][new_pos.COL] != '#') {
      arr[new_pos.ROW][new_pos.COL] = '#';
      valid++;
    }
  }
  if (in_map_square(row_max, col_max, a + flip_v) &&
      in_map_square(row_max, col_max, b + flip_v)) {
    auto new_pos = a + flip_v != b ? (a + flip_v) : (b + flip_v);
    // update map -> add antenas
    if (arr[new_pos.ROW][new_pos.COL] != '#') {
      arr[new_pos.ROW][new_pos.COL] = '#';
      valid++;
    }
  }
  return valid;
}

int in_range2(ll row_max, ll col_max, pp a, pp b, vector<string> &arr) {
  pp v = a - b;
  pp flip_v = b - a;
  int valid = 0;
  if (in_map_square(row_max, col_max, a + v) &&
      in_map_square(row_max, col_max, b + v)) {
    auto new_pos = a + v != b ? (a + v) : (b + v);
    while (in_map_square(row_max, col_max, new_pos)) {
      // update map -> add antenas
      if (arr[new_pos.ROW][new_pos.COL] != '#') {
        arr[new_pos.ROW][new_pos.COL] = '#';
        valid++;
      }
      new_pos += v;
    }
  }
  if (in_map_square(row_max, col_max, a + flip_v) &&
      in_map_square(row_max, col_max, b + flip_v)) {
    auto new_pos = a + flip_v != b ? (a + flip_v) : (b + flip_v);
    while (in_map_square(row_max, col_max, new_pos)) {
      // update map -> add antenas
      if (arr[new_pos.ROW][new_pos.COL] != '#') {
        arr[new_pos.ROW][new_pos.COL] = '#';
        valid++;
      }
      new_pos += flip_v;
    }
  }
  if (arr[a.ROW][a.COL] != '#') {
    valid++;
    arr[a.ROW][a.COL] = '#';
  }
  if (arr[b.ROW][b.COL] != '#') {
    valid++;
    arr[b.ROW][b.COL] = '#';
  }
  return valid;
}

int task1() {
  vector<string> map;
  unordered_map<char, vector<pp>> antenas;
  string line;
  for (int i = 0; getline(cin, line); i++) {
    map.push_back(line);
    for (int j = 0; j < line.size(); j++) {
      if (line[j] != '.') {
        if (antenas.find(line[j]) == antenas.end()) {
          antenas[line[j]] = vector<pp>();
        }
        antenas[line[j]].push_back({i, j});
      }
    }
  }

  ll antinodes = 0;
  for (auto p : antenas) {
    vector<pp> ant = p.second;
    for (int i = 0; i < ant.size(); i++) {
      for (int j = i + 1; j < ant.size(); j++) {
        antinodes += in_range(map.size(), map[0].size(), ant[i], ant[j], map);
      }
    }
  }
  cout << antinodes << endl;
  return 0;
}

int task2() {
  vector<string> map;
  unordered_map<char, vector<pp>> antenas;
  string line;
  for (int i = 0; getline(cin, line); i++) {
    map.push_back(line);
    for (int j = 0; j < line.size(); j++) {
      if (line[j] != '.') {
        if (antenas.find(line[j]) == antenas.end()) {
          antenas[line[j]] = vector<pp>();
        }
        antenas[line[j]].push_back({i, j});
      }
    }
  }

  ll antinodes = 0;
  for (auto p : antenas) {
    vector<pp> ant = p.second;
    for (int i = 0; i < ant.size(); i++) {
      for (int j = i + 1; j < ant.size(); j++) {
        antinodes += in_range2(map.size(), map[0].size(), ant[i], ant[j], map);
      }
    }
  }
  cout << antinodes << endl;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // task1();
  // task2();

  return 0;
}
