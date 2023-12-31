#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>

const int MAX_N = 1e5 + 5;
const double epsilon = 1e-9;

using namespace std;

void tipTheCows(vector<string> &cowState, int i, int j) {
  for (int y = 0; y <= i; y++) {
    for (int x = 0; x <= j; x++) {
      cowState[y][x] = (cowState[y][x] == '0' ? '1' : '0');
    }
  }

}

void solve() {
  int n;
  cin >> n;

  vector<string> cowState(n);

  for (int i = 0; i < n; i++) {
    cin >> cowState[i];
  }

  int numberOfTip = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (cowState[i][j] == '1') {
        numberOfTip += 1;
        tipTheCows(cowState, i, j);
      }
    }
  }

  cout << numberOfTip;
}


int main() {

#ifdef LOCAL
  string FILE_NAME = "local";
#else
  string FILE_NAME = "cowtip";
#endif
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

