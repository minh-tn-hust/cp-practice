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

typedef struct CowProgress {
  vector<int> sessionsRanking;

  bool isBetterThan(CowProgress &other) {
    int ans = true;
    for (int i = 0; i < sessionsRanking.size(); i++) {
      if (sessionsRanking[i] > other.sessionsRanking[i]) {
        return false;
      }
    }
    return true;
  }
} CowProgress;

void solve() {
  int K, N;
  cin >> K >> N;

  vector<CowProgress> cows(N);

  int cow;
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < N; j++) {
      cin >> cow;
      cows[cow - 1].sessionsRanking.push_back(j);
    }
  }

  int consistantPair = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (cows[i].isBetterThan(cows[j]) || cows[j].isBetterThan(cows[i])) {
        consistantPair++;
      }
    }
  }

  cout << consistantPair;
}


int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "gymnastics";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

