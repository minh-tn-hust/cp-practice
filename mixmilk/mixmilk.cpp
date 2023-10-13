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
  vector<int> capacities;
  vector<int> milks;

  int cap, milk;
  for (int i = 0; i < 3; i++) {
    cin >> cap >> milk;
    capacities.push_back(cap);
    milks.push_back(milk);
  }

  for (int i = 0; i < 100; i++) {
    int from = i % 3;
    int to = (i + 1) % 3;

    if (milks[from] + milks[to] < capacities[to]) {
      milks[to] = milks[from] + milks[to];
      milks[from] = 0;
    } else {
      milks[from] = milks[from] - (capacities[to] - milks[to]);
      milks[to] = capacities[to];
    }
  }

  cout << milks[0] << "\n" << milks[1] << "\n" << milks[2] << "\n";
}

int main() {

#ifndef ONLINE_JUDGE
  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

