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
  
  vector<pair<int, int>> arr;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    arr.push_back({temp, i});
  }

  sort(arr.begin(), arr.end());

  int lower = 0, higher = n - 1;
  int hasAnwser = false;

  while (lower < higher) {
    if (arr[lower].first + arr[higher].first == x){
      cout << arr[lower].second + 1 << " " << arr[higher].second + 1 << "\n";
      hasAnwser = true;
    }

    if (arr[lower].first + arr[higher].first > x) {
      higher--;
    } else {
      lower++;
    }
  }

  if (!hasAnwser) {
    cout << "IMPOSSIBLE";
  }
}


int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "cowlying";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

