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
#define N 100000

typedef long long ll;

int task1() {
  vector<ll> l, r;

  string line;
  ll a, b;
  while (getline(cin, line)) {
    sscanf(line.c_str(), "%lld %lld", &a, &b);
    l.push_back(a);
    r.push_back(b);
  }

  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  ll diff = 0;
  for (int i = 0; i < l.size(); i++) {
    diff += abs(l[i] - r[i]);
  }

  cout << diff << endl;
  return 0;
}

int task2() {
  ll l[N], r[N];
  memset(l, 0, sizeof(l));
  memset(r, 0, sizeof(r));

  string line;
  ll a, b;
  while (getline(cin, line)) {
    sscanf(line.c_str(), "%lld %lld", &a, &b);
    l[a]++;
    r[b]++;
  }

  ll sum = 0;
  for (int i = 0; i < N; i++) {
    if (l[i]) {
      sum += l[i] * i * r[i];
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
