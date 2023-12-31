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

int findMaximumAppearElement(map<int, int> &numOfEle) {
  int maximumAppear = numOfEle.begin()->second;
  int maxAppearEle = numOfEle.begin()->first;

  for (auto [element, numAppear]) {
    if (numAppear > maximumAppear) {
      maximumAppear = numAppear;
      maxAppearEle = element;
    }
  }

  return maxAppearEle;
}

void solve() {
  int n, q;
  cin >> n >> q;

  int a[MAX_N * 2];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  unordered_map<int, pair<int, int>> rangeOfEle;

  map<int, int> numOfEle;

  for (int i = 0; i < n; i++) {
    if (rangeOfEle[a[i]].first == 0) {
      rangeOfEle[a[i]].first = i + 1;
    } else {
      rangeOfEle[a[i]].second = i + 1;
    }

    numOfEle[a[i]]++;
  }

  for (auto &[element, range] : rangeOfEle) {
    if (range.second == 0) {
      range.second = range.first;
    }
  }




  for (auto &[element, range] : rangeOfEle) {
    cout << element 
          << " begin = " << range.first 
          << " end = " << range.second 
          << " num = " << numOfEle[element]
          << "\n";
  }

}


int main() {

#ifdef LOCAL
  string FILE_NAME = "local";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

