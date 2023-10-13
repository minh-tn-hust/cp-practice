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

int getDistanceFromTo(int fromRoom, int toRoom, int totalRoom) {
  if (fromRoom <= toRoom) {
    return toRoom - fromRoom;
  }

  return toRoom + totalRoom - fromRoom;
}

void solve() {
  int N;
  cin >> N;
  int temp;
  vector<int> cowsInRoom;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    cowsInRoom.push_back(temp);
  }


  int minimumDistance = INT_MAX;
  for (int openRoom = 0; openRoom < N; openRoom++) {
    int distance = 0;
    for (int i = 0; i < N; i++) {
      distance += cowsInRoom[i] * getDistanceFromTo(openRoom, i, N);
    }

    minimumDistance = min(minimumDistance, distance);
  }

  cout << minimumDistance;
}

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "cbarn";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

