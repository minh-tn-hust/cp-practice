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

typedef struct CowInfo {
  char status;
  int point;

  CowInfo(char status, int point) : status(status), point(point) {}

  bool isTheSame(CowInfo &info) {
    return (info.status == status && info.point == point);
  }
} CowInfo;

const char LESS = 'L';
const char GRATER = 'G';

void solve() {
  int N;
  cin >> N;

  vector<CowInfo> cowInfos;

  char status;
  int point;

  for (int i = 0; i < N; i++) {
    cin >> status >> point;
    cowInfos.push_back({status, point});
  }

  int minumumLiars = INT_MAX;
  for (auto trueInfo : cowInfos) {
    int numberOfTrue = 0;

    for (auto info : cowInfos) {
      if (info.isTheSame(trueInfo)) {
        continue;
      }
      
      if (info.status == LESS && info.point >= trueInfo.point) {
        numberOfTrue++;
      }

      if (info.status == GRATER && info.point <= trueInfo.point) {
        numberOfTrue++;
      }
    }

    minumumLiars = min(N - numberOfTrue - 1, minumumLiars);
  }

  cout << minumumLiars;
}

int main() {

#ifndef ONLINE_JUDGE
  // string FILE_NAME = "cowlying";
  // freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  // freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

