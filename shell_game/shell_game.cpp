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

int playGame(int truePosition, vector<pair<int, int>> &swaps, vector<int> &guess) {
  int score = 0;

  for (int i = 0; i < swaps.size(); i++) {
    if (swaps[i].first == truePosition) {
      truePosition = swaps[i].second;
    } else {
      if (swaps[i].second == truePosition) {
        truePosition = swaps[i].first;
      }
    }

    if (guess[i] == truePosition) {
      score++;
    }
  }

  return score;
}

void solve() {
  int N;
  cin >> N;

  vector<pair<int, int>> swaps;
  vector<int> guess;

  for (int i = 0; i < N; i++) {
    int a, b, g;
    cin >> a >> b >> g;
    swaps.push_back({a, b});
    guess.push_back(g);
  }

  int maximumScore = INT_MIN;

  for (int i = 1; i <= 3; i++) {
    maximumScore = max(maximumScore, playGame(i, swaps, guess));
  }

  cout << maximumScore;
}

int main() {

#ifndef ONLINE_JUDGE
  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

