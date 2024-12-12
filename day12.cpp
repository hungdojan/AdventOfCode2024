#include <bits/stdc++.h>
using namespace std;

#define I_2D(row, col, width) ((row) * (width) + (col))
#define PRINT_ARR(arr, n)                                                      \
  do {                                                                         \
    for (int i = 0; i < n; i++) {                                              \
      cout << bitset<4>(arr[i] >> 1) << " ";                                   \
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

void traverse(int i, int j, char c, vector<string> &_map,
              vector<vector<bool>> &visited, ll &area, ll &perimeter) {
  if (visited[i][j]) {
    return;
  }
  visited[i][j] = true;

  area = 1;
  perimeter = 0;

  ll tmp_area, tmp_perimeter;
  if (!visited[i + 1][j] && _map[i + 1][j] == c) {
    traverse(i + 1, j, c, _map, visited, tmp_area, tmp_perimeter);
    area += tmp_area;
    perimeter += tmp_perimeter;
  } else {
    perimeter += _map[i + 1][j] != c;
  }
  if (!visited[i - 1][j] && _map[i - 1][j] == c) {
    traverse(i - 1, j, c, _map, visited, tmp_area, tmp_perimeter);
    area += tmp_area;
    perimeter += tmp_perimeter;
  } else {
    perimeter += _map[i - 1][j] != c;
  }
  if (!visited[i][j + 1] && _map[i][j + 1] == c) {
    traverse(i, j + 1, c, _map, visited, tmp_area, tmp_perimeter);
    area += tmp_area;
    perimeter += tmp_perimeter;

  } else {
    perimeter += _map[i][j + 1] != c;
  }
  if (!visited[i][j - 1] && _map[i][j - 1] == c) {
    traverse(i, j - 1, c, _map, visited, tmp_area, tmp_perimeter);
    area += tmp_area;
    perimeter += tmp_perimeter;
  } else {
    perimeter += _map[i][j - 1] != c;
  }
}

enum config_t { VISITED = 1, CALCULATED = 2, UP = 4, DOWN = 8, LEFT = 16, RIGHT = 32};

typedef pair<int, int> pp;
void traverse(int i, int j, char c, vector<string> &_map,
              vector<vector<short>> &config, ll &area, pp &_min, pp &_max) {
  if (config[i][j] & VISITED) {
    return;
  }
  config[i][j] |= VISITED;
  area = 1;
  _min = {min(_min.first, i), min(_min.second, j)};
  _max = {max(_max.first, i), max(_max.second, j)};

  ll tmp_area;
  if (!config[i + 1][j] && _map[i + 1][j] == c) {
    traverse(i + 1, j, c, _map, config, tmp_area, _min, _max);
    area += tmp_area;
  } else {
    config[i][j] |= _map[i + 1][j] != c ? DOWN : 0;
  }
  if (!config[i - 1][j] && _map[i - 1][j] == c) {
    traverse(i - 1, j, c, _map, config, tmp_area, _min, _max);
    area += tmp_area;
  } else {
    config[i][j] |= _map[i - 1][j] != c ? UP : 0;
  }
  if (!config[i][j + 1] && _map[i][j + 1] == c) {
    traverse(i, j + 1, c, _map, config, tmp_area, _min, _max);
    area += tmp_area;
  } else {
    config[i][j] |= _map[i][j + 1] != c ? RIGHT : 0;
  }
  if (!config[i][j - 1] && _map[i][j - 1] == c) {
    traverse(i, j - 1, c, _map, config, tmp_area, _min, _max);
    area += tmp_area;
  } else {
    config[i][j] |= _map[i][j - 1] != c ? LEFT : 0;
  }
}

int task1() {
  string line;
  int row_size = 0;
  vector<string> v;
  while (getline(cin, line)) {
    if (row_size == 0) {
      row_size = line.size() + 2;
      v.push_back(string(row_size, '.'));
    }
    line = '.' + line;
    line.push_back('.');
    v.push_back(line);
  }
  v.push_back(string(row_size, '.'));
  ll sum = 0;
  vector<vector<bool>> visited(v.size(), vector<bool>(v[0].size(), false));
  for (int i = 1; i < v.size() - 1; i++) {
    for (int j = 1; j < v[0].size() - 1; j++) {
      if (visited[i][j])
        continue;
      ll area, perimeter;
      traverse(i, j, v[i][j], v, visited, area, perimeter);
      sum += area * perimeter;
    }
  }
  cout << sum << endl;
  return 0;
}

int task2() {
  string line;
  int row_size = 0;
  vector<string> v;
  while (getline(cin, line)) {
    if (row_size == 0) {
      row_size = line.size() + 2;
      v.push_back(string(row_size, '.'));
    }
    line = '.' + line;
    line.push_back('.');
    v.push_back(line);
  }
  v.push_back(string(row_size, '.'));

  ll sum = 0;
  vector<vector<short>> config(v.size(), vector<short>(v[0].size(), 0));
  for (int i = 1; i < v.size() - 1; i++) {
    for (int j = 1; j < v[0].size() - 1; j++) {
      if (config[i][j] & VISITED)
        continue;
      ll area, sides = 0;
      pp _min = {i, j}, _max = {i, j};
      traverse(i, j, v[i][j], v, config, area, _min, _max);
      for (int ii = _min.first; ii <= _max.first; ii++) {
        for (int jj = _min.second; jj <= _max.second; jj++) {
          if (v[ii][jj] != v[i][j] || (config[ii][jj] & CALCULATED) || !(config[ii][jj] & VISITED)) {
            continue;
          }
          bitset<4> b((config[ii][jj] >> 2));

          if (v[ii - 1][jj] == v[i][j]) {
            b &= ~(config[ii - 1][jj] >> 2);
          }
          if (v[ii][jj - 1] == v[i][j]) {
            b &= ~(config[ii][jj - 1] >> 2);
          }
          sides += b.count();
          config[ii][jj] |= CALCULATED;
        }
      }
      sum += area * sides;
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
