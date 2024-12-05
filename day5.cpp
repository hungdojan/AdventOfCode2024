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
#define N 100

typedef long long ll;

void split_str(string s, string delim, vector<int> &out) {
  size_t pos = 0;
  string token;
  while ((pos = s.find(delim)) != string::npos) {
    token = s.substr(0, pos);
    out.push_back(stoi(token));
    s.erase(0, pos + delim.size());
  }
  out.push_back(stoi(s));
}

int task1() {
  string line;
  unordered_set<int> next[N];
  bool load_graph = true;
  int sum = 0;
  while (getline(cin, line)) {
    if (line.empty()) {
      load_graph = false;
      continue;
    }
    if (load_graph) {
      vector<int> v;
      split_str(line, "|", v);
      next[v[0]].insert(v[1]);
    } else {
      vector<int> v;
      split_str(line, ",", v);
      bool valid = true;
      for (int i = 0; i < v.size() && valid; i++) {
        for (int j = i + 1; j < v.size(); j++) {
          if (next[v[j]].find(v[i]) != next[v[j]].end()) {
            valid = false;
            break;
          }
        }
      }
      if (valid) {
        sum += v[v.size() / 2];
      }
    }
  }
  cout << sum << endl;
  return 0;
}

int task2() {
  string line;
  unordered_set<int> next[N + 1];
  bool load_graph = true;
  int sum = 0;
  while (getline(cin, line)) {
    if (line.empty()) {
      load_graph = false;
      continue;
    }
    if (load_graph) {
      vector<int> v;
      split_str(line, "|", v);
      next[v[0]].insert(v[1]);
    } else {
      vector<int> v;
      split_str(line, ",", v);
      bool mistake = false;
      unordered_set<int> available(v.begin(), v.end());
      vector<int> final;

      // not optimal, but a working solution (computed in 31s)
      // try to find the last page of the manual
      // the optimal solution might be using topological sort
      for (int i = v.size() - 1; i >= 0; i--) {
        if (available.find(v[i]) == available.end())
          continue;
        bool curr_mistake = false;
        int curr;

        queue<int> q;
        q.push(v[i]);
        do {
          curr = q.front();
          q.pop();
          for (auto &val : available) {
            // if found in the list of next pages
            // add the new page into the queue
            if (curr != val && next[curr].find(val) != next[curr].end()) {
              q.push(val);
              mistake = true;
              curr_mistake = true;
            }
          }
        } while (!q.empty() && curr_mistake);
        if (curr != v[i]) {
          i++;
        }
        available.erase(curr);
        final.push_back(curr);
      }
      if (mistake) {
        sum += final[final.size() / 2];
      }
    }
  }
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
