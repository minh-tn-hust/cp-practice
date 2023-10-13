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
  int N;
  cin >> N;

  vector<int> usedTimeline(1001, 0);

  int s, t, b;
  for (int i = 0; i < N; i++) {
    cin >> s >> t >> b;
    usedTimeline[s] += b;
    usedTimeline[t + 1] -= b;
  }

  for (int i = 1; i < 1000; i++) {
    usedTimeline[i] += usedTimeline[i - 1];
  }

  int maximumBucket = INT_MIN;

  for (int i = 1; i < usedTimeline.size(); i++) {
    maximumBucket = max(maximumBucket, usedTimeline[i]);
  }
  cout << maximumBucket;
}

int main() {

  string FILE_NAME = "blist";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

