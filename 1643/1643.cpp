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

// DP Approach
void solve() {
  long long n;
  cin >> n;

  vector<long long> arr(n);

  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<long long> dp(n);

  dp[0] = arr[0];

  long long maximumSubArray = dp[0];

  for (long long i = 1; i < n; i++) {
    dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    maximumSubArray = max(maximumSubArray, dp[i]);
  }

  cout << maximumSubArray;

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

