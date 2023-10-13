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

const int FORWARD = 1;
const int BACKWARD = -1;

int switchDirection(int currentDirection) {
  if (currentDirection == FORWARD) {
    return BACKWARD;
  } else {
    return FORWARD;
  }
}

void solve() {
  int x, y;
  cin >> x >> y;
  int step = 1;
  int direction = 1;

  int totalDistance = 0;
  int currentPosition = x;

  int count= 0;
  while (currentPosition != y) {
    
    int nextPosition = x + direction * step;

    if (y <= x) {
      if (direction == BACKWARD) {
        nextPosition = max(y, nextPosition);
      }
    } else {
      if (direction == FORWARD && nextPosition > y) {
        nextPosition = min(y, nextPosition);
      }
    }

    totalDistance += abs(nextPosition - currentPosition);

    currentPosition = nextPosition;

    step *= 2;
    direction = switchDirection(direction);
  }

  cout << totalDistance;

}

int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "lostcow";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

