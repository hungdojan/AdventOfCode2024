#include <bits/stdc++.h>
using namespace std;

#define I_2D(row, col, width) ((row) * (width) + (col))
#define PRINT_ARR(arr, n)                                                      \
  do {                                                                         \
    for (int i = 0; i < n; i++) {                                              \
      cout << setprecision(30) << arr[i] << " ";                               \
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

#define PRINT_MAT(m, sep)                                                      \
  do {                                                                         \
    for (auto &row : m) {                                                      \
      for (auto &col : row) {                                                  \
        cout << col << sep;                                                    \
      }                                                                        \
      cout << endl;                                                            \
    }                                                                          \
  } while (0)

#define endl '\n';
#define X real()
#define Y imag()
#define EXT 10000000000000

typedef long long ll;
typedef complex<ll> pp;
typedef vector<vector<double>> matrix_t;

void matrix_mult(matrix_t &m1, vector<double> &m2, vector<double> &out) {
  out = vector<double>(out.size(), 0);
  for (int i = 0; i < m1.size(); i++) {
    for (int j = 0; j < m1[i].size(); j++) {
      out[i] += m1[i][j] * m2[j];
    }
  }
}

void matrix_inverse(matrix_t &m1, matrix_t &out) {
  ll det = m1[0][0] * m1[1][1] - m1[0][1] * m1[1][0];
  out[0][0] = 1.0 * m1[1][1] / det;
  out[0][1] = -1.0 * m1[0][1] / det;
  out[1][0] = -1.0 * m1[1][0] / det;
  out[1][1] = 1.0 * m1[0][0] / det;
}

ll get_sum(matrix_t &B, vector<double> &P, vector<double> &out) {
  matrix_t tmp_m(B);
  matrix_inverse(B, tmp_m);
  matrix_mult(tmp_m, P, out);
  // checking if the double is int
  if (abs(out[0] - round(out[0])) < 0.001 &&
      abs(out[1] - round(out[1])) < 0.001) {
    return 3 * out[0] + out[1];
  }
  return 0;
}

int task1() {
  string line;
  matrix_t B(2, vector<double>(2, 0));
  matrix_t tmp_m(B);
  vector<double> P(2, 0), out(2, 0);
  ll sum = 0;
  while (getline(cin, line)) {
    ll x, y;
    char c;
    if (line.empty()) {
      sum += get_sum(B, P, out);
    }
    if (line[0] == 'B') {
      sscanf(line.c_str(), "Button %c: X+%lld, Y+%lld", &c, &x, &y);
      if (c == 'A') {
        B[0][0] = x;
        B[1][0] = y;
      } else {
        B[0][1] = x;
        B[1][1] = y;
      }
    } else if (line[0] == 'P') {
      sscanf(line.c_str(), "Prize: X=%lld, Y=%lld", &x, &y);
      P[0] = x;
      P[1] = y;
    }
  }
  sum += get_sum(B, P, out);
  cout << sum << endl;
  return 0;
}

int task2() {
  string line;
  matrix_t B(2, vector<double>(2, 0));
  matrix_t tmp_m(B);
  vector<double> P(2, 0), out(2, 0);
  ll sum = 0;
  while (getline(cin, line)) {
    ll x, y;
    char c;
    if (line.empty()) {
      matrix_inverse(B, tmp_m);
      matrix_mult(tmp_m, P, out);

      // checking if the double is int
      if (abs(out[0] - round(out[0])) < 0.001 &&
          abs(out[1] - round(out[1])) < 0.001) {
        sum += 3 * out[0] + out[1];
      }
    }
    if (line[0] == 'B') {
      sscanf(line.c_str(), "Button %c: X+%lld, Y+%lld", &c, &x, &y);
      if (c == 'A') {
        B[0][0] = x;
        B[1][0] = y;
      } else {
        B[0][1] = x;
        B[1][1] = y;
      }
    } else if (line[0] == 'P') {
      sscanf(line.c_str(), "Prize: X=%lld, Y=%lld", &x, &y);
      P[0] = x + 10000000000000;
      P[1] = y + 10000000000000;
    }
  }
  sum += get_sum(B, P, out);
  cout << sum << endl;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // task1();
  task2();

  return 0;
}
