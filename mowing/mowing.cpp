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

int maxTime = INT_MAX;

void mowing(
  string &direction, 
  int step, 
  unordered_map<int, unordered_map<int, int>> &mowedCell,
  int &time,
  int &curX,
  int &curY
) {
  int deltaX, deltaY;
  if (direction == "N") {
    deltaY = 1;
    deltaX = 0;

  }

  if (direction == "S") {
    deltaY = -1;
    deltaX = 0;

  }

  if (direction == "W") {
    deltaX = -1;
    deltaY = 0;


  }

  if (direction == "E") {
    deltaX = 1;
    deltaY = 0;
  }


  for (int i = 0; i < step; i++) {
    time += 1;
    curX += deltaX;
    curY += deltaY;
    if (mowedCell[curY][curX] != 0) {
      maxTime = min(time - mowedCell[curY][curX], maxTime);
    }

    mowedCell[curY][curX] = time;
  }
}

void solve() {
  unordered_map<int, unordered_map<int, int>> mowedCell;
  int N;
  cin >> N;

  int x = 0, y = 0, time = 0;

  string direction;
  int step;
  for (int i = 0; i < N; i++) {
    cin >> direction >> step;
    mowing(direction, step, mowedCell, time, x, y);
  }

  cout << (maxTime == INT_MAX ? -1 : maxTime);

}

int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "mowing";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

