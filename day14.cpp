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
#define PRINT_MATRIX(m, sep)                                                   \
  do {                                                                         \
    for (auto &row : m) {                                                      \
      for (auto &col : row) {                                                  \
        cout << col << col << sep;                                             \
      }                                                                        \
      cout << endl;                                                            \
    }                                                                          \
  } while (0)
#define endl '\n'
#define R 103
#define C 101

// image cell dimensions
#define H 25
#define W 25

typedef long long ll;

#define Y first
#define X second
typedef pair<int, int> pp;

struct robot_t {
  pp p;
  pp v;
};

static void new_step(robot_t &robot) {
  int tmp_y = robot.p.Y + robot.v.Y;
  robot.p.Y = (tmp_y > 0 ? tmp_y % R : (tmp_y + R) % R);
  int tmp_x = robot.p.X + robot.v.X;
  robot.p.X = (tmp_x > 0 ? tmp_x % C : (tmp_x + C) % C);
}

static void new_second(vector<robot_t> &r, vector<vector<bool>> &m) {
  for (auto &robot : r) {
    new_step(robot);
    if (!m[robot.p.Y][robot.p.X])
      m[robot.p.Y][robot.p.X] = true;
  }
}

static void update_canvas(vector<string> &canvas, vector<robot_t> &r) {
  for (int i = 0; i < H; i++) {
    canvas[i * R] = string(canvas[i].size(), '1');
    for (int j = 0; j < W; j++) {
      vector<vector<bool>> m(R, vector<bool>(C, false));
      new_second(r, m);
      int top = i * R + 1;
      for (int y = 0; y < m.size(); y++) {
        canvas[top + y][j * C] = '1';
        int left = j * C + 1;
        for (int x = 0; x < m[y].size(); x++) {
          canvas[top + y][left + x] = m[y][x] ? '1' : '0';
        }
      }
    }
  }
}

void generate_image(ll sec, vector<robot_t> &r) {
  ofstream new_file("frame" + to_string(sec * H * W) + ".pbm");
  vector<string> v(H * (R + 1), string(W * (C + 1), '0'));
  new_file << "P1" << endl << W * (C + 1) << " " << H * (R + 1) << endl;
  update_canvas(v, r);
  for (auto &s : v) {
    new_file << s;
  }
  new_file.close();
}


int task1() {
  string line;
  vector<vector<ll>> q(2, vector<ll>(2, 0));

  while (getline(cin, line)) {
    ll p1, p2, v1, v2;
    sscanf(line.c_str(), "p=%lld,%lld v=%lld,%lld", &p2, &p1, &v2, &v1);
    ll f1 = (p1 + 100 * v1) % R;
    ll f2 = (p2 + 100 * v2) % C;
    if (f1 < 0) {
      f1 += R;
    }
    if (f2 < 0) {
      f2 += C;
    }
    if (f1 == R / 2 || f2 == C / 2) {
      continue;
    }
    q[f1 / (R / 2 + 1)][f2 / (C / 2 + 1)] += 1;
  }
  ll sum = q[0][0] * q[0][1] * q[1][0] * q[1][1];
  cout << sum << endl;
  return 0;
}

int task2() {
  string line;
  vector<robot_t> r;

  while (getline(cin, line)) {
    ll p1, p2, v1, v2;
    sscanf(line.c_str(), "p=%lld,%lld v=%lld,%lld", &p2, &p1, &v2, &v1);
    r.push_back({{p1, p2}, {v1, v2}});
  }

  const int n = 10000;
  for (int i = 0; i < n / (H * W); i++) {
    generate_image(i, r);
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // task1();
  // task2();

  return 0;
}
