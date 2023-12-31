#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>

const double epsilon = 1e-9;

using namespace std;

void solve() {
  int N;
  cin >> N;
  string s;
  cin >> s;

  for (int K = 1; K <= N; K++) {
    unordered_set<string> distincSequence;
    bool isAccepted = true;

    for (int i = 0; i <= N - K; i++) {
      string newSequence = s.substr(i, K);

      if (distincSequence.count(newSequence) == 0)  {
        distincSequence.insert(newSequence);
      } else {
        isAccepted = false;
        break;
      }
    }

    if (isAccepted) {
      cout << K;
      break;
    }
  }
}


int main() {

#ifdef LOCAL
  string FILE_NAME = "local";
#else
  string FILE_NAME = "whereami";
#endif

  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

