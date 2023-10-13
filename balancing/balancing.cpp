#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>
#include <math.h>

using namespace std;

bool canBuildWith(int sleepHour, vector<int> &a) {
  int sum = 0;
  for (int i = 0; i < a.size(); i++) {
    sum += a[i];

    if (sum == sleepHour) {
      sum = 0;
      continue;
    }

    if (sum > sleepHour) {
      return false;
    }
  }

  if (sum == 0) {
    return true;
  }

  return false;
}

void solve() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a;

    int temp;
    int sum = 0;
    int maximum = INT_MIN;
    for (int i = 0; i < N; i++) {
      cin >> temp;
      sum += temp;
      a.push_back(temp);
      maximum = max(maximum, temp);
    }

    vector<int> elsieCanBuild;
    for (int i = 1; i <= sqrt(sum); i++) {
      if (sum % i == 0) {
        if (i >= maximum) {
          elsieCanBuild.push_back(i);
        }

        if (sum / i >= maximum) {
          elsieCanBuild.push_back(sum / i);
        }
      }
    }

    int minimumOperator = INT_MAX;
    for (auto sleepHour : elsieCanBuild) {
      if (canBuildWith(sleepHour, a)) {
        minimumOperator = min(N - (sum / sleepHour), minimumOperator);
      }
    }

    if (minimumOperator == INT_MAX) {
      cout << "0" << "\n";
    } else {
      cout << minimumOperator << "\n";
    }
  }
}

int main() {

#ifndef ONLINE_JUDGE
  // string FILE_NAME = "local";
  // freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  // freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

