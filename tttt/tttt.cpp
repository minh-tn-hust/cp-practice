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

set<string> singleWin;
set<string> coopWin;

bool checkCol(vector<string> &board, int col, int maximumTeam) {
  set<char> distincCharacter;

  for (int i = 0; i < 3; i++) {
    distincCharacter.insert(board[i][col]);
  }

  if (distincCharacter.size() == maximumTeam) {
    string winningTeam = "";
    for (auto team : distincCharacter) {
      winningTeam += team;
    }
    if (maximumTeam == 1) {
      singleWin.insert(winningTeam);
    } else {
      coopWin.insert(winningTeam);
    }
    return true;
  }

  return false;
}

bool checkRow(vector<string> &board, int row, int maximumTeam) {
  set<char> distincCharacter;

  for (int i = 0; i < 3; i++) {
    distincCharacter.insert(board[row][i]);
  }

  if (distincCharacter.size() == maximumTeam) {
    string winningTeam = "";
    for (auto team : distincCharacter) {
      winningTeam += team;
    }
    if (maximumTeam == 1) {
      singleWin.insert(winningTeam);
    } else {
      coopWin.insert(winningTeam);
    }

    return true;
  }

  return false;

}

int TOP_LEFT_TO_BOTTOM_RIGHT = 1;
int TOP_RIGHT_TO_BOTTOM_LEFT = 2;
bool checkDiagonal(vector<string> &board, int maximumTeam, int type) {
  set<char> distincCharacter;

  if (type == TOP_LEFT_TO_BOTTOM_RIGHT) {
    for (int i = 0; i < 3; i++) {
      distincCharacter.insert(board[i][i]);
    }
  } else {
    for (int i = 0; i < 3; i++) {
      distincCharacter.insert(board[i][2 - i]);
    }
  }

  if (distincCharacter.size() == maximumTeam) {
    string winningTeam = "";
    for (auto team : distincCharacter) {
      winningTeam += team;
    }
    if (maximumTeam == 1) {
      singleWin.insert(winningTeam);
    } else {
      coopWin.insert(winningTeam);
    }
    return true;
  }

  return false;

}

void solve() {
  vector<string> board;

  string s;
  for (int i = 0; i < 3; i++) {
    cin >> s;
    board.push_back(s);
  }

  for (int i = 0; i < 3; i++) {
    checkCol(board, i, 1);
    checkCol(board, i, 2);
    checkRow(board, i, 1);
    checkRow(board, i, 2);
  }
  checkDiagonal(board, 1, TOP_LEFT_TO_BOTTOM_RIGHT);
  checkDiagonal(board, 2, TOP_LEFT_TO_BOTTOM_RIGHT);
  checkDiagonal(board, 1, TOP_RIGHT_TO_BOTTOM_LEFT);
  checkDiagonal(board, 2, TOP_RIGHT_TO_BOTTOM_LEFT);

  cout << singleWin.size() << "\n" << coopWin.size();
}

int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "tttt";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

