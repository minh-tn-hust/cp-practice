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
  long long n;
  cin >> n;

  vector<long long> arr;

  long long temp;
  for (long long i = 0; i < n; i++) {
    cin >> temp;
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end());

  long long median = arr[arr.size() / 2];

  long long minimumSum = 0;

  for (long long i = 0; i < n; i++) {
    minimumSum += abs(median - arr[i]);
  }

  cout << minimumSum;
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

