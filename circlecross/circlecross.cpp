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

typedef struct CowPath {
  int smallGate, largeGate;

  CowPath(int fGate, int sGate) {
    smallGate = min(fGate, sGate);
    largeGate = max(fGate, sGate);
  }

  bool isCross(CowPath &otherPath) {
    if (
      smallGate <= otherPath.smallGate && 
      otherPath.smallGate <= largeGate && 
      largeGate <= otherPath.largeGate
    ) {
      return true;
    }

    if (
      otherPath.smallGate <= smallGate && 
      smallGate <= otherPath.largeGate && 
      otherPath.largeGate <= largeGate
    ) {
      return true;
    }

    return false;
  }
} CowPath;

void solve() {
  string paths;
  cin >> paths;

  vector<CowPath> cowPaths;
  for (char i = 'A'; i <= 'Z'; i++) {
    int smallGate = INT_MAX, largeGate = INT_MIN;
    for (int j = 0; j < paths.size(); j++) {
      if (i == paths[j]) {
        smallGate = min(smallGate, j);
        largeGate = max(largeGate, j);
      }
    }
    cowPaths.push_back({smallGate, largeGate});
  }

  int crossingPair = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = i + 1; j < 26; j++) {
      if (cowPaths[i].isCross(cowPaths[j])) {
        crossingPair++;
      }
    }
  }

  cout << crossingPair;
}


int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "circlecross";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

