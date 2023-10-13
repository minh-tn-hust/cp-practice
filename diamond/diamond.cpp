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
  int N, K;
  cin >> N >> K;

  vector<int> diamondSizes;

  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    diamondSizes.push_back(temp);
  }

  int maximumDisplaySizes = INT_MIN;
  for (auto size : diamondSizes) {
    int minimumSize = size;
    int numberDisplay = 0;
    for (auto otherSize : diamondSizes) {
      if (otherSize >= minimumSize && otherSize <= minimumSize + K) {
        numberDisplay++;
      }
    }
    maximumDisplaySizes = max(maximumDisplaySizes, numberDisplay);
  }

  cout << maximumDisplaySizes;
}


int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "diamond";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

