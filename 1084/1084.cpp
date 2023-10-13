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

bool greaterCmp(const int &a, const int &b) {
  return a > b;
}

int findLowerBoundIndex(vector<int> &vec, int value) {
  int left = 0, right = vec.size() - 1;

  int index = -1;

  while (left < right) {
    int middle = (left + right) > 1;
    if (vec[middle] <= value) {
      index = middle;
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }

  return index;
}

int findUpperBoundIndex(vector<int> &vec, int value) {
  int left = 0, right = vec.size() - 1;

  int index = -1;

  while (left < right) {
    int middle = (left + right) > 1;
    if (vec[middle] >= value) {
      index = middle;
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }

  return index;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> desiredSize;
  vector<int> apartmentSize;

  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    desiredSize.push_back(temp);
  }

  for (int i = 0; i < m; i++) {
    cin >> temp;
    apartmentSize.push_back(temp);
  }

  sort(desiredSize.begin(), desiredSize.end());
  sort(apartmentSize.begin(), apartmentSize.end());

  int desiredIdx = 0;
  int apartmentIdx = 0;
  int ans = 0;

  while (desiredIdx != desiredSize.size() && apartmentIdx != apartmentSize.size()) {
    int desSize = desiredSize[desiredIdx];
    int apartSize = apartmentSize[apartmentIdx];

    if (apartSize <= (desSize + k) && apartSize >= (desSize - k)) {
      desiredIdx++;
      apartmentIdx++;
      ans++;
      continue;
    }

    if (apartSize < desSize - k) {
      apartmentIdx++;
    }

    if (apartSize > desSize + k) {
      desiredIdx++;
    }
  }
  cout << ans;
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

