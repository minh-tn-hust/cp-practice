#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>


using namespace std;

void solve() {
  int X, Y, M;
  cin >> X >> Y >> M;

  int xLimit = M / X;
  int yLimit = M / Y;

  int maximumAmount = INT_MIN;
  for (int nx = 0; nx <= xLimit; nx++) {
    for (int ny = 0; ny <= yLimit; ny++) {
      int milkAmount = nx * X + ny * Y;
      if (milkAmount <= M) {
        maximumAmount = max(maximumAmount, milkAmount);
      }
    }
  }

  cout << maximumAmount;
}

int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "pails";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

