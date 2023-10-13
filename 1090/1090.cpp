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
  int n, x;
  cin >> n >> x;
  vector<int> childrenWeight;

  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    childrenWeight.push_back(temp);
  }

  sort(childrenWeight.begin(), childrenWeight.end());

  int lighterChildIdx = 0;
  int heavierChildIdx = n - 1;
  int numberOfGondolas = 0;

  while (lighterChildIdx <= heavierChildIdx) {
    if (lighterChildIdx == heavierChildIdx) {
      numberOfGondolas += 1;
      break;
    }
    if (childrenWeight[lighterChildIdx] + childrenWeight[heavierChildIdx] > x) {
      numberOfGondolas += 1;
      heavierChildIdx--;
      continue;
    }

    numberOfGondolas += 1;
    lighterChildIdx += 1;
    heavierChildIdx -= 1;
  }

  cout << numberOfGondolas;
}

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

