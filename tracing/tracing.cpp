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

typedef struct CowntactHistory {
  int time, x, y;
  CowntactHistory(){
    time = 0;
    x = 0;
    y = 0;
  }
  CowntactHistory(int time, int x, int y) : time(time), x(x), y(y) {}
} CowntactHistory;

bool timeCompare(const CowntactHistory &a, const CowntactHistory &b) {
  return a.time < b.time;
}

bool canMakeCurrentStatus(vector<CowntactHistory> &history, int K, int N, int patientZero,string &status) {
  vector<bool> isInjected(N + 1, false);
  vector<int> spreadTime(N + 1, K);
  isInjected[patientZero] = true;
  
  for (auto contact : history) {
    int x = contact.x;
    int y = contact.y;
    if (isInjected[y] && isInjected[x]) {
      spreadTime[y] = max(0, spreadTime[y] - 1);
      spreadTime[x] = max(0, spreadTime[x] - 1);
      continue;
    }

    if (isInjected[y] && !isInjected[x]) {
      isInjected[x] = (spreadTime[y] > 0);
      spreadTime[y] = max(0, spreadTime[y] - 1);
      continue;
    }

    if (isInjected[x] && !isInjected[y]) {
      isInjected[y] = (spreadTime[x] > 0);
      spreadTime[x] = max(0, spreadTime[x] - 1);
      continue;
    }
  }

  for (int i = 1; i <= N; i++) {
    if (isInjected[i] == true && status[i - 1] == '1') {
      continue;
    }

    if (isInjected[i] == false && status[i - 1] == '0') {
      continue;
    }

    return false;
  }

  return true;
}

void solve() {
  int N, T;
  cin >> N >> T;

  string currentStatus;
  cin >> currentStatus;

  vector<CowntactHistory> history;

  int t, x, y;

  for (int i = 0; i < T; i++) {
    cin >> t >> x >> y;
    history.push_back({t, x, y});
  }

  sort(history.begin(), history.end(), timeCompare);
  
  int smallestK = INT_MAX;
  int largestK = INT_MIN;
  int numberValidPatientZero = 0;

  for (int patientZero = 1; patientZero <= N; patientZero++) {
    bool canBePatientZero = false;
    for (int K = 0; K <= T; K++) {
      if (canMakeCurrentStatus(history, K, N, patientZero, currentStatus)) {
        smallestK = min(smallestK, K);
        largestK = max(largestK, K);
        canBePatientZero = true;
      }
    }

    if (canBePatientZero) {
      numberValidPatientZero++;
    }
  }

  cout << numberValidPatientZero << " ";

  if (smallestK == INT_MAX) {
    cout << 0 << " ";
  } else {
    cout << smallestK << " ";
  }

  if (largestK >= T) {
    cout << "Infinity";
  } else {
    if (largestK == INT_MIN) {
      cout << 0;
    } else {
      cout << largestK;
    }
  }
}


int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "tracing";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

