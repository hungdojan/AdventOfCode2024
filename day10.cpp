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
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<int> pp;

int traverse(vector<vector<int>> &dp, vector<vector<int>> &v, int search,
             int row, int col) {
  if (dp[row][col]) {
    return dp[row][col];
  }
  if (v[row][col] == 9) {
    dp[row][col] = 1;
    return 1;
  }

  int nof_paths = 0;
  if (v[row - 1][col] == search) {
    nof_paths += traverse(dp, v, search + 1, row - 1, col);
  }
  if (v[row + 1][col] == search) {
    nof_paths += traverse(dp, v, search + 1, row + 1, col);
  }
  if (v[row][col - 1] == search) {
    nof_paths += traverse(dp, v, search + 1, row, col - 1);
  }
  if (v[row][col + 1] == search) {
    nof_paths += traverse(dp, v, search + 1, row, col + 1);
  }
  dp[row][col] = nof_paths;
  return nof_paths;
}

int traverse(vector<vector<int>> &dp, vector<vector<int>> &v, int search,
             int row, int col, int id) {
  if (dp[row][col] == id) {
    return 0;
  }
  if (v[row][col] == 9) {
    dp[row][col] = id;
    return 1;
  }

  int nof_paths = 0;
  if (v[row - 1][col] == search) {
    nof_paths += traverse(dp, v, search + 1, row - 1, col, id);
  }
  if (v[row + 1][col] == search) {
    nof_paths += traverse(dp, v, search + 1, row + 1, col, id);
  }
  if (v[row][col - 1] == search) {
    nof_paths += traverse(dp, v, search + 1, row, col - 1, id);
  }
  if (v[row][col + 1] == search) {
    nof_paths += traverse(dp, v, search + 1, row, col + 1, id);
  }
  dp[row][col] = id;
  return nof_paths;
}

int task1() {
  vector<vector<int>> v;
  vector<pp> starts;
  string line;
  int row = 0;
  int row_size;
  while (getline(cin, line)) {
    vector<int> c_line;
    if (row == 0) {
      row_size = line.size() + 2;
      v.push_back(vector<int>(row_size, -1));
    }
    c_line.push_back(-1);
    for (int i = 0; i < line.size(); i++) {
      c_line.push_back(line[i] - '0');
      if (line[i] == '0') {
        starts.push_back({row + 1, i + 1});
      }
    }
    c_line.push_back(-1);
    v.push_back(c_line);
    row++;
  }
  v.push_back(vector<int>(row_size, -1));

  int sum = 0;
  vector<vector<int>> dp(v.size(), vector<int>(row_size, -1));
  for (int i = 0; i < starts.size(); i++) {
    int trails = traverse(dp, v, 1, starts[i].X, starts[i].Y, i);
    sum += trails;
  }
  cout << sum << endl;
  return 0;
}

int task2() {
  vector<vector<int>> v;
  vector<pp> starts;
  string line;
  int row = 0;
  int row_size;
  while (getline(cin, line)) {
    vector<int> c_line;
    if (row == 0) {
      row_size = line.size() + 2;
      v.push_back(vector<int>(row_size, -1));
    }
    c_line.push_back(-1);
    for (int i = 0; i < line.size(); i++) {
      c_line.push_back(line[i] - '0');
      if (line[i] == '0') {
        starts.push_back({row + 1, i + 1});
      }
    }
    c_line.push_back(-1);
    v.push_back(c_line);
    row++;
  }
  v.push_back(vector<int>(row_size, -1));

  int sum = 0;
  vector<vector<int>> dp(v.size(), vector<int>(row_size, 0));
  for (int i = 0; i < starts.size(); i++) {
    int trails = traverse(dp, v, 1, starts[i].X, starts[i].Y);
    sum += trails;
  }
  cout << sum << endl;
  return 0; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // task1();
  // task2();

  return 0;
}
