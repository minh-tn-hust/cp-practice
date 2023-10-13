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

const int INFINITY = 1e9 + 9;

typedef struct CowInCell {
  string direction;
  int x, y;
  int numberEatingCell = INFINITY;
  int isStop = false;

  CowInCell(string direction, int x, int y) : direction(direction), x(x), y(y) {
    isStop = false;
  };

  pair<bool, int> isBlockedByAStopCow(CowInCell cow) {
    int curX = x, curY = y;

    if (direction == "N") {
      swap(cow.x, cow.y);
      swap(curX, curY);
    }

    if (curX < cow.x){
      if(cow.y <= curY && curY <= cow.y + cow.numberEatingCell - 1) {
        if (curY == cow.y + cow.numberEatingCell - 1 && curX + cow.numberEatingCell - 1 == cow.x) {
          return {false, INFINITY};
        } else {
          return {true, abs(cow.x - curX)};
        }
      }
    } 
    return {false, INFINITY};
  }

  pair<bool, int> isBlockedBy(CowInCell cow) {
    if (cow.direction == direction) {
      return {false, INFINITY};
    }

    if (cow.isStop) {
      return isBlockedByAStopCow(cow);
    }

    int curX = x, curY = y;

    if (direction == "N") {
      swap(curX, curY);
      swap(cow.x, cow.y);
    }


    if (cow.x >= curX && cow.y <= curY) {

      int eStep = abs(cow.x - curX);
      int nStep = abs(cow.y - curY);

      if (eStep <= nStep) {
        return {false, INFINITY};
      } else {
        return {true, eStep};
      }
    }
    return {false, INFINITY};
  }
} CowInCell;

int findStoppedCow(vector<CowInCell> &cows) {
  int numCows = cows.size();

  int minimumEatingsCell = INFINITY;

  for (int i = 0; i < numCows; i++) {
    if (cows[i].isStop) continue;
    for (int j = 0; j < numCows; j++) {
      if (i == j) continue;

      const auto &[isBlocked, eatingCells]  = cows[i].isBlockedBy(cows[j]);

      if (isBlocked) {
        cows[i].numberEatingCell = min(cows[i].numberEatingCell, eatingCells);
        minimumEatingsCell = min(minimumEatingsCell, eatingCells);
      }
    }
  }

  for (auto &cow : cows) {
    if (!cow.isStop) {
      if (cow.numberEatingCell == minimumEatingsCell) {
        cow.isStop = true;
      } else {
        cow.numberEatingCell = INFINITY;
      }
    }
  }
}

void solve() {
  int N;

  vector<CowInCell> cows;

  cin >> N;
  string direct;
  int x, y;

  for (int i = 0; i < N; i++) {
    cin >> direct >> x >> y;
    cows.push_back({direct, x, y});
  }

  for (int i = 0; i < N; i++) {
    int index = findStoppedCow(cows);
  }

  for (auto cow : cows) {
    if (cow.numberEatingCell == INFINITY) {
      cout << "Infinity\n";
    } else {
      cout << cow.numberEatingCell << "\n";
    }
  }

}

int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "stuck_in_a_rut";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

