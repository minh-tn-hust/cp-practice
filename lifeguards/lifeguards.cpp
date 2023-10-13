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

typedef struct Guard {
  int begin, end;

  Guard(int begin, int end) : begin(begin), end(end) {}
} Guard;

const int MAX_TIME = 1000;

int numberOfSafetyHours(vector<Guard> &guards, int firedIndex) {
  vector<int> prefixSum(MAX_TIME + 1, 0);

  for (int i = 0; i < guards.size(); i++) {
    if (i == firedIndex) continue;

    Guard &guard = guards[i];
    prefixSum[guard.begin] += 1;
    prefixSum[guard.end] -= 1;
  }

  int coverHours = 0;
  if (prefixSum[0] != 0) {
    coverHours++;
  }

  for (int i = 1; i <= MAX_TIME; i++) {
    prefixSum[i] += prefixSum[i - 1];
    if (prefixSum[i] != 0) {
      coverHours++;
    }
  }

  return coverHours;
}

void solve() {
  int N;
  cin >> N;

  vector<Guard> guards;

  int begin, end;
  for (int i = 0; i < N; i++) {
    cin >> begin >> end;
    guards.push_back({begin, end});
  }

  int maximumCoverHour = INT_MIN;
  for (int firedIndex = 0; firedIndex < N; firedIndex++) {
    maximumCoverHour = max(maximumCoverHour, numberOfSafetyHours(guards, firedIndex));
  }

  cout << maximumCoverHour;
}


int main() {
  string FILE_NAME = "lifeguards";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

